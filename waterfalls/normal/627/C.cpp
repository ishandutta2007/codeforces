#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MP make_pair
#define A first
#define B second


int st[1<<20];
class ST {
private:
	int size;
	void updateI(int w, int L, int R, int a, int v) {
		if (a<L || R<a) return;
		st[w] = min(st[w],v);
		if (L!=R) {
			updateI(w*2,L,(L+R)/2,a,v), updateI(w*2+1,(L+R)/2+1,R,a,v);
		}
	}
	int queryI(int w, int L, int R, int a, int b) {
		if (b<L || R<a) return 1e9+7;
		if (a<=L && R<=b) return st[w];
		return min(queryI(w*2,L,(L+R)/2,a,b),queryI(w*2+1,(L+R)/2+1,R,a,b));
	}
public:
	ST(int s=0) {
		size = s;
		fill(st,st+(1<<20),1e9+7);
	}
	void update(int a, int v) { updateI(1,0,size-1,a,v); }
	int query(int a, int b) { return queryI(1,0,size-1,a,b); }
};

int n,d,l;
vector<pair<int,int> > gas;
ST tree;

int main() {
	scanf("%d%d%d",&d,&l,&n);
	for (int i=0;i<n;i++) {
		int x,p;
		scanf("%d%d",&x,&p);
		gas.push_back(MP(x,p));
	}
	gas.push_back(MP(0,0));
	gas.push_back(MP(d,0));
	n+=2;
	sort(gas.begin(),gas.end());
	tree = ST(n);
	for (int i=0;i<n;i++) tree.update(i,gas[i].B);
	int cur = l;
	ll ans = 0;
	for (int i=0;i<n;i++) {
		if (i) {
			if (cur<gas[i].A-gas[i-1].A) return printf("-1\n"), 0;
			cur-=gas[i].A-gas[i-1].A;
		}
		int loc = gas[i].A;
		if (loc+cur>=d) break;
		int low = -1;
		int high = l-cur;
		while (high-low>1) {
			int mid = (low+high+1)/2;
			int far = loc+cur+mid;
			far = min(far,d+1);
			far = lower_bound(gas.begin(),gas.end(),MP(far,2147483647))-gas.begin()-1;
			if (tree.query(i+1,far)>gas[i].B) low = mid;
			else high = mid;
		}
		ans+=(ll) gas[i].B*high;
		cur+=high;
	}
	printf("%lld\n",ans);

	return 0;
}