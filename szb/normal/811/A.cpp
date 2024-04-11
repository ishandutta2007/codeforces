#include<cstdio>
#include<algorithm>
#include<cmath>
#include<memory.h>
#include<map>
#define ll int
#define maxn 10100
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
using namespace std;
inline ll read(){ll x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline void write(ll x){if (x<0) putchar('-'),x=-x;if (x>=10) write(x/10);putchar(x%10+'0');  }
inline void writeln(ll x){  write(x); puts("");}
int main(){
    ll a=read(),b=read(),x=1;
    while(a>=0&&b>=0){
        if(x&1) a-=x;
        else b-=x;
        x++;
    }
    puts(a<0?"Vladik":"Valera");
}