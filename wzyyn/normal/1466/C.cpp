#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;

char s[100005];
int f[100005][2][2];
void solve(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	if (n==1) puts("0");
	else{
		f[2][1][1]=2;
		f[2][1][0]=1;
		f[2][0][1]=1;
		if (s[1]!=s[2]) f[2][0][0]=0;
		else f[2][0][0]=1<<30;
		For(i,3,n) For(j,0,1) For(k,0,1){
			f[i][j][k]=1<<30;
			if (j==0&&k==0&&s[i-1]==s[i]) continue;
			For(l,0,1) if (l||k||s[i-2]!=s[i])
				f[i][j][k]=min(f[i][j][k],f[i-1][l][j]+k);
		}
		int ans=1<<30;
		For(i,0,1) For(j,0,1) ans=min(ans,f[n][i][j]);
		cout<<ans<<endl;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}