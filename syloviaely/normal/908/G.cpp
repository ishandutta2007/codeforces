#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;
const int N=310000;
int ww[120][800];
int n,C[710][710],ten[800];
char ch[710];
const int mo=1e9+7;
int f[710][10],g[710][10];
int get(int l,int r){
	return (ten[r]-ten[l-1]+mo)%mo;
}
void preget(){
	for (int m=0;m<=n;m++)
		for (int w=0;w<=9;w++){
			for (int k1=0;k1<=m;k1++)
				f[m][w]=(f[m][w]+1ll*C[m][k1]*ten[k1]%mo*w%mo*ww[90-9*w][m-k1])%mo;
		}
	for (int m=0;m<=n;m++)
		for (int w=0;w<=9;w++){
			for (int k1=0;k1<=m;k1++)
				g[m][w]=(g[m][w]+1ll*C[m][k1]*ww[10][k1]%mo*w%mo*ww[90-9*w][m-k1])%mo;
		}
		/*for (int w=0;w<=9;w++){
			g[m][w]=1ll*g[m-1][w]*(10-w)%mo;
			for (int k=0;k<m;k++){
				int k1=m-k;
				int num=1ll*C[n][k]*C[n-k][k1]%mo*ww[10][m]%mo*ww[w][k+1]%mo;
				g[m][w]=(g[m][w]+num)%mo;
			}
		}*/
}
int pre[11];
void add(int k1,int k2){
	//cout<<"add "<<k1<<" "<<k2<<endl;
	for (int i=k1-1;i>=0;i--) pre[i]+=k2;
}
int main(){
	scanf("%s",ch+1); n=strlen(ch+1);
	for (int i=0;i<=110;i++){
		ww[i][0]=1;
		for (int j=1;j<=n;j++) ww[i][j]=1ll*ww[i][j-1]*i%mo;
	}
	ten[0]=0;
	for (int i=1;i<=n;i++) ten[i]=(ten[i-1]+ww[10][i-1])%mo;
	for (int i=0;i<=n;i++){
		C[i][0]=1;
		for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
	}
	preget();
	int ans=0;
	for (int i=1;i<=n;i++){
		int m=n-i;
		add(0,1);
		int lim=ch[i]-'0'-1; if (i==n) lim++;
		for (int j=0;j<=lim;j++){
			for (int w=1;w<10;w++){
				ans=(ans+1ll*f[m][w]*ww[10][pre[w]])%mo;
				ans=(ans+1ll*g[m][w]*get(pre[w]+1,pre[w-1]))%mo;
			}
			add(j,-1);
			add(j+1,1);
		}
	}
	//cout<<"end"<<endl;
	cout<<ans<<endl;
	return 0;
}