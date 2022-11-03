#include<algorithm>
#include<memory.h>
#include<map>
#include<cstdio>
#include<cmath>
#include<cstring>
#define ll int
#define maxn 301000
#define ld long double
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){  write(x);   puts("");   }
bool cmp(ll a,ll b){	return a>b;	}
char s1[maxn],s2[maxn];
ll a[maxn],b[maxn],c[maxn],n,tmp,l1=1,l2=1,r1,r2,sum;
void print(){
	For(i,1,sum)	putchar(c[i]);	exit(0);
}
void work(ll x){
	if ((n&1)+(x&1)==1){
		For(i,x,n)	if (i&1)	putchar(b[l2++]);
		else	putchar(a[l1++]);
	}else{
		For(i,x,n)	if (i&1)	putchar(a[l1++]);
		else	putchar(b[l2++]);
	}
	exit(0);
}
int main(){
	scanf("%s",s1);
	scanf("%s",s2);
	n=strlen(s1);
	For(i,1,n)	a[i]=s1[i-1];
	For(i,1,n)	b[i]=s2[i-1];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1,cmp);
	For(i,1,n){
		if (a[l1]>=b[l2])	work(i);
		if (i&1)	putchar(a[l1++]);	else	putchar(b[l2++]);
	}
}