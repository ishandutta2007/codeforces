#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=5005;
int n,LCP[N][N];
int f[N];
char s[N];
void solve(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i=1;i<=n+1;i++)
		LCP[i][n+1]=LCP[n+1][i]=0;
	for (int i=n;i>=1;i--)
		for (int j=n;j>=1;j--)
			LCP[i][j]=(s[i]==s[j]?LCP[i+1][j+1]+1:0);
	for (int i=1;i<=n;i++) f[i]=0;
	int ans=0;
	for (int i=1;i<=n;i++){
		f[i]=max(f[i],n-i+1);
		ans=max(ans,f[i]);
		for (int j=i+1;j<=n;j++){
			int L=LCP[i][j];
			if (s[i+L]<s[j+L]) f[j]=max(f[j],f[i]+(n-j-L+1)); 
		}
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}