#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int a[100013];
vector<int> adj[100013];
ll in[100013], thru[100013];

void setup(int x, int p=0) {
	vector<ll> has(2);
	for (int i: adj[x]) if (i!=p) {
		setup(i,x);
		has.push_back(thru[i]);
		sort(has.begin(),has.end(),greater<ll>());
		has.resize(2);
		in[x] = max(in[x],in[i]);
	}
	in[x] = max(in[x],has[0]+has[1]+a[x]);
	thru[x] = has[0]+a[x];
}

ll ans = 0;
void dfs(int x, int p=0, ll ain=0, ll athru=0) {
	ans = max(ans,ain+in[x]);
	vector<ll> has = { athru,0,0 };
	vector<ll> hasin = { ain,0 };
	for (int i: adj[x]) if (i!=p) {
		has.push_back(thru[i]);
		sort(has.begin(),has.end(),greater<ll>());
		has.resize(3);
		hasin.push_back(in[i]);
		sort(hasin.begin(),hasin.end(),greater<ll>());
		hasin.resize(2);
	}
	for (int i: adj[x]) if (i!=p) {
		ll nin = has[0]+has[1]+a[x];
		if (thru[i]==has[0] || thru[i]==has[1]) nin+=has[2]-thru[i];
		ll nin2 = hasin[0];
		if (in[i]==hasin[0]) nin2 = hasin[1];
		nin = max(nin,nin2);
		nin = max(nin,ain);
		ll nthru = has[0]+a[x];
		if (thru[i]==has[0]) nthru = has[1]+a[x];
		dfs(i,x,nin,nthru);
	}
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	setup(1);
	dfs(1);
	printf("%lld\n",ans);

    return 0;
}