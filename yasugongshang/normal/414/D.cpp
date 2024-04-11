#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
#define ld long double
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
const int N=100005;
int dep[N],n,k,p,tong[N];
ll sum[N];
vector<int> v[N];
void dfs(int p,int fa){
	dep[p]=dep[fa]+1;
	for(auto i:v[p])if(i!=fa){
		dfs(i,p);
	}
}
bool check(int x){
	for(int i=1;i<=n&&tong[i];i++)if(tong[i]>x){
		if((ll)x*i-(sum[tong[i]]-sum[tong[i]-x])<=p)return 1;
	}
	return 0;
}
int main(){
	n=read(); k=read(); p=read();
	for(int i=1;i<n;i++){
		int s=read(),t=read();
		v[s].push_back(t); v[t].push_back(s);
	}
	dfs(1,0);
	sort(&dep[2],&dep[n+1]);
	for(int i=1;i<=n;i++){sum[i]=sum[i-1]+dep[i]; tong[dep[i]]=i;}
	int l=0,r=k;
	while(l<r){
		int mid=(l+r)>>1; mid++;
		if(check(mid))l=mid; else r=mid-1;
	}
	cout<<l<<endl;
}