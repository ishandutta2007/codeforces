#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define ull unsigned long long
#define mp make_pair
#define ld double
#define fi first
#define se second
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
const int N=1005,inf=1e9;
priority_queue<PI > q;
ld dis[N],sum[N],dq[N],d[N][N];
bool vis[N];
int main(){
	int n=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)d[i][j]=(ld)read()/100;
		if(i<n)dis[i]=inf; dq[i]=1;
	}
	while(1){
		int k=0;
		for(int i=1;i<=n;i++)if(!vis[i]&&(!k||dis[i]<dis[k]))k=i;
		if(!k||dis[k]==inf)break; vis[k]=1;
		for(int i=1;i<=n;i++)if(!vis[i]){
			sum[i]+=dq[i]*d[i][k]*dis[k]; dq[i]*=(1-d[i][k]);
			dis[i]=min(dis[i],(sum[i]+1)/(1-dq[i]));
		}
	}
	printf("%.8f\n",dis[1]);
}
/*
dq[i]=\prod (1-p)

*/