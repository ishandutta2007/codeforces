#include<algorithm>
#include<cstdio>
#include<cstring>
#define ll long long
#define For(i,x,y)  for(int i=x;i<=y;++i)
#define FOr(i,x,y)	for(int i=x;i>=y;--i)
#define maxn 610010
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
bool cmp(ll a,ll b){	return a>b;	}
inline void write(ll x){    if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){  write(x);   puts("");   }
ll q[100010],l[100010],k[100010],tot,ans;
int main(){
	ll n=read(),f=read();
	For(i,1,n){
		k[i]=read();	l[i]=read();
		ans+=min(k[i],l[i]);
		if (k[i]<l[i])	q[++tot]=min(k[i]*2,l[i])-min(k[i],l[i]);
	}
	sort(q+1,q+tot+1,cmp);
	For(i,1,f)	ans+=q[i];
	writeln(ans);
}