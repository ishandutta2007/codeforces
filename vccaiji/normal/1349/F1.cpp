#include<bits/stdc++.h>//I love luogu
using namespace std;
const int p=998244353;
int a[5100][5100];
int main(){
	int n;
    scanf("%d",&n);
	for(int i=1;i<=n;i++){
		a[i][0]=1;
		a[i][i-1]=1;
		for(int j=1;j<i-1;j++)
			a[i][j]=(1ll*a[i-1][j-1]*(i-j)+1ll*a[i-1][j]*(j+1))%p;
	}
	for(int i=1;i<=n;i++){
		int ans=0;
		int u=1;
		for(int j=n;j>=i;j--){
			ans=(ans+1ll*a[j][i-1]*u)%p;
			u=(1ll*u*j)%p;
		}
		printf("%d ",ans);
	}
	return 0;
}