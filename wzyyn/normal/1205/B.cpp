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
using namespace std;
const int N=155;
vector<int> vec[N];
int q[N],ex[N],ey[N];
int n,cnt,e[N][N];
int dis[N],vis[N];
void solve_SSSP(int S){
	For(i,1,*q) dis[i]=1<<30,vis[i]=0;
	dis[S]=0;
	For(i,1,*q){
		int id=-1;
		For(j,1,*q) if (!vis[j])
			if (id==-1||dis[j]<dis[id]) id=j;
		vis[id]=1;
		For(j,1,*q) if (e[id][j])
			dis[j]=min(dis[j],dis[id]+1);
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		ll x;
		scanf("%lld",&x);
		For(j,0,59)
			if (x&(1ll<<j)){
				vec[j].PB(i);
				if (vec[j].size()==3){
					puts("3");
					return 0;
				}
			}
	}
	For(i,0,59)
		if (vec[i].size()==2){
			q[++*q]=vec[i][0];
			q[++*q]=vec[i][1];
			ex[++cnt]=vec[i][0];
			ey[cnt]=vec[i][1];
		}
	sort(q+1,q+*q+1);
	*q=unique(q+1,q+*q+1)-q-1;
	For(i,1,cnt){
		ex[i]=lower_bound(q+1,q+*q+1,ex[i])-q;
		ey[i]=lower_bound(q+1,q+*q+1,ey[i])-q;
	}
	int ans=1<<30;
	For(i,1,cnt){
		memset(e,0,sizeof(e));
		For(j,1,cnt) e[ex[j]][ey[j]]=e[ey[j]][ex[j]]=1;
		e[ex[i]][ey[i]]=e[ey[i]][ex[i]]=0;
		solve_SSSP(ex[i]);
		ans=min(ans,dis[ey[i]]+1);
	}
	if (ans==1<<30)
		printf("-1");
	else printf("%d",ans);
}