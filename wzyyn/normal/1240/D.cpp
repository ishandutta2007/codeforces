#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define y1 fdhjksa
using namespace std;
const int N=300005;
int n,a[N],d[N];
int nx[N],id[N];
map<int,int> mp[N];
ll ans;
void solve(){
	scanf("%d",&n);
	ans=0;
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n+2) d[i]=0,nx[i]=-1,id[i]=i,mp[i].clear();
	Rep(i,n,1){
		if (mp[id[i+1]][a[i]]){
			int p=mp[id[i+1]][a[i]];
			id[i]=id[p+1];
			ans+=(d[i]=d[p+1]+1);
			if (p!=n) mp[id[i]][a[p+1]]=p+1;
		}
		mp[id[i]][a[i]]=i;
	}
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}