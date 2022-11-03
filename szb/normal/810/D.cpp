#include<algorithm>
#include<memory.h>
#include<cmath>
#include<cstdio>
#define ll int
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define maxn 300010
using namespace std;
inline ll read(){   ll x=0;char ch=getchar();   while(ch<'0'||ch>'9') ch=getchar();  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x; }
inline void write(ll x){    if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){  write(x);   puts("");   }
ll n,k,ans1,ans2,ans3;	char s[100];
ll work(ll l,ll r){
	while(l!=r){
		ll mid=(l+r)>>1;
		printf("1 %d %d\n",mid,mid+1);fflush(stdout);
		scanf("%s",s);
		if (s[0]=='N')	l=mid+1;
		else	r=mid;
	}
	return l;
}
int main(){
	n=read();	k=read();
	ll l=1,r=n;
	while(l!=r){
		ll mid=(l+r)>>1;
		printf("1 %d %d\n",mid,mid+1);fflush(stdout);
		scanf("%s",s);
		if (s[0]=='N')	l=mid+1;
		else	r=mid;
	}
	ans1=l;
	if (ans1>1)	ans2=work(1,ans1-1);
	if (ans1<n)	ans3=work(ans1+1,n);
	if (ans2&&ans3){
		printf("1 %d %d\n",ans2,ans3);fflush(stdout);
			scanf("%s",s);
		if (s[0]=='N')	ans2=ans3;
	}else ans2=ans2+ans3;
	printf("2 %d %d\n",ans1,ans2);fflush(stdout);
}