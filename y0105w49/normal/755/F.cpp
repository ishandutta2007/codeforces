#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef complex<ld> pt;
typedef long long ll;
#define fi first
#define se second
#define pb push_back

const int N=1<<20;
int p[N];
bool seen[N];

int dfs1(int u) {
	int d=0;
	for(;!seen[u];) {
		seen[u]=1;
		u=p[u];
		++d;
	}
	return d;
}
void _main() {
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",p+i);
	map<int,int> cycs;
	for(int i=1;i<=n;i++) if(!seen[i]) cycs[dfs1(i)] += 1;

	static int dp[N];
	dp[0]=1;
   int kk=k;
   if(kk+kk>n) kk=n-kk;
	for(const auto &P:cycs) {
		int del=P.fi;
		int qt=P.se;

		for(int i=0;i<=kk;i++) if(dp[i]) dp[i]=qt+1;
		for(int i=0;i<=kk-del;i++) if(dp[i] && !dp[i+del]) dp[i+del]=dp[i]-1;
             if(dp[kk]) break;
	}

	int mn=k+1;
	if(dp[kk]) mn=k;

	int dub=0;
	int sing=0;

	for(const auto &P:cycs) {
		int len=P.fi;
		int qt=P.se;
		dub += (len/2) * qt;
		if(len%2 == 1) sing += qt;
	}

	int mx=0;
	for(;k--;) {
		if(dub) {
			--dub;
			mx+=2;
			continue;
		}
		if(sing) {
			--sing;
			mx+=1;
			continue;
		}
	}
	printf("%d %d\n",mn,mx);
}

int main() {
	_main();
}