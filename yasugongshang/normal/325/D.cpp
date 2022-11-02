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
const int N=3005,x[8]={1,-1,0,0,1,1,-1,-1},y[8]={0,0,1,-1,1,-1,1,-1};
int s,t,r,c,n,ans,top,rk[N*N*2],father[N*N*2];
bitset<N*N*2> vis;
PI q[100];
inline int zb(int x,int y){
	if(x==0||x>r)return 0;
	if(y==0)y=2*c; if(y>2*c)y=1;
	return (x-1)*c*2+y;
}
inline int getfather(int x){
	return father[x]==x?x:getfather(father[x]);
}
void clear(){
	while(top){
		if(q[top].second) father[q[top].first]=q[top].second; else rk[q[top].first]--; top--;
	}
}
void Merge(int u,int v){
	if(!vis[u]||!vis[v])return;
	int s1=getfather(u),s2=getfather(v);
	if(s1==s2)return; if(rk[s1]<rk[s2])swap(s1,s2);
	q[++top]=mp(s2,father[s2]); father[s2]=s1; if(rk[s1]==rk[s2]){q[++top]=mp(s1,0); rk[s1]++;} 
}
void ins(int a,int b){
	for(int i=0;i<8;i++){
		Merge(zb(a,b),zb(a+x[i],b+y[i]));
	}
}

int main(){
	r=read(); c=read(); ans=n=read();
	for(int i=1;i<=r*c*2+2;i++)father[i]=i; s=r*c*2+1; t=s+1; 
	for(int i=1;i<=n;i++){
		int u=read(),v=read(); top=0; vis[zb(u,v)]=1; vis[zb(u,v+c)]=1;
		ins(u,v); ins(u,v+c);
		if(getfather(zb(u,v))==getfather(zb(u,v+c))){clear(); ans--; vis[zb(u,v)]=vis[zb(u,v+c)]=0;}
	}
	cout<<ans<<endl;
}