#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define A first
#define B second
typedef long long ll;

int n,l;

void quit() { printf("NO\n"), exit(0); }
vector<int> make(vector<pair<int,pair<ll,ll> > > X, int s) {
	vector<int> res;
	int prev = 0;
	int prevS = 0;
	for (auto cur: X) {
		ll hereS = cur.B.A-s*cur.B.B;
		for (int i=0;i<hereS-prevS;i++) res.push_back(1);
		int here = cur.A;
		for (int i=0;i<here-prev-(hereS-prevS);i++) res.push_back(0);
		prev = here;
		prevS = hereS;
	}
	while (prevS<s) res.push_back(1), prevS+=1;
	while (res.size()<l) res.push_back(0);
	return res;
}
vector<int> solve(vector<pair<ll,ll> > pts) {
	for (auto& p: pts) {
		if ((p.A+p.B)%2==1) quit();
		p.B = (p.B+p.A)/2;
	}
	vector<pair<int,pair<ll,ll> > > X;
	for (auto p: pts) X.push_back(MP(p.A%l,MP(p.B,p.A/l)));
	sort(X.begin(),X.end());
	ll low = 0;
	ll high = l;
	auto prev = X[0];
	for (auto cur: X) {
		if (cur==prev) continue;
		int z = cur.A-prev.A;
		ll x = cur.B.A-prev.B.A;
		ll y = -cur.B.B+prev.B.B;
		if (0<=x && x<=z) {
			if (y>0) high = min(high,(z-x)/y);
		} else if (x<0) {
			if (y<=0) quit();
			low = max(low,(-x+y-1)/y);
			high = min(high,(-x+z+y-1)/y);
		} else if (x>z) {
			if (y>=0) quit();
			y = -y;
			low = max(low,(x-z+y-1)/y);
			high = min(high,(x+y-1)/y);
		}
		prev = cur;
	}
	for (ll i=low;i<=high;i++) {
		ll val = prev.B.A-i*prev.B.B;
		if (val<=i && val+l-prev.A>=i) return make(X,i);
	}
	quit();
}

ll t[200013];
ll x[200013];
ll y[200013];
char rev[4] = {'L','U','D','R'};

int main() {
	scanf("%d%d",&n,&l);
	for (int i=1;i<=n;i++) scanf("%lld%lld%lld",&t[i],&x[i],&y[i]);
	vector<int> one,two;
	for (int r=-1;r<=1;r++) {
		if (!r) continue;
		vector<pair<ll,ll> > has;
		for (int i=0;i<=n;i++) has.push_back(MP(t[i],x[i]+r*y[i]));
		one = solve(has);
		swap(one,two);
	}
	for (int i=0;i<l;i++) printf("%c",rev[one[i]*2+two[i]]);
	printf("\n");

	return 0;
}