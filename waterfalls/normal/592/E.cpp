#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll x[400013], y[400013];
vector<int> pts;

int quad(int a) {
	if (x[a]>0 && y[a]>=0) return 1;
	if (x[a]<=0 && y[a]>0) return 2;
	if (x[a]<0 && y[a]<=0) return 3;
	if (x[a]>=0 && y[a]<0) return 4;
	return 0;
}

bool comp(int a, int b) {
	if (quad(a)!=quad(b)) return quad(a)<quad(b);
	if (x[b]==0) return false;
	if (x[a]==0) return true;
	return y[a]*x[b]<y[b]*x[a];
}

bool cross(int a, int b) {
	a = pts[a%pts.size()];
	b = pts[b%pts.size()];
	ll res = x[a]*y[b]-x[b]*y[a];
	return res>0;
}

map<pair<ll,ll>,ll> slopes;
pair<ll,ll> get(int a) {
	ll g = abs(__gcd(x[a],y[a]));
	return make_pair(x[a]/g,y[a]/g);
}

int main() {
	int c,d;
	scanf("%d%d%d",&n,&c,&d);
	for (int i=0;i<n;i++) {
		scanf("%lld%lld",&x[i],&y[i]);
		x[i]-=c;
		y[i]-=d;
		if (x[i]==0 && y[i]==0) continue;
		pts.push_back(i);
		slopes[get(i)]+=1;
	}
	sort(pts.begin(),pts.end(),comp);
	ll ans = (ll) pts.size()*(pts.size()-1)*(pts.size()-2)/6;
	for (int i=0;i<pts.size();i++) {
		if (i<pts.size()-1 && get(pts[i])==get(pts[i+1])) continue;
		int low = i;
		int high = i+pts.size();
		while (high-low>1) {
			if (cross(i,(low+high)/2)) low = (low+high)/2;
			else high = (low+high)/2;
		}
		ll num = (low-i+pts.size())%pts.size();
		auto p = get(pts[i]);
		auto q = make_pair(-p.first,-p.second);
		ll one = slopes[p];
		ll two = slopes[q];
		ans-=one*(one-1)*(one-2)/6;
		ans-=one*num*(num-1)/2;
		ans-=one*(one-1)/2*num;
		ans-=one*two*num;
		ans-=one*(one-1)/2*two;
	}
	printf("%lld\n",ans);

	return 0;
}