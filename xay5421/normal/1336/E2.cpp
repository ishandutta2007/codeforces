#include<bits/stdc++.h>
#define pp __builtin_popcountll
#define ctz __builtin_ctz
using namespace std;
typedef long long LL;
const int N=300005,M=60,P=998244353;
int n,m,rk,C[M][M];
LL b[M];
int fpow(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=1LL*k1*k1%P)if(k2&1)k3=1LL*k3*k1%P;
	return k3;
}
void ins(LL x){
	for(int i=0;i<m;++i)if(x>>i&1){
		if(!b[i]){
			b[i]=x;
			++rk;
			return;
		}
		x^=b[i];
	}
}
void init(){
	int len=0;
	vector<int>o(m);
	vector<LL>num(rk);
	for(int i=0;i<m;++i)if(b[i])o[len]=i,num[len++]=b[i];
	for(int i=0;i<m;++i)if(!b[i])o[len++]=i;
	memset(b,0,sizeof(b));
	for(int i=0;i<rk;++i){
		for(int j=0;j<m;++j){
			if(num[i]>>o[j]&1){
				b[i]|=1LL<<j;
			}
		}
	}
	for(int i=0;i<rk;++i){
		for(int j=0;j<i;++j)if(b[j]>>i&1)b[j]^=b[i];
	}
}
int G(int popi,int c){
	int ans=0;
	for(int j=0;j<=c&&j<=popi&&c-j>=0;++j){
		ans=(ans+(j&1?-1LL:1LL)*C[popi][j]*C[m-popi][c-j])%P;
	}
	if(ans<0)ans+=P;
	return ans;
}
int main(){
	C[0][0]=1;
	for(int i=1;i<M;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
	}
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i){
		LL x;scanf("%lld",&x);
		ins(x);
	}
	init();
	if(rk*2<=m){
		vector<int>ans(m+1);
		LL x=0;
		for(int i=0;i<(1<<rk);++i){
			if(i)x^=b[ctz(i)];
			++ans[pp(x)];
		}
		for(int i=0,x=fpow(2,n-rk);i<=m;++i){
			ans[i]=1LL*ans[i]*x%P;
			printf("%d%c",ans[i],i==m?'\n':' ');
		}
		
	}else{
		vector<LL>c(m-rk);
		for(int i=rk;i<m;++i){
			for(int j=0;j<rk;++j){
				if(b[j]>>i&1){
					c[i-rk]|=1LL<<j;
				}
			}
		}
		vector<int>ans(m+1);
		LL x=0,y=0;
		for(int i=0;i<(1<<(m-rk));++i){
			if(i)x^=c[ctz(i)],y^=1<<ctz(i);
			++ans[pp(y)+pp(x)];
		}
		for(int i=0,x=1LL*fpow(2,n)*fpow((P+1)/2,m)%P;i<=m;++i){
			int now=0;
			for(int j=0;j<=m;++j){
				now=(now+1LL*ans[j]*G(j,i))%P;
			}
			now=1LL*now*x%P;
			printf("%d%c",now,i==m?'\n':' ');
		}
	}
	return 0;
}