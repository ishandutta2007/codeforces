#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=1000005;
int n,m,Q,mnv;
int a[N],b[N];
struct Tarr1{
	int s[N],t[N];
	void change2(int x,int v){
		for (;x<N;x+=x&(-x)) t[x]+=v;
	}
	void change(int x,int v){
		if (s[x]) change2(x,-1);
		s[x]+=v;
		if (s[x]) change2(x,1);
	}
	int ask(int x){
		int s=0;
		for (;x;x-=x&(-x)) s+=t[x];
		return s;
	}
	int askrk(int x){
		int p=0,S=1<<19;
		for (;S;S>>=1)
			if (p+S<N&&x>t[p+S])
				p+=S,x-=t[p];
		return p+1;
	}
}T1,T2;
struct Tarr2{
	ll t[N],s;
	void change(int x,int v){
		s+=v;
		for (;x<N;x+=x&(-x)) t[x]+=v;
	}
	ll ask(int x){
		ll s=0;
		for (;x;x-=x&(-x)) s+=t[x];
		return s;
	}
}T3,T4,T5,T6;
void add1(int x,int v){
	T1.change(x,v);
	T3.change(x,v);
	T5.change(x,v*x);
}
void add2(int x,int v){
	T2.change(x,v);
	T4.change(x,v);
	T6.change(x,v*x);
}
ll F1(int k,int x){
	ll re=0;
	re-=(k-x)*T4.s+T6.s;
	if (x>=k) re-=(x-k)*T4.ask(x-k)-T6.ask(x-k);
	re+=(k-x+max(0,x-k-min(x-k,mnv)))*(T3.s-1)+(T5.s-x);
	return re+k;
}
ll F2(int k,int x){
	ll re=0;
	re-=(k-x)*(T4.s-1)+(T6.s-x);
	if (x>=k) re-=(x-k)*T4.ask(x-k)-T6.ask(x-k);
	re+=(k-x+max(0,x-k-min(x-k,mnv)))*T3.s+T5.s;
	return re-k;
}

ll F1(int x){
	ll re=-(1ll<<60);
	int l=1,r=T1.ask(min(mnv+x,N-1));
	re=max(re,F1(x,T1.askrk(l)));
	if (r) re=max(re,F1(x,T1.askrk(r)));
	l=T1.ask(min(T2.askrk(T2.ask(N-1))+x,N-1));
	l=max(l-2,r+1); r=min(l+4,T1.ask(N-1));
	while (r-l>=1){
		int m1=(l+r)/2,m2=m1+1;
		ll v1=F1(x,T1.askrk(m1));
		ll v2=F1(x,T1.askrk(m2));
		re=max(re,max(v1,v2));
		v1<=v2?l=m2:r=m1;
	}
	For(i,l,r) re=max(re,F1(x,T1.askrk(i)));
	return re;
}
ll F2(int x){
	ll re=-(1ll<<60);
	int mn=min(T1.askrk(1),T2.askrk(1));
	int l=1,r=T2.ask(min(mnv+x,N-1));
	re=max(re,F2(x,T2.askrk(l)));
	if (r) re=max(re,F2(x,T2.askrk(r)));
	re=max(re,F2(x,T2.askrk(T2.ask(N-1))));
	return re;
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	For(i,1,n) scanf("%d",&a[i]); 
	For(i,1,m) scanf("%d",&b[i]);
	For(i,1,n) add1(++a[i],1);
	For(i,1,m) add2(++b[i],1);
	while (Q--){
		int op,x,y;
		scanf("%d%d",&op,&x);
		if (op==1){
			add1(a[x],-1);
			scanf("%d",&a[x]);
			add1(++a[x],1);
		}
		if (op==2){
			add2(b[x],-1);
			scanf("%d",&b[x]);
			add2(++b[x],1);
		}
		if (op==3){
			mnv=min(T1.askrk(1),T2.askrk(1));
			printf("%lld\n",max(F1(x),F2(x)));
		}
	}
}