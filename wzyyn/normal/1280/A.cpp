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
int x,n;
char s[3000005];
const int mo=1000000007;
void solve(){
	scanf("%d%s",&x,s+1);
	n=strlen(s+1);
	int ans=n;
	For(i,1,x){
		int tms=(s[i]-'0');
		ans=(ans+1ll*(tms-1)*(ans+mo-i))%mo;
		if (n<=x){
			int L=i+1,R=n;
			For(j,1,tms-1) For(k,L,R) s[++n]=s[k];
		}
		//printf("%d %d %d\n",i,n,ans);
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}