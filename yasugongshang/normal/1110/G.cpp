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
const int N=2000005;
int f,yk,yp;
char ch[N];
vector<int> v[N];
void ins(int s,int t){
	v[s].push_back(t); v[t].push_back(s);
}
void dfs(int p,int fa,int dep){
	int sz=0;
	if(v[p].size()>3)f=1;
	for(auto i:v[p])sz+=v[i].size()>1;
	if(v[p].size()==3&&sz>=2)f=1;
	if(v[p].size()==3){yk+=dep; yp++;}
	for(auto i:v[p])if(i!=fa){
		dfs(i,p,dep+1);
	}
}
int main(){
	int T=read();
	while(T--){
		int n=read(),tot=n; f=yp=yk=0;
		for(int i=1;i<n;i++){
			int s=read(),t=read();
			ins(s,t);
		}
		scanf("%s",ch+1);
		for(int i=1;i<=n;i++)if(ch[i]=='W'){
			ins(i,++tot); tot++; ins(tot,tot-1); tot++; ins(tot,tot-2);
		}
		dfs(1,0,0);
		if(f||(yp==2&&yk%2==0))puts("White"); else puts("Draw");
		for(int i=1;i<=tot;i++)v[i].clear();
	}
}
/*
ak
 
>3
<3 
*/