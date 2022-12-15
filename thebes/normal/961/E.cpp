#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int MN = 2e5+5;
int n, s, p, i, arr[MN], j;
vector<int> vec[505];
long long ans;

int main(){
	for(scanf("%d",&n);i<n;i++)
		scanf("%d",&arr[i]);
	s = sqrt(n+0.0);
	for(i=0;i<n;i++)
		vec[i/s].pb(arr[i]);
	for(i=0;i<500;i++)
		sort(begin(vec[i]),end(vec[i]));
	for(i=0;i<n;i++){
		for(j=i+1;j<min(n,arr[i]);){
			if(j%s==0&&j+s<arr[i]){
				int p=lower_bound(begin(vec[j/s]),end(vec[j/s]),i+1)-begin(vec[j/s]);
				ans += vec[j/s].size()-p;
				j += s; continue;
			}
			if(arr[j++]>=i+1) ans++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}