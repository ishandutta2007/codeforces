#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int mo=998244353;
const int N=1005;
char s[N],t[N];
int n,m,f[N][N][2],ans;
int main(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for (int i=0;i<=n;i++)
		for (int j=0;j<=m;j++){
			if (i!=0) f[i][j][0]=1;
			if (j!=0) f[i][j][1]=1;
		}
	for (int i=0;i<=n;i++)
		for (int j=0;j<=m;j++){
			if (t[j+1]!=s[i]) f[i][j+1][1]=(f[i][j+1][1]+f[i][j][0])%mo;
			if (s[i+1]!=s[i]) f[i+1][j][0]=(f[i+1][j][0]+f[i][j][0])%mo;
			if (t[j+1]!=t[j]) f[i][j+1][1]=(f[i][j+1][1]+f[i][j][1])%mo;
			if (s[i+1]!=t[j]) f[i+1][j][0]=(f[i+1][j][0]+f[i][j][1])%mo;
			ans=(ans+f[i][j][0])%mo;
			ans=(ans+f[i][j][1])%mo;
		}
	int l=0;
	for (int i=1;i<=n;i++){
		if (s[i]==s[i-1]) l=1;
		else l++;
		ans=(ans+mo-1ll*l*(m+1))%mo; 
	}
	l=0;
	for (int i=1;i<=m;i++){
		if (t[i]==t[i-1]) l=1;
		else l++;
		ans=(ans+mo-1ll*l*(n+1))%mo; 
	}
	cout<<ans<<endl;
}