#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
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
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=755,M=10000005;
int n,tot=1,lef[N],match[N],bj[M],fail[M],ch[M][2],sum,q[M];
bool vis[N<<1];
string s[N];
bitset<N> e[N];
void build(){
	int r=1; q[1]=1;
	For(i,0,1)ch[0][i]=1;
	for(int i=1;i<=r;i++){
		int t=q[i]; if(bj[fail[t]]){if(bj[t])e[bj[t]][bj[fail[t]]]=1; else bj[t]=bj[fail[t]];}
		For(j,0,1)if(ch[t][j]){
			q[++r]=ch[t][j]; fail[ch[t][j]]=ch[fail[t]][j];
		}else{
			ch[t][j]=ch[fail[t]][j];
		}
	}
}
int dfs(int p){
	For(i,1,n)if(e[p][i]&&!vis[i]){
		vis[i]=1; 
		if(!match[i]||dfs(match[i])){
			match[i]=p; return 1;
		}
	}
	return 0;
}
void ddd(int p){
	if(vis[p])return;
	vis[p]=1;
	For(i,1,n)if(e[p][i]&&match[i]!=p){vis[i+n]=1; ddd(match[i]);}
}
int main(){
	n=read();
	For(i,1,n){
		cin>>s[i];
		int len=s[i].length(),p=1;
		For(j,0,len-1){
			int t=s[i][j]-'a';
			if(!ch[p][t])ch[p][t]=++tot;
			p=ch[p][t];
		}
		bj[p]=i; 
	}
	build();
	For(i,1,n){
		int len=s[i].length(),p=1;
		For(j,0,len-1){
			if(bj[p])e[i][bj[p]]=1;
			int t=s[i][j]-'a';
			p=ch[p][t];
		}
	}
	For(k,1,n)For(i,1,n)if(e[i][k])e[i]|=e[k];
	vector<int> ans;
	For(i,1,n){
		lef[i]=dfs(i);
		memset(vis,0,sizeof(vis));
	}
	For(i,1,n)if(!lef[i])ddd(i);
	For(i,1,n)if(vis[i]&&!vis[i+n])ans.pb(i);
	writeln(ans.size());
	for(auto i:ans)wri(i); puts("");
}