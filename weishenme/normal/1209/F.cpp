#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int N=8000005,M=1e9+7;
typedef long long ll;
vector<pair<int ,int > > G[N];
int n,m,x,y,to[N],now[N],Q[N],a[10],Ans[N];
bool flag[N];
int main(){
	scanf("%d%d",&n,&m);int kk=n;
	for (int i=1;i<=m;i++){
		int j=i,tot=0;
		scanf("%d%d",&x,&y);
		int xx=x,yy=y;
		while (j){
			a[++tot]=j%10;
			j/=10;
		}
		int now;
		for (int j=tot;j>1;j--){
			now=++n;
			G[x].pb(mp(a[j],now));
			x=now;
		}
		G[x].pb(mp(a[1],y));
		for (int j=tot;j>1;j--){
			now=++n;
			G[y].pb(mp(a[j],now));
			y=now;
		}
		G[y].pb(mp(a[1],xx));
	}
	for (int i=1;i<=n;i++)sort(G[i].begin(),G[i].end());
	Q[1]=flag[1]=1;
	to[1]=1;
	int l=1,r=1;
	while (l<=r){
		int L=l,R=to[l];l=to[l]+1;
		for (int i=0;i<10;i++){
			int p=r+1;
			for (int j=L;j<=R;j++){
				while (now[Q[j]]!=G[Q[j]].size()&&G[Q[j]][now[Q[j]]].fi==i){
					if (flag[G[Q[j]][now[Q[j]]].se]){
						now[Q[j]]++;
						continue;
					}
					int v=G[Q[j]][now[Q[j]]].se;
					flag[v]=1;
					Ans[v]=((ll)Ans[Q[j]]*10+i)%M;
					Q[++r]=v;
					now[Q[j]]++;
				}
			}
			if (p<=r)to[p]=r;
		}
	}
	for (int i=2;i<=kk;i++)printf("%d\n",Ans[i]);
	return 0;
}