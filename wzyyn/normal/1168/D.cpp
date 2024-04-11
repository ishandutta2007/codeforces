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
char s[10];
const int N=150005;
int n,Q,lf[N],dep[N];
int v[N],spe[N],fa[N];
int fav[N][30],ndv[N][30];
int rest[N],Fa[N];
int ls[N],rs[N],GGcnt;
vector<int> e[N];
void GG(){
	while (Q--) puts("Fou");
}
void dfs1(int x){
	if (!spe[x]){
		assert(e[x].size()==1);
		dfs1(e[x][0]);
		spe[x]=spe[e[x][0]];
	}
	else{
		if (e[x].size()>=1){
			dfs1(e[x][0]);
			ls[x]=spe[e[x][0]];
			Fa[spe[e[x][0]]]=x;
		}
		if (e[x].size()>=2){
			dfs1(e[x][1]);
			rs[x]=spe[e[x][1]];
			Fa[spe[e[x][1]]]=x;
		}
		rest[x]=dep[n]-dep[x];
		For(i,0,25){
			ndv[x][i]=max(ndv[ls[x]][i]+fav[ls[x]][i],
						  ndv[rs[x]][i]+fav[rs[x]][i]);
			rest[x]-=ndv[x][i];
		}
		if (rest[x]<0) ++GGcnt;
	}
	if (v[x]!=-1)
		fav[spe[x]][v[x]]++;
}
void modify(int x,int val,int v){
	if (val==-1) return;
	x=spe[x]; fav[x][val]+=v;
	for (x=Fa[x];x;x=Fa[x]){
		if (rest[x]<0) --GGcnt;
		rest[x]+=ndv[x][val];
		ndv[x][val]=max(ndv[ls[x]][val]+fav[ls[x]][val],
						ndv[rs[x]][val]+fav[rs[x]][val]);
		rest[x]-=ndv[x][val];
		if (rest[x]<0) ++GGcnt;
	}
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) lf[i]=1;
	For(i,2,n){
		scanf("%d%s",&fa[i],s);
		lf[fa[i]]=0; v[i]=(s[0]=='?'?-1:s[0]-'a');
		dep[i]=dep[fa[i]]+1;
		e[fa[i]].PB(i);
	}
	For(i,1,n)
		if (lf[i]&&dep[i]!=dep[n])
			return GG(),0;
	For(i,1,n)
		if (lf[i]||e[i].size()==2||i==1)	
			spe[i]=i;
	dfs1(1);
	while (Q--){
		int x;
		scanf("%d%s",&x,s);
		modify(x,v[x],-1);
		v[x]=(s[0]=='?'?-1:s[0]-'a');
		modify(x,v[x],1);
		if (GGcnt) puts("Fou");
		else{
			int ans=0;
			For(i,0,25)
				ans+=(i+1)*(ndv[1][i]+rest[1]);
			printf("Shi %d\n",ans);
		}
	}
}