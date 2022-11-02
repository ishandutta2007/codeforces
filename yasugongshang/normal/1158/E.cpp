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
const int LL=10,L=1<<LL,N=1100;
vector<int> f[N],g[N];
int n,ans[N],cx[N];
char res[N];
void ask(){
	putchar('?'); For(i,1,n){putchar(' '); write(min(cx[i],n-1)); } cout<<endl;
	scanf("%s",res+1);
	memset(cx,0,sizeof(cx));
}
int main(){
	n=read();
	f[0].pb(1); For(i,2,n)g[0].pb(i); 
	for(int len=L;len>2;len>>=1){
		for(int j=0;j<L;j+=2*len){
			for(auto k:f[j])cx[k]=len/2-1;
		}
		ask();
		for(int j=0;j<L;j+=2*len){
			vector<int> zs;
			for(auto k:g[j])if(res[k]=='1')zs.pb(k); else g[j+len/2].pb(k);
			swap(g[j],zs);
		}
		for(int j=len;j<L;j+=2*len){
			for(auto k:f[j])cx[k]=len/2-1;
		}
		ask();
		for(int j=len;j<L;j+=2*len){
			vector<int> zs;
			for(auto k:g[j])if(res[k]=='1')zs.pb(k); else g[j+len/2].pb(k);
			swap(g[j],zs);
		}
		for(int j=0;j<L;j+=len){
			for(auto k:g[j])cx[k]=1;
		}
		ask();
		for(int j=len/2;j<L;j+=len){
			vector<int> zs;
			for(auto k:g[j])if(res[k]=='0')zs.pb(k); else f[j].pb(k);
			swap(g[j],zs);
		}
	}
	for(int i=0;i<L;i+=2)swap(f[i+1],g[i]);
	/*For(i,0,L-1){
		cout<<i<<" "; for(auto j:f[i])wri(j); puts("");
	}*/
	for(int i=0;i<LL;i++){
		For(o,0,2){
			for(int j=o;j<L;j+=3){
				For(k,0,f[j].size()-1)if(k>>i&1)cx[f[j][k]]=1;
			}
			ask();
			for(int j=o+1;j<L;j+=3)for(auto k:f[j])if(res[k]=='1')ans[k]|=1<<i;
		}
	}
	puts("!");
	For(i,1,L-1){
		for(auto j:f[i]){
			wri(j); writeln(f[i-1][ans[j]]);
		}
	}
	fflush(stdout);
}
/*
01111
00000
11111
00011
00000
11100
00000

*/