//Coded by tzc_wk
/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
const unsigned long long HSB=571;
map<unsigned long long,int> used;
int k=0,a[100005],b[100005];
inline int deal(string s){
	unsigned long long hs=0;
	int num=0;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]<='Z')	s[i]+=1<<5;
		hs=hs*HSB+s[i];
		if(s[i]=='r')	num++;
	}
	if(!used[hs])	used[hs]=++k,a[k]=num,b[k]=s.size();
	return used[hs];
}
int n=read(),m,p[100005];
vector<int> g[100005],ng[100005];
int low[100005],dfn[100005],stk[100005],top=0,idx=0;
bool vis[100005];
int from[100005],comp=0;
int mn1[100005],mn2[100005];
inline void tarjan(int x){
	low[x]=dfn[x]=++idx;
	stk[++top]=x;vis[x]=1;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y]){
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(dfn[x]==low[x]){
		comp++;
		while(top){
			int y=stk[top];top--;
			from[y]=comp;
			vis[y]=0;
			if(x==y)	break;
		}
	}
}
inline void dfs(int x){
//	cout<<x<<" "<<mn1[x]<<" "<<mn2[x]<<endl;
	vis[x]=1;
	for(int i=0;i<ng[x].size();i++){
		int y=ng[x][i];
		if(!vis[y])	dfs(y);
		if(mn1[y]<mn1[x]){
			mn1[x]=mn1[y];
			mn2[x]=mn2[y];
		}
		else if(mn1[y]==mn1[x]){
			mn2[x]=min(mn2[x],mn2[y]);
		}
	}
}
signed main(){
	fz(i,1,n){
		string s;cin>>s;
		p[i]=deal(s);
	}
	m=read();
	fz(i,1,m){
		string s,t;cin>>s>>t;
		int u=deal(s),v=deal(t);
		g[u].push_back(v);
	}
	fillbig(mn1);fillbig(mn2);
	fz(i,1,k){
//		cout<<a[i]<<" "<<b[i]<<endl;
		if(!dfn[i]){
			tarjan(i);
		}
	}
	fz(i,1,k){
		if(mn1[from[i]]>a[i])
			mn1[from[i]]=a[i],
			mn2[from[i]]=b[i];
		else if(mn1[from[i]]==a[i])
			mn2[from[i]]=min(mn2[from[i]],b[i]);
	}
	fz(i,1,k){
		foreach(it,g[i]){
			if(from[i]!=from[*it]){
				ng[from[i]].push_back(from[*it]);
			}
		}
	}
	fill0(vis);
	fz(i,1,comp){
//		cout<<mn1[i]<<" "<<mn2[i]<<endl;
//		for(int j=0;j<ng[i].size();j++)	cout<<i<<" "<<ng[i][j]<<endl;
		if(!vis[i])	dfs(i);
	}
	int ans1=0,ans2=0;
	fz(i,1,n)	ans1+=mn1[from[p[i]]],ans2+=mn2[from[p[i]]];
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}