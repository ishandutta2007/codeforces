#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int len;
char S[1000013];
int suffix[1000013];
pair<pair<int,int>,int> cur[1000013];
pair<pair<int,int>,int> cur2[1000013];
int last[1000013];
int where[1000013];

int cnt[1000013];

void csort(bool which) {
	for (int i=0;i<max(len,200);i++) cnt[i] = 0;
	for (int i=0;i<len;i++) cnt[which ? cur[i].first.second : cur[i].first.first]+=1;
	int tot = 0;
	for (int i=0;i<max(len,200);i++) {
		int old = cnt[i];
		cnt[i] = tot;
		tot+=old;
	}
	for (int i=0;i<len;i++) {
		cur2[cnt[which ? cur[i].first.second : cur[i].first.first]] = cur[i];
		cnt[which ? cur[i].first.second : cur[i].first.first]+=1;
	}
	for (int i=0;i<len;i++) cur[i] = cur2[i];
}

int val[1000013];

class ST {
private:
	int size;
	int st[4000013];
	int lazy[4000013];
	int left(int w) { return w<<1; }
	int right(int w) { return (w<<1)+1; }
	void build(int w, int L, int R) {
		if (L==R) st[w] = val[L];
		else {
			build(left(w),L,(L+R)/2);
			build(right(w),(L+R)/2+1,R);
			st[w] = max(st[left(w)],st[right(w)]);
		}
	}
	void process(int w, int L, int R) {
		st[w]+=lazy[w];
		if (L!=R) {
			lazy[left(w)]+=lazy[w];
			lazy[right(w)]+=lazy[w];
		}
		lazy[w] = 0;
	}
	void updateI(int w, int L, int R, int a, int b, int val) {
		if (lazy[w]) process(w,L,R);
		if (a>R || b<L) return;
		if (a<=L && R<=b) {
			lazy[w] = val;
			process(w,L,R);
			return;
		}
		updateI(left(w),L,(L+R)/2,a,b,val);
		updateI(right(w),(L+R)/2+1,R,a,b,val);
		st[w] = max(st[left(w)],st[right(w)]);
	}
	int queryI(int w, int L, int R, int a, int b) {
		if (lazy[w]) process(w,L,R);
		if (a>R || b<L) return -2147483647;
		if (a<=L && R<=b) return st[w];
		int one = queryI(left(w),L,(L+R)/2,a,b);
		int two = queryI(right(w),(L+R)/2+1,R,a,b);
		return max(one,two);
	}
public:
	ST(int s=0) {
		size = s;
		if (s>0) build(1,0,size-1);
		fill(lazy,lazy+4*size,0);
	}
	void update(int a, int b, int val) { updateI(1,0,size-1,a,b,val); }
	int query(int a, int b) { return queryI(1,0,size-1,a,b); }
};

ST ma;
int one[1000013];
int two[1000013];
int ok[1000013];

int main() {
    scanf(" %s",&S);
    len = strlen(S);
    val[0] = (S[0]==')' ? 1 : -1);
    for (int i=1;i<len;i++) val[i] = val[i-1]+(S[i]==')' ? 1 : -1);
    ma = ST(len);
    for (int i=0;i<len;i++) {
        one[i] = max(ma.query(0,len-1),0);
        ma.update(0,len-1,S[i]==')' ? -1 : 1);
        ma.update(i,i,ma.query((i-1+len)%len,(i-1+len)%len)+(S[i]==')' ? 1 : -1));
    }
    val[len-1] = (S[len-1]=='(' ? 1 : -1);
    for (int i=len-2;i>=0;i--) val[i] = val[i+1]+(S[i]=='(' ? 1 : -1);
    ma = ST(len);
    for (int i=len-1;i>=0;i--) {
        two[(i+1)%len] = max(ma.query(0,len-1),0);
        ma.update(0,len-1,S[i]=='(' ? -1 : 1);
        ma.update(i,i,ma.query((i+1)%len,(i+1)%len)+(S[i]=='(' ? 1 : -1));
    }
    int sum = 0;
    for (int i=0;i<len;i++) {
        if (S[i]=='(') sum+=1;
        else sum-=1;
    }
    for (int i=0;i<len;i++) if (one[i]+two[i]==abs(sum)) ok[i] = 1;
    for (int i=0;i<len;i++) last[i] = S[i];
    for (int i=0;i<len;i++) cur[i].second = i;
    for (int i=0;i<len;i++) where[i] = i;
    for (int k=1;k<len;k*=2) {
        for (int i=0;i<len;i++) {
            cur[i].first.first = last[i];
            cur[i].first.second = last[where[(cur[i].second+k)%len]];
        }
        csort(true);
        csort(false);
        for (int i=0;i<len;i++) where[cur[i].second] = i;
        last[0] = 0;
        for (int i=1;i<len;i++) {
            if (cur[i].first.first==cur[i-1].first.first &&
                cur[i].first.second==cur[i-1].first.second) last[i] = last[i-1];
            else last[i] = last[i-1]+1;
        }
    }
    for (int i=0;i<len;i++) suffix[i] = cur[i].second;
    if (sum<0) for (int i=0;i<-sum;i++) printf("(");
    int which = 0;
    for (int i=0;i<len;i++) {
        if (ok[suffix[i]]) {
            which = i;
            break;
        }
    }
    for (int i=0;i<len;i++) printf("%c",S[(suffix[which]+i)%len]);
    if (sum>0) for (int i=0;i<sum;i++) printf(")");
    printf("\n");

    return 0;
}