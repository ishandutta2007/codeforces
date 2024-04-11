#include<bits/stdc++.h>
using namespace std;
int n,k;
char s[5100];
int p=998244353;
int C[5100][5100];
int u[5100];
int main(){
	cin>>n>>k;
	scanf("%s",s+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1') u[++cnt]=i;
	}
	u[cnt+1]=n+1;
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	}
	if(k==0){
		cout<<1;
		return 0;
	}if(k>cnt){
		cout<<1;
		return 0;
	}int ans=1;
	for(int i=1;i<=cnt-k+1;i++){
		ans=(ans+C[u[i+k]-1-u[i-1]][k])%p;
		ans=(ans+p-C[u[i+k]-1-u[i]][k-1])%p;
	}
	for(int i=cnt-k+2;i<=cnt;i++){
		ans=(ans+C[n-u[i-1]][cnt-i+1])%p;
		ans=(ans+p-C[n-u[i]][cnt-i])%p;
	}
	cout<<ans;
	return 0;
}