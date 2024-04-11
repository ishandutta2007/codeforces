#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MP make_pair
#define A first
#define B second
ll sq(ll x) { return x*x; }

int n;
pair<ll,ll> x[100013];
ll lmin[100013], lmax[100013];
ll rmin[100013], rmax[100013];

bool check(ll k) {
	int r = 1;
	for (int l=1;l<=n;l++) {
		if (x[l].A>0) break;
		while (r<n && sq(x[r+1].A-x[l].A)<=k && abs(x[r+1].A)<=abs(x[l].A)) r+=1;
		while (abs(x[r].A)>abs(x[l].A)) r-=1;
		ll low = min(lmin[l-1],rmin[r+1]);
		ll high = max(lmax[l-1],rmax[r+1]);
		if (sq(high-low)<=k && sq(max(abs(low),abs(high)))+sq(max(abs(x[l].A),abs(x[r].A)))<=k) return true;
	}
	int l = n;
	for (r=n;r>=1;r--) {
		if (x[r].A<0) break;
		while (l>1 && sq(x[r].A-x[l-1].A)<=k && abs(x[l-1].A)<=abs(x[r].A)) l-=1;
		while (abs(x[l].A)>abs(x[r].A)) l+=1;
		ll low = min(lmin[l-1],rmin[r+1]);
		ll high = max(lmax[l-1],rmax[r+1]);
		if (sq(high-low)<=k && sq(max(abs(low),abs(high)))+sq(max(abs(x[l].A),abs(x[r].A)))<=k) return true;
	}
	return false;
}

int main() {
	ll minx = 1e9, maxx = -1e9;
	ll miny = 1e9, maxy = -1e9;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		scanf("%lld%lld",&x[i].A,&x[i].B);
		minx = min(minx,x[i].A);
		maxx = max(maxx,x[i].A);
		miny = min(miny,x[i].B);
		maxy = max(maxy,x[i].B);
	}
	sort(x+1,x+n+1);
	for (int i=1;i<=n;i++) {
		lmin[i] = min(lmin[i-1],x[i].B);
		lmax[i] = max(lmax[i-1],x[i].B);
	}
	for (int i=n;i>=1;i--) {
		rmin[i] = min(rmin[i+1],x[i].B);
		rmax[i] = max(rmax[i+1],x[i].B);
	}
	ll low = -1;
	ll high = min((maxx-minx)*(maxx-minx),(maxy-miny)*(maxy-miny));
	while (high-low>1) {
		if (check((low+high+1)/2)) high = (low+high+1)/2;
		else low = (low+high+1)/2;
	}
	printf("%lld\n",high);

	return 0;
}