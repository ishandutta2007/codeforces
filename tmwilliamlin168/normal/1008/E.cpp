#include <bits/stdc++.h>
using namespace std;

#define ll long long

int qc, lqc;
vector<array<ll, 5>> dat;

inline int qry(ll x, ll y) {
	++qc;
	cout << x << " " << y << endl;
	int ans;
	cin >> ans;
	if(!ans) {
		dat.push_back({qc-lqc, 0, 0, 0, 0});
//		cout << dat.size() << "\n";
//		for(array<ll, 5> di : dat)
//			for(int i=0; i<5; ++i)
//				cout << di[i] << " ";
		exit(0);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	ll n;
	cin >> n;
//	qry(1, 1);
	ll a=1, b=1, c=n, d=n;
	while(a<c||b<d) {
		dat.push_back({qc-lqc, a, b, c-a, d-b});
		lqc=qc;
		ll e=(2*a+c)/3, f=(2*b+d)/3;
		int ans=qry(e, f);
		if(ans==1) {
			a=e+1;
			continue;
		} else if(ans==2) {
			b=f+1;
			continue;
		}
		while(e>a&&f>b) {
			if(e-a>f-b) {
				ll m=(a+e)/2;
				ans=qry(m, f);
				if(ans==1)
					a=m+1;
				else if(ans==2) {
					b=f+1;
					break;
				} else
					e=m;
			} else {
				ll m=(b+f)/2;
				ans=qry(e, m);
				if(ans==1) {
					a=e+1;
					break;
				} else if(ans==2)
					b=m+1;
				else
					f=m;
			}
		}
		if(e<=a)
			d=f-1;
		else if(f<=b)
			c=e-1;
	}
	qry(a, b);
}