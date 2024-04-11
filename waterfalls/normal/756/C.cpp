#include <bits/stdc++.h>
using namespace std;

class ST {
private:
	int size;
	int low[1<<18], high[1<<18];
	int lazy[1<<18];
	void push(int w, int L, int R) {
		if (!lazy[w]) return;
		low[w]+=lazy[w];
		high[w]+=lazy[w];
		if (L!=R) lazy[w*2]+=lazy[w], lazy[w*2+1]+=lazy[w];
		lazy[w] = 0;
	}
	void update(int w, int L, int R, int a, int b, int v) {
		push(w,L,R);
		if (b<L || R<a) return;
		if (a<=L && R<=b) lazy[w]+=v, push(w,L,R);
		else {
			update(w*2,L,(L+R)/2,a,b,v), update(w*2+1,(L+R)/2+1,R,a,b,v);
			low[w] = min(low[w*2],low[w*2+1]);
			high[w] = max(high[w*2],high[w*2+1]);
		}
	}
	int minquery(int w, int L, int R, int a, int b) {
		push(w,L,R);
		if (b<L || R<a) return 1e9;
		if (a<=L && R<=b) return low[w];
		return min(minquery(w*2,L,(L+R)/2,a,b),minquery(w*2+1,(L+R)/2+1,R,a,b));
	}
	int maxquery(int w, int L, int R, int a, int b) {
		push(w,L,R);
		if (b<L || R<a) return -1e9;
		if (a<=L && R<=b) return high[w];
		return max(maxquery(w*2,L,(L+R)/2,a,b),maxquery(w*2+1,(L+R)/2+1,R,a,b));
	}
public:
	ST(int s=0) {
		size = s;
		memset(low,0,sizeof low);
		memset(high,0,sizeof high);
		memset(lazy,0,sizeof lazy);
	}
	void update(int a, int b, int v) { update(1,0,size,a,b,v); }
	int minquery(int a, int b) { return minquery(1,0,size,a,b); }
	int maxquery(int a, int b) { return maxquery(1,0,size,a,b); }
};

int n;
int x[100013];
ST tree;

int main() {
	scanf("%d",&n);
	tree = ST(n);
	x[n+1] = -1;
	int last = 0;
	for (int i=0;i<n;i++) {
		int p,t;
		scanf("%d%d",&p,&t);
		last = max(last,p);
		if (t==0) {
			tree.update(1,p,-1);
		} else {
			tree.update(1,p,1);
			scanf("%d",&x[p]);
		}
		int low = 0;
		int high = last+1;
		while (high-low>1) {
			int mid = (low+high)/2;
			int b = tree.maxquery(mid,last);
			if (b>0) low = mid;
			else high = mid;
		}
		if (low==0) printf("-1\n");
		else printf("%d\n",x[low]);
	}

	return 0;
}