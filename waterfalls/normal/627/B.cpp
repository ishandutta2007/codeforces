#include <bits/stdc++.h>
using namespace std;

class FT {
private:
	int size;
	int ft[200013];
	int lim;
	int cur[200013];
	int sumto(int x) { return x>0 ? ft[x]+sumto(x-(x&-x)) : 0; }
public:
	FT(int s=0, int l=0) {
		size = s;
		fill(ft,ft+size+1,0);
		lim = l;
		fill(cur,cur+size+1,0);
	}
	void update(int x, int v) {
		v = min(v,lim-cur[x]);
		cur[x]+=v;
		while (x<=size) ft[x]+=v, x+=x&-x;
	}
	int query(int a, int b) { return sumto(b)-sumto(a-1); }
};

int n,k,a,b,q;
FT high, low;

int main() {
	scanf("%d%d%d%d%d",&n,&k,&a,&b,&q);
	low = FT(n,b);
	high = FT(n,a);
	for (int Q=0;Q<q;Q++) {
		int type;
		scanf("%d",&type);
		if (type==1) {
			int d,a;
			scanf("%d%d",&d,&a);
			high.update(d,a);
			low.update(d,a);
		} else {
			int p;
			scanf("%d",&p);
			int res = 0;
			res+=low.query(1,p-1);
			res+=high.query(p+k,n);
			printf("%d\n",res);
		}
	}

	return 0;
}