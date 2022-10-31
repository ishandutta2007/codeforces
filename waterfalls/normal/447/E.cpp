#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int fib[400000];
int a[300000];
int MOD = 1000000009;

pair<int,int> findPair(int L,int from,pair<int,int> val,pair<int,int> original=make_pair(0,0)) {
    if (L==from) return val;
    original.first = (original.first+(long long) val.first*fib[L-1-from]+(long long) val.second*fib[L-from])%MOD;
    original.second = (original.second+(long long) val.first*fib[L-from]+(long long) val.second*fib[L+1-from])%MOD;
    return original;
}

class ST {
private:
	int size;
	int st[1200013];
	pair<int,int> lazy[1200013];
	int left(int w) { return w<<1; }
	int right(int w) { return (w<<1)+1; }
	void build(int w, int L, int R) {
        if (L==R) st[w] = a[L];
        else {
            build(left(w),L,(L+R)/2);
            build(right(w),(L+R)/2+1,R);
            st[w] = (st[left(w)]+st[right(w)])%MOD;
        }
	}
	void process(int w, int L, int R) {
	    st[w] = (st[w]+(long long) lazy[w].first*fib[R-L+1]+(long long) lazy[w].second*(fib[R-L+2]-1))%MOD;
		if (L!=R) {
            lazy[left(w)].first = (lazy[left(w)].first+lazy[w].first)%MOD;
            lazy[left(w)].second = (lazy[left(w)].second+lazy[w].second)%MOD;
            lazy[right(w)] = findPair((L+R)/2+1,L,lazy[w],lazy[right(w)]);
 		}
		lazy[w].first = 0;
		lazy[w].second = 0;
	}
	void updateI(int w, int L, int R, int a, int b, pair<int,int> val) {
		if (lazy[w].first || lazy[w].second) process(w,L,R);
		if (a>R || b<L) return;
		if (a<=L && R<=b) {
			lazy[w] = findPair(L,a,val);
			process(w,L,R);
			return;
		}
		updateI(left(w),L,(L+R)/2,a,b,val);
		updateI(right(w),(L+R)/2+1,R,a,b,val);
		st[w] = (st[left(w)]+st[right(w)])%MOD;
	}
	int queryI(int w, int L, int R, int a, int b) {
		if (lazy[w].first || lazy[w].second) process(w,L,R);
		if (a>R || b<L) return 0;
		if (a<=L && R<=b) return st[w];
		int one = queryI(left(w),L,(L+R)/2,a,b);
		int two = queryI(right(w),(L+R)/2+1,R,a,b);
		return (one+two)%MOD;
	}
public:
	ST(int s=0) {
		size = s;
		if (s!=0) build(1,0,size-1);
		for (int i=0;i<4*s;i++) {
            lazy[i].first = 0;
            lazy[i].second = 0;
		}
	}
	void update(int a, int b, pair<int,int> val) { updateI(1,0,size-1,a,b,val); }
	int query(int a, int b) { return queryI(1,0,size-1,a,b); }
};

int n,m;
ST tree;

int main() {
    fib[0] = 0;
    fib[1] = 1;
    for (int i=2;i<400000;i++) fib[i] = (fib[i-1]+fib[i-2])%MOD;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    tree = ST(n);
    for (int i=0;i<m;i++) {
        int t,l,r;
        scanf("%d%d%d",&t,&l,&r);
        l-=1; r-=1;
        if (t==1) tree.update(l,r,make_pair(1,1));
        else printf("%d\n",tree.query(l,r));
    }

    return 0;
}