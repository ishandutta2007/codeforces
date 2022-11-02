#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
#define sqr(x) ((x)*(x))
#define mp make_pair
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
inline void wri(ll a){write(a); putchar(' ');}
inline void writeln(ll a){write(a); puts("");}
const int N=1000005,mod=1e9+7;
int n,m,tree[N],sum[N],a[N],w[N];
inline void push_up(int nod){
	tree[nod]=(tree[nod<<1]+tree[nod<<1|1])%mod;
	sum[nod]=sum[nod<<1]+sum[nod<<1|1];
}
void build(int l,int r,int nod){
	if(l==r){
		tree[nod]=a[l]*w[l]%mod;
		sum[nod]=w[l]; return;
	}
	int mid=(l+r)>>1;
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
	push_up(nod);
}
void insert(int l,int r,int pos,int nod){
	if(l==r){
		tree[nod]=a[l]*w[l]%mod;
		sum[nod]=w[l]; return; 
	}
	int mid=(l+r)>>1;
	if(pos<=mid)insert(l,mid,pos,nod<<1);
	else insert(mid+1,r,pos,nod<<1|1);
	push_up(nod); 
}
int find(int l,int r,ll dq,int nod){
	if(sum[nod]<dq)return 0;
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(sum[nod<<1]>=dq)return find(l,mid,dq,nod<<1);
	else return find(mid+1,r,dq-sum[nod<<1],nod<<1|1);
}
int ask(int l,int r,int i,int j,int nod){
	if(i>j)return 0;
	if(l==i&&r==j)return sum[nod];
	int mid=(l+r)>>1;
	if(j<=mid)return ask(l,mid,i,j,nod<<1);
	else if(i>mid)return ask(mid+1,r,i,j,nod<<1|1);
	else return ask(l,mid,i,mid,nod<<1)+ask(mid+1,r,mid+1,j,nod<<1|1);
}
int Ask(int l,int r,int i,int j,int nod){
	if(i>j)return 0;
	if(l==i&&r==j)return tree[nod];
	int mid=(l+r)>>1;
	if(j<=mid)return Ask(l,mid,i,j,nod<<1);
	else if(i>mid)return Ask(mid+1,r,i,j,nod<<1|1);
	else return (Ask(l,mid,i,mid,nod<<1)+Ask(mid+1,r,mid+1,j,nod<<1|1))%mod;
}
signed main(){
	n=read(); m=read();
	for(int i=1;i<=n;i++)a[i]=read()-i;
	for(int i=1;i<=n;i++)w[i]=read();
	build(1,n,1);
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		if(x>0){
			ll t1=ask(1,n,1,x-1,1),t2=ask(1,n,1,y,1);
			int t=find(1,n,(t2+t1+1)/2,1); //cout<<t1<<" "<<t2<<" "<<(t2+t1*3+1)/2<<" "<<t<<" "<<ask(1,n,x,t,1)<<endl;
			writeln((((ask(1,n,x,t,1)%mod*a[t]-Ask(1,n,x,t,1))+(Ask(1,n,t+1,y,1)-ask(1,n,t+1,y,1)%mod*a[t]))%mod+mod)%mod);
		}else{
			x=-x; w[x]=y;
			insert(1,n,x,1);
		}
	}
}
/*
(x-t1)*2>=t2-t1
x*2-t1*2>=t2-t1
*/