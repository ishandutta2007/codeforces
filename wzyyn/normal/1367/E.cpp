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
int n,m,f[2005],cnt[30],ans;
char s[2005];
void solve(){
	int ans=0;
	scanf("%d%d%s",&n,&m,s+1);
	memset(f,0,sizeof(f));
	For(i,1,m) f[i]=(m%i==0?i:0);
	For(i,1,n) f[i]=max(f[i],f[i-1]);
	memset(cnt,0,sizeof(cnt));
	For(i,1,n) ++cnt[s[i]-'a'];
	For(i,1,n){
		int sum=0;
		For(j,0,25) sum+=cnt[j]/i;
		ans=max(ans,f[sum]*i);
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}