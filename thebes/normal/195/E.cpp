#include <bits/stdc++.h>
using namespace std;

const int MN=1e5+5,mod=1e9+7;
int N, M, i, x, y, ds[MN], d[MN], h[MN], ans;

int ld(int x){return ds[x]=(ds[x]==x)?x:ld(ds[x]);}
int len(int x){return d[x]=(ds[x]==x)?0:(d[x]+len(ds[x]))%mod;}

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++)
		ds[i]=i;
	for(i=1;i<=N;i++){
		for(scanf("%d",&M);M>0;M--){
			scanf("%d%d",&x,&y);
			y = (1LL*len(x)+y+mod)%mod;
			x = ld(x);
			ds[x] = i;
			d[x] = y;
			ans = (ans+y)%mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}