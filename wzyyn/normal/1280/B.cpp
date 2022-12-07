#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
int n,m,S1[65],S2[65];
char s[65][65];
void solve(){
	scanf("%d%d",&n,&m);
	memset(S1,0,sizeof(S1));
	memset(S2,0,sizeof(S2));
	For(i,1,n) scanf("%s",s[i]+1);
	int ans=1<<30,fl=0;
	For(i,1,n) For(j,1,m)
		if (s[i][j]=='A'){
			S1[i]++,S2[j]++;
			ans=min(ans,4-(i==1||i==n)-(j==1||j==m));
		}
		else fl=1;
	if (!fl) ans=0;
	For(i,1,n) if (S1[i]==m) ans=min(ans,2-(i==1||i==n));
	For(i,1,m) if (S2[i]==n) ans=min(ans,2-(i==1||i==m));
	//printf("%d\n",ans);
	if (ans>4) puts("MORTAL");
	else printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}