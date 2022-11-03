#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
using namespace std;
#define ll long long
#define For(i,x,y)	for(ll i=x;i<=y;++i)
#define maxn 210000
#define szb (f[i][j-(n-i+1)][k-(n-i+1)*(i-1)]+1)
ll read(){	ll x=0,f=0; char ch=getchar();	while(ch<'0'||ch>'9'){ if(ch=='-') f=1; ch=getchar(); }	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0', ch=getchar();	return f?-x:x;}
void write(ll x){	if (x<0)	x=-x,putchar('-');	if (x>=10)	write(x/10);	putchar(x%10+'0');}
void writeln(ll x){	write(x);	puts("");	}
const ll inf=2e11+7;
ll ans,a[102],answ,n,K;
inline ll check(ll x){
	ll ans=0;
	For(i,1,n)	ans+=(x-a[i]%x)%x;
	return ans<=K;
}
int main(){
	n=read();	K=read();
	For(i,1,n)	a[i]=read();
	for(ll i=1,now=inf;i<inf;i=now+1){
		ll tot=0;	now=inf;
		For(j,1,n)	if (a[j]>=i)	now=min(now,a[j]/(a[j]/i)),++tot;
		ll l=i,r=now,mid;
		if (check(r)){	answ=max(answ,r);	continue;}
		if (!check(l))	continue;
		while(l<=r){
			ll mid=(l+r)>>1;
			if (check(mid))	answ=max(answ,mid),l=mid+1;
			else	r=mid-1;
		}
	}
	writeln(answ);
}
/*
3 40
10 30 50
*/