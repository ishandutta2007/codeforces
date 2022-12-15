#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN=1e5+5,LG=32;
int n, k, cnt[LG], psa[MN][LG], i, j, x, r, p[LG];
long long ans; unordered_map<int,int> idx;

int main(){
	scanf("%d%d",&n,&k); r=k;
	for(i=2;i*i<=k;i++){
		int c = 0;
		while(r%i==0){
			r/=i; c++;
		}
		if(c) idx[i]=++j,cnt[j]=c;
	}
	if(r!=1) idx[r]=++j,cnt[j]=1;
	for(i=1;i<=n;i++){
		scanf("%d",&x);r=x;
		for(j=1;j<LG;j++)
			psa[i][j]=psa[i-1][j];
		for(auto e : idx){
			while(r%e.first==0){
				r/=e.first; psa[i][e.second]++;
			}
		}
	}
	for(i=1;i<=n;i++){
		int mn = 1<<30;
		for(j=1;j<LG;j++){
			while(p[j]<i&&psa[i][j]-psa[p[j]][j]>=cnt[j]) p[j]++;
			mn = min(mn, p[j]);
		}
		ans += mn;
	}
	printf("%lld\n",ans);
	getchar(); getchar();
}