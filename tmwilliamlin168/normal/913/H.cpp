#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll M=998244353, mgc=1000000;

ll inv(ll x, ll m=M) {
	return x<=1?x:((1-inv(m%x, x)*m)/x+m)%m;
}

struct poly {
	vector<ll> v;
	inline ll& operator[](int i) {
		if(v.size()<=i)
			v.resize(i+1);
		return v[i];
	}
	inline ll operator()(ll x) {
		ll res=0;
		for(int i=v.size()-1; i>=0; --i)
			res=(res*x+v[i])%M;
		return res;
	}
	inline void integrate() {
		if(v.empty()||v.back())
			v.push_back(0);
		for(int i=v.size()-1; i; --i)
			v[i]=v[i-1]*inv(i)%M;
		v[0]=0;
	}
} dp1[930];

int n, fc, cut[30];
ll x[30], pt[931], dist[930], dp2[930];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	vector<int> f={0};
	for(int i=0; i<n; ++i) {
		double d;
		cin >> d;
		x[i]=(ll)(d*mgc+0.5);
		f.push_back(x[i]%mgc);
	}
	sort(f.begin(), f.end());
	f.resize(unique(f.begin(), f.end())-f.begin());
	fc=f.size();
	for(int i=0; i<n; ++i)
		for(int j=0; j<fc; ++j)
			pt[i*fc+j]=(i+f[j]*inv(mgc))%M;
	pt[n*fc]=n;
	for(int i=0; i<n; ++i)
		cut[i]=find(pt, pt+n*fc+1, (x[i]*inv(mgc))%M)-pt;
	for(int i=0; i<n*fc; ++i)
		dist[i]=(pt[i+1]-pt[i]+M)%M;
	for(int i=0; i<n*fc; ++i) {
		if(i<min(fc, cut[0])) {
			dp1[i][1]=1;
			dp2[i]=dist[i];
		}
	}
	for(int k=1; k<n; ++k) {
		for(int i=n*fc-1; i>=0; --i) {
			if(i>=cut[k]) {
				dp1[i].v.clear();
				dp2[i]=0;
			} else {
				for(int j=i-1; j>=max(i-fc, 0); --j)
					dp1[i][0]+=dp2[j];
				dp1[i][0]%=M;
				if(i-fc>=0)
					for(int j=0; j<dp1[i-fc].v.size(); ++j)
						dp1[i][j]=(dp1[i][j]-dp1[i-fc][j]+M)%M;
				dp1[i].integrate();
				dp2[i]=dp1[i](dist[i]);
			}
		}
	}
	ll ans=0;
	for(int i=0; i<n*fc; ++i)
		ans+=dp2[i];
	cout << ans%M;
}