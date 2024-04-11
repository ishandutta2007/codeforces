// author: xay5421
// created: Thu Jun  3 09:18:15 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005,K=20;
int n,m,f[N][K],sum[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		int x;
		scanf("%d",&x);
		f[x][0]=0;
		++sum[x];
	}
	rep(i,1,m)sum[i]+=sum[i-1];
	rep(j,1,K-1){
		rep(i,1,m-(1<<j)+1){
			f[i][j]=f[i][j-1]^f[i+(1<<(j-1))][j-1]^(((sum[i+(1<<j)-1]-sum[i+(1<<(j-1))-1])&1)<<(j-1));
		}
	}
	int Q;
	scanf("%d",&Q);
	while(Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		int dt=r-l+1,res=0;
		per(i,K-1,0)if(dt>>i&1){
			res^=f[l][i];
			l+=1<<i;
			res^=((sum[r]-sum[l-1])&1)<<i;
		}
		putchar('A'+!res);
	}
	return 0;
}