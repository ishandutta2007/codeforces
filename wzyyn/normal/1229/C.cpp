#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=100005;
int S1[N],S2[N];
int n,m,Q,deg[N];
vector<int> e[N];
ll ans;
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		if (x>y) swap(x,y);
		++S1[x]; ++S2[y];
		++deg[x]; ++deg[y];
		e[x].PB(y);
	}
	For(i,1,n)
		ans+=1ll*S1[i]*S2[i];
	printf("%lld\n",ans);
	scanf("%d",&Q);
	while (Q--){
		int x;
		scanf("%d",&x);
		ans-=1ll*S1[x]*S2[x];
		S1[x]=0; S2[x]=deg[x];
		For(i,0,e[x].size()-1){
			int y=e[x][i];
			ans-=1ll*S1[y]*S2[y];
			--S2[y]; ++S1[y];
			ans+=1ll*S1[y]*S2[y];
			e[y].PB(x);
		}
		e[x].clear();
		printf("%lld\n",ans);
	}
}