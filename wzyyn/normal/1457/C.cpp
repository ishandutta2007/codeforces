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
int n,p,k,x,y;
char s[100005];
int f[100005];
void solve(){
	scanf("%d%d%d",&n,&p,&k);
	scanf("%s%d%d",s+1,&x,&y);
	Rep(i,n,1){
		f[i]=(i+k>n?0:f[i+k]);
		if (s[i]=='0') f[i]+=x;
	}
	int ans=(1<<30);
	For(i,p,n) ans=min(ans,f[i]+y*(i-p));
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}