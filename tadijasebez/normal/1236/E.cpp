#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=100050;
const int L=17;
int a[N],b[N],n,m;
ll ans;
vector<int> Us[N];
int par[N][L],tsz,pos[N][L];
void Solve(){
	tsz=0;
	for(int i=1;i<=n;i++)Us[i].clear();
	for(int i=1;i<=m;i++)b[i]=i-a[i],Us[a[i]].pb(b[i]);
	map<int,int> las;
	for(int i=n;i>=1;i--){
		sort(Us[i].rbegin(),Us[i].rend());
		for(int x:Us[i]){
			++tsz;
			par[tsz][0]=las.count(x+1)?las[x+1]:0;
			pos[tsz][0]=i;
			for(int j=1;j<L;j++)
				par[tsz][j]=par[par[tsz][j-1]][j-1],
				pos[tsz][j]=pos[par[tsz][j-1]][j-1];
			las[x]=tsz;
			//printf("%i %i\n",i,x);
		}
		int u=las[-i],cnt=0;
		for(int j=L-1;~j;j--){
			if(pos[u][j]==0)continue;
			if(pos[u][j]-i+cnt+(1<<j)<=m+1){
				cnt+=1<<j;
				u=par[u][j];
			}
		}
		//printf("ans:%i %i\n",i,min(m+1-cnt,n-i));
		ans+=min(m+1-cnt,n-i);
	}
	//printf("\n");
}
int main(){
	scanf("%i %i",&n,&m);
	for(int i=1;i<=m;i++)scanf("%i",&a[i]);
	if(n==1)return 0*printf("0\n");
	Solve();
	for(int i=1;i<=m;i++)a[i]=n-a[i]+1;
	Solve();
	ans+=n;
	printf("%lld\n",ans);
	return 0;
}