#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second
typedef long long ll;

int n,k;
pair<ll,ll> pos[100013];

vector<int> orderx,ordery;
bool byX(int a, int b) { return pos[a].A<pos[b].A; }
bool byY(int a, int b) { return pos[a].B<pos[b].B; }

bool used[100013];

ll get(ll x) { return (x==0) ? 1 : x; }

int main() {
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) {
		ll x1,x2,y1,y2;
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		pos[i] = MP(x1+x2,y1+y2);
		orderx.push_back(i);
		ordery.push_back(i);
	}
	sort(orderx.begin(),orderx.end(),byX);
	sort(ordery.begin(),ordery.end(),byY);
	ll ans = 2e18;
	int ona = 0;
	vector<int> gota;
	for (int a=0;a<=k;a++) {
		while (gota.size()<a) {
			if (!used[orderx[ona]]) used[orderx[ona]] = 1, gota.push_back(orderx[ona]);
			ona+=1;
		}
		int onb = 0;
		vector<int> gotb;
		for (int b=0;b<=k-a;b++) {
			while (gotb.size()<b) {
				if (!used[ordery[onb]]) used[ordery[onb]] = 1, gotb.push_back(ordery[onb]);
				onb+=1;
			}
			int onc = orderx.size()-1;
			vector<int> gotc;
			for (int c=0;c<=k-a-b;c++) {
				while (gotc.size()<c) {
					if (!used[orderx[onc]]) used[orderx[onc]] = 1, gotc.push_back(orderx[onc]);
					onc-=1;
				}
				int ond = ordery.size()-1;
				vector<int> gotd;
				for (int d=0;d<=k-a-b-c;d++) {
					while (gotd.size()<d) {
						if (!used[ordery[ond]]) used[ordery[ond]] = 1, gotd.push_back(ordery[ond]);
						ond-=1;
					}
					int on1 = 0;
					while (used[orderx[on1]]) on1+=1;
					int on2 = orderx.size()-1;
					while (used[orderx[on2]]) on2-=1;
					ll one = get((pos[orderx[on2]].A-pos[orderx[on1]].A)/2);
					on1 = 0;
					while (used[ordery[on1]]) on1+=1;
					on2 = ordery.size()-1;
					while (used[ordery[on2]]) on2-=1;
					ll two = get((pos[ordery[on2]].B-pos[ordery[on1]].B)/2);
					ans = min(ans,one*two);
				}
				for (int i: gotd) used[i] = 0;
			}
			for (int i: gotc) used[i] = 0;
		}
		for (int i: gotb) used[i] = 0;
	}
	for (int i: gota) used[i] = 0;
	printf("%lld\n",ans);

	return 0;
}