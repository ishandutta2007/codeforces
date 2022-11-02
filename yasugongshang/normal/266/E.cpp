#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
//#define int long long
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
inline int rnd(int x){
	return rand()%x;
}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=100005,mod=1000000007;
int n,m,tree[N<<2][6],lazy[N<<2],sum[6][N],a[N];
char ch[1];
inline int ksm(int a,int b){
	ll ans=1;
	for(int i=0;i<b;i++)ans=ans*a%mod;
	return ans;
}
inline int c(int a,int b){
	int ans=1;
	for(int i=a;i>a-b;i--)ans=ans*i;
	for(int i=1;i<=b;i++)ans=ans/i;
	return ans;
}
void gao(int nod,int l,int r,int de){
	for(int i=0;i<=5;i++)tree[nod][i]=(ll)(sum[i][r]-sum[i][l-1])*de%mod; lazy[nod]=de;
}
void pushdown(int nod,int l,int r){
	if(lazy[nod]!=-1){
		int mid=(l+r)>>1;
		gao(nod<<1,l,mid,lazy[nod]); gao(nod<<1|1,mid+1,r,lazy[nod]);
		lazy[nod]=-1;
	}
}
void push_up(int nod){
	for(int i=0;i<6;i++)tree[nod][i]=(tree[nod<<1][i]+tree[nod<<1|1][i])%mod;
}
void insert(int l,int r,int i,int j,int de,int nod){
	if(l==i&&r==j){
		gao(nod,l,r,de);
		return;
	}
	pushdown(nod,l,r);
	int mid=(l+r)>>1;
	if(j<=mid)insert(l,mid,i,j,de,nod<<1); else if(i>mid)insert(mid+1,r,i,j,de,nod<<1|1);
	else{
		insert(l,mid,i,mid,de,nod<<1); insert(mid+1,r,mid+1,j,de,nod<<1|1);
	}
	push_up(nod);
}
int tong[6];
void ask(int l,int r,int i,int j,int nod){
	if(l==i&&r==j){
		//cout<<l<<" "<<r<<" "<<tree[nod][0]<<endl;
		for(int i=0;i<6;i++)tong[i]=(tong[i]+tree[nod][i])%mod;
		return;
	}
	pushdown(nod,l,r);
	int mid=(l+r)>>1;
	if(j<=mid)ask(l,mid,i,j,nod<<1); else if(i>mid)ask(mid+1,r,i,j,nod<<1|1);
	else{
		ask(l,mid,i,mid,nod<<1); ask(mid+1,r,mid+1,j,nod<<1|1);
	}
}
signed main(){
	n=read(); m=read(); memset(lazy,-1,sizeof(lazy));
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=0;i<6;i++)for(int j=1;j<=n;j++)sum[i][j]=(sum[i][j-1]+ksm(j+1,i))%mod;
	for(int i=1;i<=n;i++)insert(1,n,i,i,a[i],1);
	for(int i=1;i<=m;i++){
		scanf("%s",ch);
		int l=read(),r=read(),x=read();
		if(ch[0]=='='){
			insert(1,n,l,r,x,1);
		}else{
			memset(tong,0,sizeof(tong));
			ask(1,n,l,r,1);
			//cout<<tong[0]<<endl; 
			int ans=0;
			for(int i=0;i<=x;i++)ans=(ans+(ll)tong[i]*ksm(-l,x-i)%mod*c(x,i))%mod;
			writeln((ans+mod)%mod);
		}
	}
}
/*
10 2
6 4 1 8 7 10 3 5 1 5
= 1 3 0
? 2 5 3

*/