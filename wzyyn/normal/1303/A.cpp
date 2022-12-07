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
char s[505];
void solve(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	int fi=n+1,la=0,ans=0;
	For(i,1,n) if (s[i]=='1')
		fi=min(fi,i),la=max(la,i);
	For(i,fi,la) if (s[i]=='0') ++ans;
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}