#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;
const int MN = 3003;
bitset<MN> in[MN],out[MN],m;
int N,M,i,j,x,y;long long ans;
int main(){
	for(scanf("%d%d",&N,&M);i<M;i++){
		scanf("%d%d",&x,&y);
		out[x][y]=in[y][x]=1;
	}
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			if(i==j) continue;
			m=out[i]&in[j];
			x=m.count();
			ans += x*(x-1)/2;
		}
	}
	printf("%lld\n",ans);
	return 0;
}