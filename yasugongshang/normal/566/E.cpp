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
const int N=1005;
bool vis[N];
bitset<N> s[N],xl[N],zs;
set<PI> S;
int main(){
	int n=read();
	For(i,1,n){
		int k=read();
		while(k--)s[i][read()]=1;
	}
	For(i,1,n)For(j,i+1,n){
		zs=s[i]&s[j];
		if(zs.count()==2){
			vector<int> v;
			For(j,1,n)if(zs[j])v.pb(j);
			S.insert(mp(v[0],v[1]));
		}
	}
	for(auto i:S){wri(i.fi); writeln(i.se); vis[i.fi]=vis[i.se]=1;} 
	if(!S.size()){
		For(i,2,n){
			wri(1); writeln(i); 
		}
		return 0;
	}else if(S.size()==1){
		For(i,1,n)if(s[i].count()!=n){
			For(j,1,n)if(!vis[j]){wri(j); writeln(s[i][j]?S.begin()->fi:S.begin()->se);}
			return 0;
		}
		For(i,1,n)if(!vis[i]){wri(i); writeln(S.begin()->fi);}
	}else{
		for(auto i:S)xl[i.fi][i.se]=xl[i.se][i.fi]=1;
		For(i,1,n)if(vis[i])xl[i][i]=1;
		For(i,1,n)if(!vis[i]){
			bitset<N> jb;
			int k=0;
			For(j,1,n)if(s[j][i]&&(!k||s[j].count()<s[k].count()))k=j;
			For(j,1,n)if(vis[j]&&s[k][j])jb[j]=1;
			For(j,1,n)if(jb==xl[j]){
				wri(j); writeln(i); break;
			}
		}
	}
}
/*
6
5 1 2 3 4 5
6 1 2 3 4 5 6
5 1 2 3 5 6
4 1 2 3 5
3 2 3 6
3 1 2 4

1 2
2 3
1 4
2 5
3 6


*/