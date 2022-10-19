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
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
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
char s[2005];
bool mp[30][30];
int vis[30];
int ans[30],cnt=0,found=1;
vector<int> g[30];
inline void dfs(int x,int prev){
	if(vis[x]){
		found=0;
		return;
	}
	vis[x]=1;
	ans[++cnt]=x;
	foreach(it,g[x])	if(*it!=prev)	dfs(*it,x);
}
inline void solve(){
	memset(mp,0,sizeof(mp));
	fz(i,0,25)	g[i].clear();
	cnt=0;memset(ans,0,sizeof(ans));
	memset(vis,0,sizeof(vis));found=1;
	cin>>s+1;
	int n=strlen(s+1);
	for(int i=1;i<n;i++){
		mp[s[i]-'a'][s[i+1]-'a']=mp[s[i+1]-'a'][s[i]-'a']=1;
	}
	fz(i,0,25){
		fz(j,0,25){
			if(mp[i][j])	g[i].push_back(j);
		}
	}
	fz(i,0,25){
		if(g[i].size()<=1&&!vis[i])	dfs(i,-1);
		else if(g[i].size()>=3){
			puts("NO");
			return;
		}
	}
	if(!found||cnt!=26){
		puts("NO");
		return;
	}
	puts("YES");
	for(int i=1;i<=cnt;i++)	putchar(ans[i]+'a');eoln;
}
signed main(){
	int T=read();
	while(T--)	solve();
	return 0;
}