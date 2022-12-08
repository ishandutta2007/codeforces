#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define fail return puts("-1"),0
using namespace std;
typedef long long ll;
int to[111],n;
ll ans=1;
bool vis[111];
void work(ll &ans,ll x) {
	if(x==0)return;
	ans=ans*x/__gcd(ans,x);
}
int main() {
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&to[i]);
	rep(i,1,n)if(!vis[i]){
		int now=i,cnt=0;
		while(!vis[to[now]]){
			now=to[now];
			++cnt;
			vis[now]=1;
		}
		if(cnt&1)work(ans,cnt);
		else work(ans,cnt/2);
	}
	rep(i,1,n)if(!vis[i])fail;cout<<ans;
	return 0;
}