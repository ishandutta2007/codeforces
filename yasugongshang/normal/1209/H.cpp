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
const int N=400005,M=1<<20|2;
ld ans,s[N],dow[N],up[N],S[N],v[N],tr[M],lzy[M];
int m,q[N];
bool cmp(int a,int b){
	return v[a]<v[b];
}
void push_up(int nod){
	tr[nod]=min(tr[nod<<1],tr[nod<<1|1])+lzy[nod];
}
void cao(int nod,ld x){
	tr[nod]+=x; lzy[nod]+=x; 
}
void ins(int l,int r,int i,int j,ld x,int nod){
	if(l==i&&r==j){
		cao(nod,x); return;
	}
	int mid=(l+r)>>1;
	if(j<=mid)ins(l,mid,i,j,x,nod<<1);
	else if(i>mid)ins(mid+1,r,i,j,x,nod<<1|1);
	else{
		ins(l,mid,i,mid,x,nod<<1); ins(mid+1,r,mid+1,j,x,nod<<1|1);
	}
	push_up(nod);
}
ld ask(int l,int r,int i,int j,int nod){
	//cout<<l<<" "<<r<<" "<<i<<" "<<j<<" "<<tr[nod]<<endl;
	if(l==i&&r==j)return tr[nod];
	int mid=(l+r)>>1;
	if(j<=mid)return ask(l,mid,i,j,nod<<1)+lzy[nod];
	else if(i>mid)return ask(mid+1,r,i,j,nod<<1|1)+lzy[nod];
	else return min(ask(l,mid,i,mid,nod<<1),ask(mid+1,r,mid+1,j,nod<<1|1))+lzy[nod];
}
void build(int l,int r,int nod){
	if(l==r){
		tr[nod]=S[l]; return;
	}
	int mid=(l+r)>>1;
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
	push_up(nod);
}
int main(){
	int n=read(),L=read(),lst=0;
	For(i,1,n){
		int x=read(),y=read(); double z; scanf("%lf",&z);
		s[++m]=x-lst; v[m]=1;
		s[++m]=y-x; v[m]=z+1;
		lst=y;
	}
	s[++m]=L-lst; v[m]=1;
	For(i,1,m){
		dow[i]=v[i]<=1?0:s[i]/(v[i]-1);
		up[i]=-s[i]/(v[i]+1);
		S[q[i]=i]=S[i-1]+dow[i];
	}
	sort(q+1,q+m+1,cmp);
	build(1,m,1);
	For(i,1,m){
		int k=q[i];
		ld nl=min(ask(1,m,k,m,1),dow[k]-up[k]); //cout<<k<<" "<<nl<<" "<<ask(1,m,k,m,1)<<" "<<dow[k]-nl<<endl;
		ans+=(s[k]+(dow[k]-nl))/v[k];
		ins(1,m,k,m,-nl,1);
	}
	printf("%.12lf\n",(double)ans);
}