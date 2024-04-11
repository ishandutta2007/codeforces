#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
#define poly vector<ll>
#define mem(a) memset(a,0,sizeof(a))
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
const int N=205,NN=2*N,MM=400005,inf=1e9;
int n,m,qlt,ti,ne,top;
int dfn[NN],low[NN],to[NN],zhan[NN],zh[NN],son[NN];
int ed[MM],nxt[MM];
char ans[N];
inline int yi(int x){return (x&1)?x+1:x-1;}
void ae(int a,int b){
	nxt[++ne]=son[a]; son[a]=ne; ed[ne]=b;
}
void ins(int a,int b){
	ae(a,b); ae(yi(b),yi(a)); //cout<<a<<" "<<b<<endl;
}
void dfs(int p){
	dfn[p]=low[p]=++ti;
	zhan[++top]=p; zh[p]=1;
	for(int i=son[p];i;i=nxt[i])if(!dfn[ed[i]]){
		dfs(ed[i]); low[p]=min(low[p],low[ed[i]]);
	}else if(zh[ed[i]])low[p]=min(low[p],dfn[ed[i]]);
	if(dfn[p]==low[p]){
		qlt++;
		while(1){
			to[zhan[top]]=qlt; zh[zhan[top]]=0;
			if(zhan[top--]==p)break;
		}
	}
}
int p[160005][2],x[160005][2],len;
int vis[300];
bool check(int qz){
	mem(son); mem(dfn);
	ti=ne=qlt=0;
	For(i,1,m){
		ins(2*p[i][0]-1+x[i][0],2*p[i][1]-1+x[i][1]);
	}
	For(i,1,qz)ins(2*i-vis[ans[i]],yi(2*i-vis[ans[i]]));
	For(i,1,2*n)if(!dfn[i])dfs(i);
	for(int i=1;i<=2*n;i+=2)if(to[i]==to[i+1])return 0;
	return 1;
}
void GG(){
	puts("-1"); exit(0);
}
void solve(int qz){
	For(j,qz+1,n){
		ans[j]='a';
		if(!check(j)){
			int f=0;
			For(k,'a'+1,'a'+len-1)if(vis[k]!=vis['a']){ans[j]=k; f=1; break;}
			if(!f)GG();
		}
	}
	cout<<(ans+1)<<endl; exit(0);
}
char ch[30],s[205];
int main(){
	scanf("%s",ch);
	len=strlen(ch);
	For(i,0,len-1)vis['a'+i]=ch[i]=='V';
	n=read(),m=read();
	For(i,1,m){
		For(j,0,1){
			p[i][j]=read(); x[i][j]=getchar()=='V';
		}
	}
	scanf("%s",s+1);
	For(i,1,n)ans[i]=s[i];
	if(!check(0)){GG(); }
	if(check(n)){
		cout<<(ans+1)<<endl; return 0;
	}
	Rep(i,n,1){
		int t=ans[i]; 
		ans[i]++; //puts("zhu"); check(2); GG();
		if(ans[i]<'a'+len&&check(i)){
			solve(i);
		}else{
			For(j,ans[i]+1,'a'+len-1)if(vis[j]!=vis[ans[i]]){
				ans[i]=j; if(check(i))solve(i); else break;
			} ans[i]=t;
		}
	}
	GG();
}
/*
VVVVCVCVVCVVVVCVCCCCCCCVCC
20 36
1 V 2 C
1 C 2 V
2 V 3 C
2 C 3 V
3 V 4 C
3 C 4 V
4 V 5 C
4 C 5 V
5 V 6 C
5 C 6 V
6 V 7 C
6 C 7 V
7 V 8 C
7 C 8 V
8 V 9 C
8 C 9 V
9 V 10 C
9 C 10 V
10 V 11 C
10 C 11 V
11 V 12 C
11 C 12 V
12 V 13 C
12 C 13 V
13 V 14 C
13 C 14 V
14 V 15 C
14 C 15 V
15 V 16 C
15 C 16 V
16 V 17 C
16 C 17 V
17 V 18 C
17 C 18 V
18 V 19 C
18 C 19 V
jcsxccsacascuasbcausa
*/