#include<vector>
#include<cstdio> 
#include<cstring> 
#include<map>
#include<cmath> 
#include<algorithm> 
#include<ctime> 
using namespace std; 
#define ll int
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
ll read(){  ll x=0,f=1; char ch=getchar();  for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-')    f=-1;   for(;ch>='0'&&ch<='9';ch=getchar())   x=x*10+ch-'0';  return x*f; } 
void write(ll x){   if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  } 
void writeln(ll x){ write(x);   puts("");   }
const ll N=400010;
ll h,a[N],b[N],mn[N],mx[N],n;
int main(){
	h=read();	ll fl=0;
	For(i,1,h+1)	a[i]=read();
	For(i,2,h+1)	if (a[i]>1&&a[i-1]>1)	fl=i;
	if (!fl)	puts("perfect");
	else{
		puts("ambiguous");
		For(i,1,h+1)	a[i]+=a[i-1];
		For(i,1,h+1){
			if (i==fl){
				For(j,a[i-1]+1,a[i])	printf("%d ",a[i-1]);
			}else
			{
				For(j,a[i-1]+1,a[i])	printf("%d ",a[i-1]);
			}
		}puts("");
		For(i,1,h+1){
			if (i==fl){
				printf("%d ",a[i-2]+1);
				For(j,a[i-1]+2,a[i])	printf("%d ",a[i-1]);
			}else
			{
				For(j,a[i-1]+1,a[i])	printf("%d ",a[i-1]);
			}
		}
	}
}