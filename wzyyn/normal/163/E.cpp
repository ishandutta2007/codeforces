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
using namespace std;
const int N=1000005;
int ch[N][26],fa[N],a[N],q[N],val[N];
int dfn[N],ed[N],pos[N],n,k,nd=1;
vector<int> e[N];
char s[N];
void dfs(int x){
	dfn[x]=++*dfn;
	for (auto i:e[x]) dfs(i);
	ed[x]=*dfn;
}
void build_tr(){
	int h=0,t=0;
	For(i,0,25)
		if (!ch[1][i]) ch[1][i]=1;
		else{
			fa[ch[1][i]]=1;
			q[++t]=ch[1][i];
		}
	while (h!=t){
		//cout<<h<<' '<<t<<endl;
		int x=q[++h];
		For(i,0,25)
			if (!ch[x][i])
				ch[x][i]=ch[fa[x]][i];
			else{
				q[++t]=ch[x][i];
				fa[ch[x][i]]=ch[fa[x]][i];
			}
	}
	For(i,2,nd) e[fa[i]].PB(i);
	dfs(1);
}
void change(int x,int v){
	for (;x<=nd;x+=x&(-x)) a[x]+=v;
}
int ask(int x){
	int ans=0;
	for (;x;x-=x&(-x)) ans+=a[x];
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,k){
		scanf("%s",s+1);
		int len=strlen(s+1);
		int x=1;
		For(j,1,len){
			int c=s[j]-'a';
			if (!ch[x][c])
				ch[x][c]=++nd;
			x=ch[x][c];
		}
		pos[i]=x;
		val[i]=1;
	}
	build_tr();
	For(i,1,k){
		change(dfn[pos[i]],1);
		change(ed[pos[i]]+1,-1);
	}
	For(i,1,n){
		scanf("%s",s+1);
		int len=strlen(s+1);
		if (s[1]=='+'||s[1]=='-'){
			int x=0,v=(s[1]=='+'?1:-1);
			For(j,2,len) x=x*10+s[j]-'0';	
			if (val[x]+v<0||val[x]+v>1) v=0;
			change(dfn[pos[x]],v);
			change(ed[pos[x]]+1,-v);
			val[x]+=v;
		}
		else{
			int x=1;
			ll ans=0;
			For(i,2,len){
				x=ch[x][s[i]-'a'];
				ans+=ask(dfn[x]);
			}
			printf("%lld\n",ans);
		}
	} 
}