#include<iostream>
#include<cstdio>
using namespace std;
const int N=100005;
int ans,n,f[N][3],g[N][3];
char ch[N];
int main(){
	cin>>n;
	scanf("%s",ch+1);
	for(int i=1;i<=n;i++)if(ch[i]=='1'){
		for(int j=0;j<3;j++){
			f[i][j]=max(f[i-1][j],g[i-1][j]+1);
			g[i][j]=g[i-1][j];
		}
		f[i][1]=max(f[i][1],f[i-1][0]+1);
		f[i][2]=max(f[i][2],f[i-1][1]+1);
	}else{
		for(int j=0;j<3;j++){
			g[i][j]=max(g[i-1][j],f[i-1][j]+1);
			f[i][j]=f[i-1][j];
		}
		g[i][1]=max(g[i][1],g[i-1][0]+1);
		g[i][2]=max(g[i][2],g[i-1][1]+1);
	}
	for(int i=0;i<3;i++)ans=max(ans,max(f[n][i],g[n][i]));
	cout<<ans<<endl;
}