#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
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
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=205,inf=1000000005;
int n,m,f[N][N],e[N][N];
double ans=inf;
pair<double,int> q[N];
int check(int u,int v,double x,double y){
	double l=y,r=0; int t=0,sum=0;
	for(int i=1;i<=n;i++){
		double ll=x-f[u][i],rr=y-(x-f[v][i]);
		if(ll>rr)continue;
		//cout<<ll<<" "<<rr<<endl;
		q[++t]=mp(ll,1); q[++t]=mp(rr,-1);
	}
	q[++t]=mp(0,0); q[++t]=mp(y,0);
	sort(&q[1],&q[t+1]);
	for(int i=1;i<=t;i++){
		sum+=q[i].second; if(q[i].first>=0&&q[i].first<=y&&sum==0)return 1;
	}
	return 0;
}
int main(){
	n=read(); m=read();
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)f[i][j]=f[j][i]=inf;
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		f[u][v]=f[v][u]=e[u][v]=min(f[u][v],(int)read());
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	//for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cout<<i<<" "<<j<<" "<<e[i][j]<<endl;
	//cout<<f[1][3]<<" "<<f[1][1]<<" "<<f[1][2]<<" "<<f[2][3]<<" "<<f[2][1]<<" "<<f[2][2]<<endl;
	//cout<<check(1,2,59.6046,100)<<endl; return 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(e[i][j]){
			double l=0,r=1e9;
			if(!check(i,j,ans-0.4,e[i][j]))continue;
			for(int k=1;k<=40&&l<ans;k++){
				double mid=(l+r)/2;
				if(check(i,j,mid,e[i][j]))r=mid; else l=mid;
				//if(i==1&&j==2)cout<<l<<" "<<r<<" "<<mid<<" "<<check(i,j,mid,e[i][j])<<endl;
			}
			//if(i==2&&j==1)cout<<l<<endl;
			ans=min(ans,l);
		}
	}
	printf("%.2lf\n",(double)ans);
}
/*
40.5 8.5
5 20
4 2 38
3 5 50
2 5 27
4 4 100
2 1 49
4 1 85
3 2 48
2 2 30
3 5 61
2 4 100
2 3 32
2 4 14
2 3 47
3 1 99
4 4 50
1 3 27
4 4 56
4 3 34
4 2 91
4 5 41

*/