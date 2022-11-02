#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
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
const int mod=1e9+7,N=100005,base=N;
ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
ll pw[N],ipw[N];
int q[50],a[N];
struct hh{
	int len,hash;
	hh(){}
	hh(int x){len=1; hash=x;}
	hh(int x,int y){len=x; hash=y;}
}jb[50];
hh operator +(hh a,hh b){
	return hh(a.len+b.len,(a.hash*pw[b.len]+b.hash)%mod);
}
hh operator -(hh a,hh b){
	return hh(a.len-b.len,(a.hash-b.hash+mod)*ipw[b.len]%mod);
}
struct data{
	hh l,r;
	data (){}
	data (int x){
		if(x>0){r=x; l=hh(0,0);} else {l=-x; r=hh(0,0);}
	}
}tr[1<<18|2];
hh splitr(int nod,int k){
	if(!k)return tr[0].l;
	if(tr[nod].r.len==k)return tr[nod].r;
	if(tr[nod<<1|1].r.len>=k)return splitr(nod<<1|1,k);
	return splitr(nod<<1,k-tr[nod<<1|1].r.len+tr[nod<<1|1].l.len)-tr[nod<<1|1].l+tr[nod<<1|1].r;
}
hh splitl(int nod,int k){
	if(!k)return tr[0].l;
	if(tr[nod].l.len==k)return tr[nod].l;
	if(tr[nod<<1].l.len>=k)return splitl(nod<<1,k);
	return splitl(nod<<1|1,k-tr[nod<<1].l.len+tr[nod<<1].r.len)-tr[nod<<1].r+tr[nod<<1].l;
}
void push_up(int nod){
	data a=tr[nod<<1],b=tr[nod<<1|1];
	if(a.l.len<0||b.l.len<0){
		tr[nod].l.len=-1; return;
	}
	if(a.r.len>=b.l.len){
		hh zs=splitr(nod<<1,b.l.len);
		if(zs.hash==b.l.hash){
			tr[nod].l=tr[nod<<1].l;
			tr[nod].r=tr[nod<<1].r-tr[nod<<1|1].l+tr[nod<<1|1].r;
		}else tr[nod].l.len=-1; 
	}else{
		hh zs=splitl(nod<<1|1,a.r.len);
		if(zs.hash==a.r.hash){
			tr[nod].l=tr[nod<<1|1].l-tr[nod<<1].r+tr[nod<<1].l;
			tr[nod].r=tr[nod<<1|1].r;
		}else tr[nod].l.len=-1;
	}
}
void ins(int l,int r,int p,int nod){
	if(l==r){
		tr[nod]=a[l]; return;
	}
	int mid=(l+r)>>1;
	if(p<=mid)ins(l,mid,p,nod<<1); else ins(mid+1,r,p,nod<<1|1);
	push_up(nod);
}
vector<int> v;
void ask(int l,int r,int i,int j,int nod){
	if(i>r||j<l)return;
	if(i<=l&&r<=j){
		v.pb(nod); return;
	}
	int mid=(l+r)>>1;
	ask(l,mid,i,j,nod<<1); ask(mid+1,r,i,j,nod<<1|1);
}
void build(int l,int r,int nod){
	if(l==r){
		tr[nod]=a[l];  return;
	}
	int mid=(l+r)>>1;
	build(l,mid,nod<<1); build(mid+1,r,nod<<1|1);
	push_up(nod);
}
int main(){
	int n=read(); read();
	For(i,pw[0]=1,n)pw[i]=pw[i-1]*base%mod;
	ipw[n]=ksm(pw[n],mod-2); Rep(i,n,1)ipw[i-1]=ipw[i]*base%mod;
	For(i,1,n)a[i]=read();
	build(1,n,1);
	int Q=read();
	while(Q--){
		int op=read(),x=read(),y=read();
		if(op==1){
			a[x]=y;
			ins(1,n,x,1);
		}else{
			v.clear();
			ask(1,n,x,y,1);
			int f=1,top=0;
			for(auto i:v){
				hh zs=tr[i].l;
				if(zs.len==-1){
					f=0; break;
				}
				hh dq=(hh){0,0};
				while(zs.len-dq.len){
					if(!top){f=0; break;}
					hh s=tr[q[top]].r-jb[top],t=zs-dq;
					if(s.len<=t.len){
						hh sp=splitl(i,s.len+dq.len)-dq;
						if(sp.hash!=s.hash){f=0; break;}
						dq=s+dq; top--;
					}else{
						hh sp=splitr(q[top],t.len+jb[top].len)-jb[top];
						if(sp.hash!=t.hash){f=0; break;}
						jb[top]=t+jb[top]; dq=zs;
					}
				}
				if(!f)break;
				if(tr[i].r.len){
					q[++top]=i; jb[top]=(hh){0,0};
				}
			}
			puts(f&&top==0?"Yes":"No");
		}
	}
}