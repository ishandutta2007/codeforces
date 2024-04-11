#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,p=998244353;
int d,n,m,q;
int a[N],b[31],f[31],dp2[31][31],dp1[31][31];
int main(){
	scanf("%d%d%d",&d,&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	b[++m]=-d;
	b[++m]=d*2;
	stable_sort(b+1,b+1+m);
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			dp1[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=j+1;k<=m;k++){
				if(b[j]<a[i]&&a[i]<b[k]){
					dp1[j][k]=1ll*dp1[j][k]*(min(min(a[i]-b[j],b[k]-a[i])-1,d)+1)%p;
				}
			}
		}
	}
	scanf("%d",&q);
	while(q--){
		int x;
		scanf("%d",&x);
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				dp2[i][j]=dp1[i][j];
			}
		}
		for(int j=1;j<=m;j++){
			for(int k=j+1;k<=m;k++){
				if(b[j]<x&&x<b[k]){
					dp2[j][k]=1ll*dp2[j][k]*(min(min(x-b[j],b[k]-x)-1,d)+1)%p;
				}
			}
		}
		f[1]=p-1;
		for(int i=2;i<=m;i++){
			f[i]=0;
			for(int j=1;j<i;j++){
				f[i]=(f[i]+1ll*f[j]*dp2[j][i])%p;
			}
			f[i]=(p-f[i])%p;
		}
		printf("%d\n",f[m]);
	}
}