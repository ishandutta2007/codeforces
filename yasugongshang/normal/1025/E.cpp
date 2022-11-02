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
const int N=55;
int n,m,x[N],y[N],a[N][N],tong[N];
vector<pair<PI,PI> > ans,v1,v2;
void print(vector<pair<PI,PI> > v){
	for(auto i:v){
		cout<<i.first.first<<" "<<i.first.second<<" "<<i.second.first<<" "<<i.second.second<<endl;
	}
}
void insert(int sx,int sy,int tx,int ty){
	swap(a[sx][sy],a[tx][ty]);
	ans.push_back(mp(mp(sx,sy),mp(tx,ty)));
}
void solve(int id){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(a[i][j]==id){
			if(tong[id]==i)return;
			if(tong[id]>i){
				if(a[i+1][j])solve(a[i+1][j]);
				insert(i,j,i+1,j);
				solve(id);
			}else{
				if(a[i-1][j])solve(a[i-1][j]);
				insert(i,j,i-1,j);
				solve(id);
			}
			return;
		}
	}
}
void calc(){
	memset(a,0,sizeof(a));
	for(int i=1;i<=m;i++)a[x[i]][y[i]]=i;
	int tot=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(a[i][j])tong[a[i][j]]=++tot;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(a[i][j])solve(a[i][j]);
	}
	/*for(int i=1;i<=n;i++){puts("");
		for(int j=1;j<=n;j++)cout<<a[i][j]<<" "; puts("");
	}*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(a[i][j]){
			int t=a[i][j];
			if(j>t)for(int k=j;k>t;k--)insert(i,k,i,k-1);
			else for(int k=j;k<t;k++)insert(i,k,i,k+1);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(a[i][j]){
			if(i<j)for(int k=i;k<j;k++)insert(k,j,k+1,j);
			else for(int k=i;k>j;k--)insert(k,j,k-1,j);
		}
	}
}
signed main(){
	n=read(); m=read();
	for(int i=1;i<=m;i++){
		x[i]=read(); y[i]=read();
	}
	calc(); v1=ans; ans.clear();
	for(int i=1;i<=m;i++){
		x[i]=read(); y[i]=read();
	}
	calc(); v2=ans;
	reverse(v2.begin(),v2.end());
	for(auto &i:v2)swap(i.first,i.second);
	cout<<v1.size()+v2.size()<<endl;
	print(v1); print(v2);
}
/*
(n*d(n)*logn)*log
2e5*1000*logn*logn1
*/