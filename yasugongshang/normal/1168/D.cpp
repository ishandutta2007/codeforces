#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<int,int>
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
const int N=150005,K=26;
vector<int> v[N];
int zs[N],fa[N],lst[N],dep[N],cnt,mxdep;
char ch[N];
void in(int nod,int x){
	if(x==1){
		if(++zs[nod]==mxdep-dep[nod]+1)cnt++;
	}else{
		if(--zs[nod]==mxdep-dep[nod])cnt--;
	}
}
struct data{
	int mx[N],s[N];
	bool push_up(int nod){
		if(mx[nod]!=max(mx[v[nod][0]],mx[v[nod][1]])+s[nod]){
			mx[nod]=max(mx[v[nod][0]],mx[v[nod][1]])+s[nod]; return 1;
		}else return 0;
	}
	void ins(int pos,int de){
		mx[pos]+=de; s[pos]+=de;
		while(pos>1){
			if(v[fa[pos]].size()==2){if(!push_up(fa[pos]))return; in(fa[pos],de);}
			else mx[lst[fa[pos]]]+=de; pos=lst[fa[pos]];
		}
	}
}T[K];
void dfs(int p){
	if(v[p].size()==2)lst[p]=p;
	else lst[p]=v[fa[p]].size()!=1?p:lst[fa[p]];
	for(auto i:v[p]){dep[i]=dep[p]+1; dfs(i);}
}
int main(){
	int n=read(),q=read(); mxdep=0;
	For(i,2,n){v[fa[i]=read()].pb(i); ch[i]=getchar();}
	dfs(1);
	For(i,2,n)if(v[i].size()==0){
		if(!mxdep)mxdep=dep[i];
		else if(dep[i]!=mxdep){
			while(q--)puts("Fou"); return 0;
		}
	}
	For(i,2,n)if(ch[i]!='?')T[ch[i]-'a'].ins(lst[i],1);
	while(q--){
		int pos=read(),sum=mxdep,ans=0;
		if(ch[pos]!='?')T[ch[pos]-'a'].ins(lst[pos],-1);
		ch[pos]=getchar(); 
		if(ch[pos]!='?')T[ch[pos]-'a'].ins(lst[pos],1);
		if(cnt){puts("Fou"); continue;}
		For(i,0,25)sum-=T[i].mx[1]; //cout<<mxdep<<" "<<sum<<" fjzz"<<endl;
		For(i,0,25)ans+=(sum+T[i].mx[1])*(i+1);
		printf("Shi "); writeln(ans);
	}
}