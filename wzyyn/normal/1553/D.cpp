#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=100005;
char s[N],t[N];
int n,m;
int f[N][2];
int nx[N][26][2];
void solve(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for (int i=0;i<=25;i++)
		nx[n+1][i][0]=nx[n+1][i][1]=n+1;
	for (int i=n;i>=1;i--){
		memcpy(nx[i],nx[i+1],sizeof(nx[i+1]));
		nx[i][s[i]-'a'][i&1]=i;
	}
	for (int i=1;i<=m;i++)
		f[i][0]=f[i][1]=n+1;
	for (int i=1;i<=n;i++)
		if (s[i]==t[1]) f[1][i&1]=min(f[1][i&1],i);
	for (int i=1;i<m;i++)
		for (int c=0;c<=1;c++)
			if (f[i][c]!=n+1)
				f[i+1][c^1]=min(f[i+1][c^1],nx[f[i][c]+1][t[i+1]-'a'][c^1]);
	puts(f[m][n&1]==n+1?"NO":"YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}