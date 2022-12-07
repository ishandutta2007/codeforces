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
#define double long double
using namespace std;
int n,a[1050],vis[1050];
void solve(){
	scanf("%d",&n);
	memset(vis,0,sizeof(vis));
	For(i,1,n) scanf("%d",&a[i]),vis[a[i]]=1;
	For(i,1,1023){
		bool flag=0;
		For(j,1,n) if (!vis[a[j]^i]) flag=1;
		if (!flag) return cout<<i<<endl,void(0);
	}
	cout<<-1<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}