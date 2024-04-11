#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN=1e6;

vector<int> dist[maxN+1];
vector<ll> pDist[maxN+1];
int edge[maxN+1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i=2; i<=n; ++i)
		cin >> edge[i];
	for(int i=n; i>=1; --i) {
		dist[i].push_back(0);
		pDist[i].push_back(0);
		vector<int> a, b;
		if(2*i<=n) {
			a=dist[2*i];
			if(2*i+1<=n)
				b=dist[2*i+1];
		}
		int ia=0, ib=0;
		while(ia<a.size()||ib<b.size()) {
			if(ia>=a.size()) {
				dist[i].push_back(b[ib]+edge[2*i+1]);
				pDist[i].push_back(pDist[i][pDist[i].size()-1]+b[ib]+edge[2*i+1]);
				++ib;
			} else if(ib>=b.size()||a[ia]+edge[2*i]<=b[ib]+edge[2*i+1]) {
				dist[i].push_back(a[ia]+edge[2*i]);
				pDist[i].push_back(pDist[i][pDist[i].size()-1]+a[ia]+edge[2*i]);
				++ia;
			} else {
				dist[i].push_back(b[ib]+edge[2*i+1]);
				pDist[i].push_back(pDist[i][pDist[i].size()-1]+b[ib]+edge[2*i+1]);
				++ib;
			}
		}
	}
	for(; m>0; --m) {
		int a, p;
		ll h1, h2, t=0;
		cin >> a >> h1;
		h2=h1;
		p=upper_bound(dist[a].begin(), dist[a].end(), h2)-dist[a].begin();
		t+=p*h2-pDist[a][p-1];
		h2-=edge[a];
		while(a>>1>=1&&h2>=0) {
			t+=h2;
			if((a^1)<=n&&h2-edge[a^1]>=0) {
				p=upper_bound(dist[a^1].begin(), dist[a^1].end(), h2-edge[a^1])-dist[a^1].begin();
				t+=p*(h2-edge[a^1])-pDist[a^1][p-1];
			}
			a>>=1;
			h2-=edge[a];
		}
		cout << t << "\n";
	}
}