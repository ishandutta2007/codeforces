#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, k;
ll ar[110];
vector<ll> cut;
vector<pll> pq;
vector<pll> lis[110];
int key[110];

void find_cut(ll idx, ll v) {
	ll i; --v;
	if (!v) {
		lis[idx].push_back(pll(1,-1));
		return;
	}
	ll cnt = v;
	cut.push_back(1);
	pq.push_back(pll(1,idx));
	lis[idx].push_back(pll(cnt+1,-cnt-1));

	for (i=1;;) {
		int ct= v/(i+1);
		if (!ct) break;
		i = v/ct;
		pq.push_back(pll(i,idx));
		cut.push_back(i);
		cnt = v/i;
		lis[idx].push_back(pll(cnt+1,(i*1987654321-(v+1))%i-i*(cnt+1)));
	}
	lis[idx].push_back(pll(1,-v-1));
}

int main() {
    int i, j = 0; ll a = 0, b = 0;

    scanf("%lld%lld",&n,&k);
    for (i=0;i<n;i++) {
		scanf("%lld",&ar[i]);
    }
    cut.push_back(0); cut.push_back(k+1987654321);
    for (i=0;i<n;i++) find_cut(i,ar[i]);

    sort(cut.begin(),cut.end());
    sort(pq.begin(),pq.end());
	cut.erase(unique(cut.begin(),cut.end()),cut.end());
	for (i=0;i<n;i++) {
		a+=lis[i][0].first;
		b+=lis[i][0].second;
	}
	ll res = 1;
	for (i=1;i<cut.size();i++) {
		if (cut[i-1]<(k-b)/a) res = max(res,(k-b)/a);
		while(j<pq.size()&&pq[j].first<=cut[i]) {
			a-=lis[pq[j].second][key[pq[j].second]].first;
			a+=lis[pq[j].second][key[pq[j].second]+1].first;
			b-=lis[pq[j].second][key[pq[j].second]].second;
			b+=lis[pq[j].second][key[pq[j].second]+1].second;
			key[pq[j].second]++;
			j++;
		}
	}
	printf("%lld\n",res);

    return 0;
}