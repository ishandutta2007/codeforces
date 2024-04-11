#include <bits/stdc++.h>
using namespace std;
#define ll long long
void ckmn(ll&x,ll y){x=min(x,y);}
const int A=55;
const ll inf=4e18;
int go[A][2],link[A],leaf[A],root,tsz;
void Add(int&c,int s[],int n){
	if(!c)c=++tsz;
	if(n==0){leaf[c]=1;return;}
	Add(go[c][s[0]],s+1,n-1);
}
void Build(){
	queue<int> q;
	link[root]=root;
	for(int i=0;i<2;i++){
		if(go[root][i]){
			link[go[root][i]]=root;
			q.push(go[root][i]);
		}else go[root][i]=root;
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		leaf[u]|=leaf[link[u]];
		for(int i=0;i<2;i++){
			if(go[u][i])link[go[u][i]]=go[link[u]][i],q.push(go[u][i]);
			else go[u][i]=go[link[u]][i];
		}
	}
}
const int N=105;
int b[N][N],a[N],sz[N],s[A];
ll dp[N][A][A],tmp[A],nxt[A];
bool fl1[N],fl2[N];
int main(){
	root=++tsz;
	int g,n,m;
	scanf("%i %i %i",&g,&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%i %i",&a[i],&sz[i]);
		for(int j=1;j<=sz[i];++j)scanf("%i",&b[i][j]);
	}
	for(int i=1,l;i<=m;++i){
		scanf("%i",&l);
		for(int j=0;j<l;++j)scanf("%i",&s[j]);
		Add(root,s,l);
	}
	Build();
	for(int k=0;k<g;++k)for(int i=1;i<=tsz;++i)for(int j=1;j<=tsz;++j)dp[k][i][j]=inf;
	for(int i=1;i<=tsz;++i){
		if(!leaf[go[i][0]])dp[0][i][go[i][0]]=1;
		if(!leaf[go[i][1]])dp[1][i][go[i][1]]=1;
	}
	fl1[0]=fl1[1]=1;
	while(1){
		bool ok=0;
		for(int i=0;i<g;++i)fl2[i]=0;
		for(int i=1;i<=n;++i){
			bool has=0;
			for(int j=1;j<=sz[i];++j)if(fl1[b[i][j]]&&!fl2[b[i][j]])has=1;
			if(!has)continue;
			for(int st=1;st<=tsz;++st){
				for(int j=1;j<=tsz;++j)tmp[j]=inf;
				tmp[st]=0;
				for(int j=1;j<=sz[i];++j){
					for(int k=1;k<=tsz;++k)nxt[k]=inf;
					for(int k=1;k<=tsz;++k){
						for(int ed=1;ed<=tsz;++ed){
							ckmn(nxt[ed],tmp[k]+dp[b[i][j]][k][ed]);
						}
					}
					for(int k=1;k<=tsz;++k)tmp[k]=nxt[k];
				}
				for(int j=1;j<=tsz;++j)if(dp[a[i]][st][j]>tmp[j]){
					dp[a[i]][st][j]=tmp[j];
					fl2[a[i]]=1;
					ok=1;
				}
			}
		}
		if(!ok)break;
		for(int i=0;i<g;++i)fl1[i]=fl2[i];
	}
	for(int i=2;i<g;++i){
		ll ans=inf;
		for(int ed=1;ed<=tsz;++ed)ans=min(ans,dp[i][root][ed]);
		if(ans==inf)printf("YES\n");
		else printf("NO %lld\n",ans);
	}
	return 0;
}