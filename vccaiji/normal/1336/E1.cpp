#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int qow(int a,int n){
	int ans=1;
	for(;n;n>>=1){
		if(n&1) ans=((long long)ans*a)%p;
		a=((long long)a*a)%p;
	}
	return ans;
}
int ans[60],tot=0,tot2=0;
long long a[60],b[60];
int C[60][60];
void dfs1(int i,long long x){
	if(i==tot){
		ans[__builtin_popcountll(x)]++;
		return;
	}
	dfs1(i+1,x);
	dfs1(i+1,x^b[i+1]);
}
void dfs2(int i,long long x){
	if(i==tot2){
		ans[__builtin_popcountll(x)]++;
		return;
	}
	dfs2(i+1,x);
	dfs2(i+1,x^b[i+1]);
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		long long aa;
		scanf("%lld",&aa);
		for(int j=m-1;j>=0;j--){
			if((aa>>j)&1){
				if(a[j])aa^=a[j];
				else{
					a[j]=aa;
					tot++;
					break;
				}
			}
		}
	}
	if(tot<=m/2){
		for(int i=0,j=0;i<m;i++){
			if(a[i]){
				j++;
				b[j]=a[i];
			}
		}
		dfs1(0,0);
		for(int i=0;i<=m;i++) printf("%lld ",((long long)qow(2,n-tot)*ans[i])%p);
		return 0;
	}
	for(int i=0;i<m;i++){
		if(a[i]==0){
			int j=++tot2;
			for(int k=0;k<m;k++){
				if(a[k]){
					for(int u=0;u<k;u++){
						if(((a[k]&b[j])>>u)&1ll) b[j]^=(1ll<<k);
					}
				} 
				else{
					if(k==i) b[j]^=(1ll<<k);
				}
			}
		}
	}
	dfs2(0,0);
	for(int i=0;i<=m;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	}
	for(int i=0;i<=m;i++){
		int anss=0;
		for(int j=0;j<=m;j++){
			int t=0;
			for(int k=0;k<=min(i,j);k++){
				if(k&1) t=(t+(long long)(p-C[j][k])*C[m-j][i-k])%p;
				else t=(t+(long long)C[j][k]*C[m-j][i-k])%p;
			}
			anss=(anss+(long long)ans[j]*t)%p;
		}
		printf("%lld ",((long long)anss*qow(2,n+p-1-m))%p);
	}
	return 0;
}