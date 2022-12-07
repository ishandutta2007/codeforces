#include<bits/stdc++.h>

using namespace std;

const int N=200005;
char s[N];
int n,k,T,Q;
int fin[26],pas[26],vis[N];
pair<int,int> p[N][55];
long long dep[N],vit[N][26];
vector<pair<int,int> > e[N];

void dfs(int x,int fa){
	int loc=lower_bound(p[x],p[x]+s[x],pair<int,int>((dep[x]+T-1)%T+1,-1))-p[x];
	vis[x]|=1<<loc;
	for (auto i:e[x])
		if (i.first!=fa){
			dep[i.first]=dep[x]+i.second;
			for (int j=0;j<k;j++) vit[i.first][j]=(j<s[i.first]?vit[x][j]:dep[i.first]);
			if (s[i.first]==s[x]){
				for (int j=0;j<s[x];j++)
					p[i.first][j]=p[x][j];
			}
			else{
				for (int j=0;j<s[i.first];j++)
					p[i.first][j]=pair<int,int>(vit[x][j]%T,j);
				sort(p[i.first],p[i.first]+s[i.first]); 
			}
			dfs(i.first,x);
			if (s[i.first]==s[x])
				vis[x]|=vis[i.first];
		}
}

long long tms[26];
long long F(int x){
	if (!fin[x]||tms[x]<=0) return 0;
	if (tms[x]<=pas[x]/fin[x]) return tms[x]*fin[x];
	return pas[x];
}
void query(){
	int x;
	scanf("%d",&x);
	if (!s[x]) return puts("0"),void(0);
	for (int i=0;i<s[x];i++)
		tms[i]=vit[x][i]/T+1;
	for (int i=s[x]-1;i>=1;i--)
		tms[i]-=tms[i-1];
	long long sum=0;
	for (int i=0;i<s[x];i++)
		sum+=F(i);
	//cout<<sum<<' '<<x<<' '<<vis[x]<<' '<<(int)s[x]<<endl;
	long long ans=(vis[x]&1?sum:1ll<<60);
	for (int i=0;i<s[x];i++){
		int p=::p[x][i].second;
		sum-=F(p); --tms[p]; sum+=F(p);
		if ((++p)<s[x]){
			sum-=F(p); ++tms[p]; sum+=F(p);
		}
		if (vis[x]&(2ll<<i))
			ans=min(ans,sum);
	}
	printf("%lld\n",ans);
}
int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
	#endif
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		e[x].push_back(pair<int,int>(y,v));
		e[y].push_back(pair<int,int>(x,v));
	}
	scanf("%d",&k);
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
		s[i]-='A';
	for (int i=0;i<k;i++)
		scanf("%d",&pas[i]);
	for (int i=0;i<k;i++)
		scanf("%d",&fin[i]);
	scanf("%d",&T);
	dfs(1,0);
	scanf("%d",&Q);
	while (Q--){
		int tp;
		scanf("%d",&tp);
		if (tp==1){
			char s[10];
			scanf("%s",s+1);
			scanf("%d",&pas[s[1]-'A']);
		}
		if (tp==2){
			char s[10];
			scanf("%s",s+1);
			scanf("%d",&fin[s[1]-'A']);
		}
		if (tp==3)
			query();
	}
}