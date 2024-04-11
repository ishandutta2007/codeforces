#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<ctime>
#include<map>
using namespace std;
#define ll int
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
ll read(){  ll x=0,f=0; char ch=getchar();  while(ch<'0'||ch>'9'){ if(ch=='-') f=1; ch=getchar(); }   while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0', ch=getchar(); return f?-x:x;}
void write(ll x){   if (x<0) x=-x,putchar('-');  if (x>=10)   write(x/10);    putchar(x%10+'0');}
void writeln(ll x)  {   write(x);   puts("");   }
ll ask(ll i,ll j){	printf("? %d %d\n",i,j);	fflush(stdout);	ll x;	scanf("%d",&x);	return x;	}
ll w[5010],t[5010],a[5010],b[5010],ans[5010],cnt[5010],n;
int main(){
	n=read();
	For(i,0,n-1)	w[i]=ask(i,0);
	For(i,0,n-1)	t[i]=ask(0,i);
	ll sum=0;
	For(i,0,n-1){
		bool flag=0;
		For(j,0,n-1)	cnt[j]=0;
		For(j,0,n-1){
			a[j]=w[0]^i^w[j];
			if (cnt[a[j]]||a[j]>=n){	flag=1;	break;	}
			cnt[a[j]]=1;
		}
		if (flag)	continue;
		For(j,0,n-1)	b[a[j]]=j;
		For(j,0,n-1)	if ((b[j]^a[0])!=t[j]){	flag=1;	break;	}
		if (flag)	continue;
		if (!sum)	For(j,0,n-1)	ans[j]=a[j];
		sum++;
	}puts("!");
	printf("%d\n",sum);
	For(i,0,n-1)	printf("%d ",ans[i]);
}