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
int n=read(),m=read();
vector<vector<int> > a;
vector<int> g[200005];
int vis[200005];
vector<int> ans;
inline void dfs(int x){
	vis[x]=1;
	foreach(it,g[x]){
		if(vis[*it]==1)	puts("-1"),exit(0);
		if(vis[*it]==0)	dfs(*it);
	}
	vis[x]=2;
	if(x<=m)	ans.push_back(x);
}
signed main(){
	a.resize(n+1);
	fz(i,1,n)	a[i].resize(m+1);
	fz(i,1,n)	fz(j,1,m)	a[i][j]=read();
	int cur=m; 
	for(int i=1;i<=n;i++){
		vector<pii> t;
		fz(j,1,m)	if(~a[i][j])	t.push_back(pii(a[i][j],j));
		sort(t.begin(),t.end());
		for(int i=0;i<t.size();i++){
			if(i==0||t[i-1].fi!=t[i].fi)	cur++;
			g[cur].push_back(t[i].se);
			g[t[i].se].push_back(cur+1);
		}
		cur++;
	}
	fz(i,1,cur)	if(!vis[i])	dfs(i);
	reverse(all(ans));
	foreach(it,ans)	cout<<*it<<" ";
	return 0;
}