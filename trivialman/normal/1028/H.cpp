#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int MAXN = 194598, MAXA = 5032107;

int dp[MAXA+5][8], best[MAXN+5][14], fac[130];
int largep[MAXA+5];
int n,q,x,y,l,r;

int main() {
	scanf("%d%d",&n,&q);
	rep(i,1,MAXA) largep[i] = i;
	rep(i,2,MAXA) if(largep[i]==i)
		for(int j=i+i;j<=MAXA;j+=i) largep[j] = i;
	rep(i,1,n){
		scanf("%d",&y);
		int num=0, pfac[8];
		for(;y>1;){
			int p = largep[y];
			while(y%(p*p)==0) y/=(p*p);
			if(y%p==0) pfac[++num] = p, y /= p;
		}
		
		rep(k,0,14) best[i][k] = best[i-1][k];
		rep(d,0,num)rep(j,0,d?(1<<d-1)-1:0){
			int newj = d?j+(1<<d-1):0, dist = num - __builtin_popcount(newj), val = fac[newj] = (d ? fac[j] * pfac[d] : 1);
			rep(k,0,7) best[i][dist+k] = max(best[i][dist+k], dp[val][k]);
			dp[val][dist] = max(dp[val][dist], i);
		}
	}
	
	while(q--){
		scanf("%d%d",&l,&r);
		rep(i,0,14) if(best[r][i]>=l){
			printf("%d\n",i);break;
		}
	}
	return 0; 
}