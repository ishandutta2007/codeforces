#include <bits/stdc++.h>
using namespace std;

string s;

class ST {
private:
	int size;
	int st[1<<19][10][10];
	int l[1<<19], r[1<<19];
	int lazy[1<<19];
	void push(int w, int L, int R) {
		if (lazy[w]==-1) return;
		l[w] = r[w] = lazy[w];
		for (int i=0;i<10;i++) for (int j=0;j<10;j++) {
			st[w][i][j] = 0;
		}
		st[w][l[w]][r[w]] = R-L;
		if (L!=R) lazy[w*2] = lazy[w], lazy[w*2+1] = lazy[w];
		lazy[w] = -1;
	}
	void pull(int w, int L, int R) {
		push(w*2,L,(L+R)/2); push(w*2+1,(L+R)/2+1,R);
		for (int i=0;i<10;i++) for (int j=0;j<10;j++) {
			st[w][i][j] = st[w*2][i][j]+st[w*2+1][i][j];
		}
		st[w][r[w*2]][l[w*2+1]]+=1;
		l[w] = l[w*2]; r[w] = r[w*2+1];
	}
	void build(int w, int L, int R) {
		if (L==R) l[w] = r[w] = s[L]-'a';
		else {
			build(w*2,L,(L+R)/2), build(w*2+1,(L+R)/2+1,R);
			pull(w,L,R);
		}
	}
	void updateI(int w, int L, int R, int a, int b, int c) {
		push(w,L,R);
		if (b<L || R<a) return;
		if (a<=L && R<=b) lazy[w] = c;
		else {
			updateI(w*2,L,(L+R)/2,a,b,c), updateI(w*2+1,(L+R)/2+1,R,a,b,c);
			pull(w,L,R);
		}
	}
public:
	ST(int s=0) {
		size = s;
		memset(st,0,sizeof st);
		fill(lazy,lazy+(1<<19),-1);
		if (s) build(1,0,size-1);
	}
	void update(int a, int b, int c) { updateI(1,0,size-1,a,b,c); }
	int query(int k, string p) {
		push(1,0,size-1);
		int ans = 1;
		for (int i=0;i<k;i++) for (int j=i;j<k;j++) {
			ans+=st[1][p[j]-'a'][p[i]-'a'];
		}
		return ans;
	}
};

int n,m,k;
char buff[200013];
ST tree;

int main() {
	scanf("%d%d%d",&n,&m,&k);
	scanf(" %s",&buff);
	s = string(buff);
	tree = ST(n);
	for (int i=0;i<m;i++) {
		int type;
		scanf("%d",&type);
		if (type==1) {
			int l,r;
			char c;
			scanf("%d%d %c",&l,&r,&c);
			tree.update(l-1,r-1,c-'a');
		} else {
			scanf(" %s",&buff);
			printf("%d\n",tree.query(k,string(buff)));
		}
	}

	return 0;
}