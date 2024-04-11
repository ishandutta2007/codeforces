#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=50;
const ll oo=1ll<<60;
int n;
ll k, dp[mxN+1], f[mxN+1], g[mxN+1];
bool b1[mxN];

ll add(ll a, ll b) {
	if(a+b<=oo)
		return a+b;
	return oo;
}

ll mult(ll a, ll b) {
	if(a<=oo/b)
		return a*b;
	return oo;
}

vector<int> rec2(int n, ll k) {
	vector<int> p(n);
	p[0]=n-1;
	memset(b1, 0, n);
	b1[n-1]=1;
	for(int i=1; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			if(b1[j])
				continue;
			p[i]=j;
			ll c;
			if(i<n-1) {
				c=f[n-2-i];
				//check no cycle
				/*
				memset(vis, 0, n);
				for(int a=0; a<n; ++a) {
					if(vis[a])
						continue;
					vis[a]=1;
					int b=p[a];
					while(b<=i)
						if(b==a)
							break;
					if(b<=i)
						c=0;
				}
				*/
				int b=j;
				while(b<=i) {
					if(b==i)
						break;
					b=p[b];
				}
				if(b==i)
					c=0;
			} else
				c=1;
			if(c<=k) {
				k-=c;
			} else {
				b1[j]=1;
				break;
			}
		}
	}
	return p;
}

vector<int> rec1(int n, ll k) {
	//cout << "rec1 " << n << " " << k << endl;
	if(!n)
		return vector<int>();
	for(int i=1; i<=n; ++i) {
		if(mult(dp[n-i], g[i])<=k) {
			k-=mult(dp[n-i], g[i]);
		} else {
			vector<int> w1=rec2(i, k/dp[n-i]), w2=rec1(n-i, k%dp[n-i]);
			for(int &wi : w2)
				wi+=i;
			w1.insert(w1.end(), w2.begin(), w2.end());
			return w1;
		}
	}
}

void solve() {
	cin >> n >> k;
	if(dp[n]<k) {
		cout << "-1\n";
		return;
	}
	vector<int> v=rec1(n, k-1);
	for(int i=0; i<n; ++i)
		cout << v[i]+1 << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	f[0]=1;
	for(int i=1; i<=mxN; ++i)
		f[i]=mult(f[i-1], i);
	g[1]=1;
	for(int i=2; i<=mxN; ++i)
		g[i]=f[i-2];
	dp[0]=1;
	for(int i=1; i<=mxN; ++i) {
		for(int j=1; j<=i; ++j)
			dp[i]=add(dp[i], mult(dp[i-j], g[j]));
	}

	int t;
	cin >> t;
	while(t--)
		solve();
}