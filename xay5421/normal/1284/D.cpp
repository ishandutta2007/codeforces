#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int n,sa[N],ea[N],sb[N],eb[N],t1[N],t2[N];
struct data{
	int k1,k2,k3,k4;
}a[N],b[N];
void upd(int l,int r){
	for(int i=l;i<=n*2;i+=i&-i)t1[i]+=1;
	for(int i=l;i<=n*2;i+=i&-i)t2[i]+=l;
	for(int i=r+1;i<=n*2;i+=i&-i)t1[i]-=1;
	for(int i=r+1;i<=n*2;i+=i&-i)t2[i]-=r+1;
}
int qry(int x){
	int s1=0,s2=0;
	for(int i=x;i;i&=i-1)s1+=t1[i],s2+=t2[i];
	return s1*(x+1)-s2;
}
int qry(int l,int r){return qry(r)-qry(l-1);}
signed main(){
	rd(n);
	for(int i=1;i<=n;++i){
		rd(sa[i]),rd(ea[i]),rd(sb[i]),rd(eb[i]);
		t1[++*t1]=sa[i],t1[++*t1]=ea[i],t2[++*t2]=sb[i],t2[++*t2]=eb[i];
	}
	sort(t1+1,t1+1+*t1,[&](int x,int y){return x<y;}),*t1=unique(t1+1,t1+1+*t1)-t1-1;
	sort(t2+1,t2+1+*t2,[&](int x,int y){return x<y;}),*t2=unique(t2+1,t2+1+*t2)-t2-1;
	for(int i=1;i<=n;++i){
		sa[i]=lower_bound(t1+1,t1+1+*t1,sa[i])-t1;
		ea[i]=lower_bound(t1+1,t1+1+*t1,ea[i])-t1;
		sb[i]=lower_bound(t2+1,t2+1+*t2,sb[i])-t2;
		eb[i]=lower_bound(t2+1,t2+1+*t2,eb[i])-t2;
		a[i]=b[i]=(data){sa[i],ea[i],sb[i],eb[i]};
	}
	memset(t1,0,sizeof(t1)),memset(t2,0,sizeof(t2));
	sort(a+1,a+1+n,[&](data x,data y){return x.k1<y.k1;}),sort(b+1,b+1+n,[&](data x,data y){return x.k2<y.k2;});
	for(int i=1,j=1;i<=n;++i){
		while(j<=n&&b[j].k2<a[i].k1)upd(b[j].k3,b[j].k4),++j;
		if(qry(a[i].k3,a[i].k4)){puts("NO");return 0;}
	}
	memset(t1,0,sizeof(t1)),memset(t2,0,sizeof(t2));
	sort(a+1,a+1+n,[&](data x,data y){return x.k3<y.k3;}),sort(b+1,b+1+n,[&](data x,data y){return x.k4<y.k4;});
	for(int i=1,j=1;i<=n;++i){
		while(j<=n&&b[j].k4<a[i].k3)upd(b[j].k1,b[j].k2),++j;
		if(qry(a[i].k1,a[i].k2)){puts("NO");return 0;}
	}
	puts("YES");
	return 0;
}