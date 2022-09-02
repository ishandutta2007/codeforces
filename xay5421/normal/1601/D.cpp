// author: xay5421
// created: Mon Oct 25 14:28:23 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=500005;
struct xay{
	int s,a;
	xay(int k1=0,int k2=0):s(k1),a(k2){}
}a[N];
bool operator<(xay a,xay b){
	if(a.a==b.a)return a.s<b.s;
	int rev=0;
	if(a.a>b.a)swap(a,b),rev=1;
	if((a.a>b.s)&&(b.a>a.s))return(a.s<b.s)^rev;
	if((a.a<=b.s)&&(b.a<=a.s))return rev^1;
	if(a.a>b.s)return rev;
	return rev^1;
}
int b[N],mx[N<<2],tg[N<<2];
int n,d,m;
void upd(int u){mx[u]=max(mx[u*2],mx[u*2+1]);}
void ps(int k1,int k2){
	mx[k1]+=k2;
	tg[k1]+=k2;
}
void psd(int k1){
	if(tg[k1]){
		ps(k1*2,tg[k1]);
		ps(k1*2+1,tg[k1]);
		tg[k1]=0;
	}
}
void add(int k1,int k2,int k3,int k4,int k5,int k6){
	if(k4<=k2&&k3<=k5){
		ps(k1,k6);
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	if(mid>=k4)add(k1*2,k2,mid,k4,k5,k6);
	if(mid<k5)add(k1*2+1,mid+1,k3,k4,k5,k6);
	upd(k1);
}
void mdf(int k1,int k2,int k3,int k4,int k5){
	if(k2==k3){
		mx[k1]=max(mx[k1],k5);
		return;
	}
	psd(k1);
	int mid=(k2+k3)>>1;
	if(mid>=k4)mdf(k1*2,k2,mid,k4,k5);
	else mdf(k1*2+1,mid+1,k3,k4,k5);
	upd(k1);
}
int qry(int k1,int k2,int k3,int k4,int k5){
	if(k4<=k2&&k3<=k5)return mx[k1];
	int mid=(k2+k3)>>1,maxn=0;
	psd(k1);
	if(mid>=k4)maxn=max(maxn,qry(k1*2,k2,mid,k4,k5));
	if(mid<k5)maxn=max(maxn,qry(k1*2+1,mid+1,k3,k4,k5));
	return maxn;
}
int main(){
	rd(n);rd(d);
	rep(i,1,n){
		rd(a[i].s),rd(a[i].a);
		if(a[i].s<d){
			--i;
			--n;
			continue;
		}
		b[++m]=a[i].a;
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	m=unique(b+1,b+m+1)-b-1;
	rep(i,1,n){
		int pos;
		if(a[i].s>=a[i].a){
			pos=lower_bound(b+1,b+m+1,a[i].a)-b;
			int pos2=upper_bound(b+1,b+m+1,a[i].s)-b-1;
			if(pos+1<=pos2)add(1,1,m,pos+1,pos2,1);
		}else pos=upper_bound(b+1,b+m+1,a[i].s)-b-1;
		int now=1;
		if(pos>=1)now=qry(1,1,m,1,pos)+1;
		mdf(1,1,m,lower_bound(b+1,b+m+1,a[i].a)-b,now);
	}
	printf("%d\n",mx[1]);
	return 0;
}