#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

const int mxN=2e5, M=1e9+7;
int n, q, x, y;
ll a[mxN], w[mxN], ft[mxN+1][2];

void upd(int i, ll x, int j) {
	for(++i; i<=n; i+=i&-i) {
		ft[i][j]+=x;
		if(j)
			ft[i][j]%=M;
	}
}

ll qry(int i, int j) {
	ll r=0;
	for(; i; i-=i&-i) {
		r+=ft[i][j];
		if(j)
			r%=M;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> q;
	for(int i=0; i<n; ++i)
		cin >> a[i];
	for(int i=0; i<n; ++i) {
		cin >> w[i];
		upd(i, w[i], 0);
		upd(i, (a[i]-i)*w[i], 1);
	}
	while(q--) {
		cin >> x >> y;
		if(x<0) {
			x=-x-1;
			upd(x, y-w[x], 0);
			upd(x, (a[x]-x)*(y-w[x]), 1);
			w[x]=y;
		} else {
			--x;
			--y;
			ll s1=qry(x, 0), s2=qry(y+1, 0), lb=0, c=0;
			for(int i=17; i>=0; --i) {
				if((lb+(1<<i))<n&&2*(c+ft[lb+(1<<i)][0])<s2+s1) {
					lb+=1<<i;
					c+=ft[lb][0];
				}
			}
			cout << ((qry(y+1, 1)-2*qry(lb, 1)+qry(x, 1))%M-(qry(y+1, 0)-2*qry(lb, 0)+qry(x, 0))%M*(a[lb]-lb)%M+2*M)%M << "\n";
		}
	}
}