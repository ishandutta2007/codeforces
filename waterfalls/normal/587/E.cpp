// why does CF use \r\n
#include <bits/stdc++.h>
using namespace std;

vector<int> add(vector<int> basis, int x) {for (int i: basis) if (i&(-i)&x) x^=i;for (int& i: basis) if (x&(-x)&i) i^=x;if (x) basis.push_back(x);return basis;}
vector<int> merge(vector<int> a, vector<int> b) {for (int i: b) a = add(a,i);return a;}

int A[200013];
class ST {
private:
	vector<int> basis[800013];
	int size,key[800013],lazy[800013];
	void push(int w, int L, int R) {
		key[w]^=lazy[w];
		if (L!=R) {
			lazy[w*2]^=lazy[w];
			lazy[w*2+1]^=lazy[w];
		}
		lazy[w] = 0;
	}
	void pull(int w) {
		basis[w] = merge(basis[w*2],basis[w*2+1]);
		key[w] = key[w*2+1];
		basis[w] = add(basis[w],key[w*2]^key[w]);
	}
	void build(int w, int L, int R) {
		key[w] = A[R];
		lazy[w] = 0;
		if (L==R) return;
		else {
			build(w*2,L,(L+R)/2);
			build(w*2+1,(L+R)/2+1,R);
			pull(w);
		}
	}
	void updateI(int w, int L, int R, int a, int b, int k) {
		push(w,L,R);
		if (b<L || R<a) return;
		if (a<=L && R<=b) lazy[w] = k, push(w,L,R);
		else {
			updateI(w*2,L,(L+R)/2,a,b,k);
			updateI(w*2+1,(L+R)/2+1,R,a,b,k);
			pull(w);
		}
	}
	vector<int> queryI(int w, int L, int R, int a, int b) {
		push(w,L,R);
		if (b<L || R<a) return vector<int>();
		if (a<=L && R<=b) return add(basis[w],key[w]);
		return merge(queryI(w*2,L,(L+R)/2,a,b),queryI(w*2+1,(L+R)/2+1,R,a,b));
	}
public:
	ST(int s=0) { if (size = s) build(1,0,size-1); }
	void update(int l, int r, int k) { updateI(1,0,size-1,l,r,k); }
	int query(int l, int r) { return 1<<queryI(1,0,size-1,l,r).size(); }
};

int n,q;
ST tree;

int main() {
	scanf("%d%d",&n,&q);
	for (int i=0;i<n;i++) scanf("%d",&A[i]);
	tree = ST(n);
	for (int i=0;i<q;i++) {
		int type,l,r,k;
		scanf("%d",&type);
		if (type==1) scanf("%d%d%d",&l,&r,&k), tree.update(l-1,r-1,k);
		else scanf("%d%d",&l,&r), printf("%d\n",tree.query(l-1,r-1));
	}

	return 0;
}