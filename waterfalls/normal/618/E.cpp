#include <bits/stdc++.h>
using namespace std;

typedef double ld;
typedef complex<double> cd;
const ld PI = 2*acos(0.0);

class ST {
private:
	int size;
	cd st[1<<20];
	cd ladd[1<<20], lmult[1<<20];
	void build(int w, int L, int R) {
		ladd[w] = 0;
		lmult[w] = 1;
		if (L==R) st[w] = L-1;
		else build(w*2,L,(L+R)/2), build(w*2+1,(L+R)/2+1,R);
	}
	void push(int w, int L, int R) {
		if (L==R) st[w] = lmult[w]*st[w]+ladd[w];
		else {
			ladd[w*2] = lmult[w]*ladd[w*2]+ladd[w];
			lmult[w*2] = lmult[w]*lmult[w*2];
			ladd[w*2+1] = lmult[w]*ladd[w*2+1]+ladd[w];
			lmult[w*2+1] = lmult[w]*lmult[w*2+1];
		}
		ladd[w] = 0;
		lmult[w] = 1;
	}
	void updateAI(int w, int L, int R, int a, int b, cd v) {
		push(w,L,R);
		if (b<L || R<a) return;
		if (a<=L && R<=b) {
			ladd[w] = v;
			push(w,L,R);
		} else updateAI(w*2,L,(L+R)/2,a,b,v), updateAI(w*2+1,(L+R)/2+1,R,a,b,v);
	}
	void updateMI(int w, int L, int R, int a, int b, cd v) {
		push(w,L,R);
		if (b<L || R<a) return;
		if (a<=L && R<=b) {
			lmult[w] = v;
			push(w,L,R);
		} else updateMI(w*2,L,(L+R)/2,a,b,v), updateMI(w*2+1,(L+R)/2+1,R,a,b,v);
	}
	cd queryI(int w, int L, int R, int a) {
		push(w,L,R);
		if (L==R) return st[w];
		if (a<=(L+R)/2) return queryI(w*2,L,(L+R)/2,a);
		else return queryI(w*2+1,(L+R)/2+1,R,a);
	}
public:
	ST(int s=0) {
		size = s;
		if (s) build(1,1,size);
	}
	void updateA(int a, cd v) { updateAI(1,1,size,a,size,v); }
	void updateM(int a, cd v) { updateMI(1,1,size,a,size,v); }
	cd query(int a) { return queryI(1,1,size,a); }
};

int n,m;
ST tree;
int ft[300013];
void update(int i, int v) { while (i<=n) ft[i] = (ft[i]+v)%360, i+=i&-i; }
int query(int i) { return i>0 ? (ft[i]+query(i-(i&-i)))%360 : 0; }

ld sini[361], cosi[361];

int main() {
	for (int i=0;i<=360;i++) {
		sini[i] = sin(i*PI/180);
		cosi[i] = cos(i*PI/180);
	}
	scanf("%d%d",&n,&m);
	n+=1;
	tree = ST(n);
	for (int i=0;i<m;i++) {
		int type,x,v;
		scanf("%d%d%d",&type,&x,&v);
		if (type==1) {
			int rad = 360-query(x);
			cd ang(v*cosi[rad],v*sini[rad]);
			tree.updateA(x+1,ang);
		} else {
			cd pos = tree.query(x);
			tree.updateA(x,-pos);
			int rad = 360-v;
			cd ang(cosi[rad],sini[rad]);
			tree.updateM(x,ang);
			tree.updateA(x,pos);
			update(x,v);
		}
		cd res = tree.query(n);
		printf("%1.9f %1.9f\n",(double) res.real(),(double) res.imag());
	}

	return 0;
}