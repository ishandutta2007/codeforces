#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int N=2005;
int fa[N],sz,n,m,quan,vis[N],vvv[N],q[N],tot,cou[N],Cou[N];
bitset<N> s[N],S[N],SS[N];
vector<int> v[N];
char ch[N];
void dfs(int p,int fa){
	sz++;
	for(auto i:v[p])if(i!=fa&&SS[quan][i])dfs(i,p);
}
void bao(int id){
	s[id].reset(); for(int i=1;i<=n;i++)if(!vis[i])s[id][i]=1;
	for(int i=1;i<=m;i++)if(S[i][id]&&!vvv[i]){s[id]&=S[i];}
	s[id][id]=0; cou[id]=s[id].count();
}
int main(){
	int T=read();
	while(T--){
		n=read(); m=read();
		memset(vis,0,sizeof(vis)); memset(fa,0,sizeof(fa)); memset(vvv,0,sizeof(vvv));
		for(int i=1;i<=m;i++){
			scanf("%s",ch+1);
			S[i].reset();
			for(int j=1;j<=n;j++)S[i][j]=ch[j]-'0'; SS[i]=S[i];
			Cou[i]=S[i].count(); if(Cou[i]==1)vvv[i]=1;
		}
		for(int i=1;i<=n;i++)bao(i);
		for(int i=1;i<n;i++){
			for(int j=1;j<=n;j++)if(!vis[j]&&cou[j]){
				fa[j]=s[j]._Find_first(); vis[j]=1;
				for(int k=1;k<=m;k++)if(S[k][j]){S[k][j]=0; Cou[k]--;}
				for(int k=1;k<=m;k++)if(vvv[k]==0&&Cou[k]==1){
					vvv[k]=1; q[++tot]=S[k]._Find_first();
				}
				while(tot)bao(q[tot--]);
				for(int k=1;k<=n;k++)if(s[k][j]){s[k][j]=0; cou[k]--;}
				break;
			}
		}
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<=n;i++)if(fa[i]){v[i].push_back(fa[i]); v[fa[i]].push_back(i);}
		int flag=2;
		for(int i=1;i<=n;i++)if(!vis[i])flag--;
		if(flag!=1){
			puts("NO"); continue;
		}
		if(flag){
			puts("YES");
			for(int i=1;i<=n;i++)if(fa[i]){
				wri(i); writeln(fa[i]);
			}
		}else puts("NO");
	}
}