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

map<pair<pii,pii>,int> mp;
char s[100005];
void solve(){
	mp.clear();
	scanf("%s",s+1);
	int x=0,y=0,n=strlen(s+1),ans=0;
	For(i,1,n){
		int nx=x,ny=y;
		if (s[i]=='N') ++nx;
		if (s[i]=='S') --nx;
		if (s[i]=='E') ++ny;
		if (s[i]=='W') --ny;
		pair<pii,pii> tmp=make_pair(pii(x,y),pii(nx,ny));
		if (tmp.fi>tmp.se) swap(tmp.fi,tmp.se);
		if (mp[tmp]) ans++;
		else ans+=5;
		mp[tmp]=1;
		x=nx; y=ny;
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}