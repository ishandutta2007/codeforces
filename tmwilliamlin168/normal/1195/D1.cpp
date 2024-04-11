#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, M=998244353;
int n, a[mxN], c[11];
ll ans=0;
vector<ll> d[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		int x=a[i];
		while(x) {
			d[i].push_back(x%10);
			x/=10;
		}
		++c[d[i].size()];
	}
	for(int i=0; i<n; ++i) {
		//as i
		{
			vector<ll> e=d[i];
			ll p=1;
			for(int j=0; j<d[i].size(); ++j, p*=10)
				e[j]=e[j]*p%M;
			for(int j=1; j<=10; ++j) {
				for(int k=j-1; k<d[i].size(); ++k)
					e[k]=e[k]*10%M;
				ll s=0;
				for(ll k : e)
					s+=k;
				//cout << i << " " << j << " " << s << endl;
				ans+=s*c[j]%M;
			}
		}
		//as j
		{
			vector<ll> e=d[i];
			ll p=1;
			for(int j=0; j<d[i].size(); ++j, p*=10)
				e[j]=e[j]*p%M;
			for(int j=1; j<=10; ++j) {
				for(int k=j; k<d[i].size(); ++k)
					e[k]=e[k]*10%M;
				ll s=0;
				for(ll k : e)
					s+=k;
				ans+=s*c[j]%M;
			}
		}

	}
	cout << ans%M;
}