#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5;
int n, a[mxN];
array<int, 2> p[mxN];
bool dp[mxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		p[i]={a[i], i};
	}
	sort(p, p+n, greater<array<int, 2>>());
	for(int i=0; i<n; ++i) {
		for(int j=p[i][1]; (j+=p[i][0])<n; )
			if(a[j]>p[i][0])
				dp[p[i][1]]|=!dp[j];
		for(int j=p[i][1]; (j-=p[i][0])>=0; )
			if(a[j]>p[i][0])
				dp[p[i][1]]|=!dp[j];
	}
	for(int i=0; i<n; ++i)
		cout << (dp[i]?'A':'B');
}