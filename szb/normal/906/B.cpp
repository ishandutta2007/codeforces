#include<set>
#include<cstdio> 
#include<cstring> 
#include<cmath> 
#include<algorithm> 
#include<ctime> 
using namespace std; 
#define ll int
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define rep(i,x,y)	for(ll i=x;i<y;++i)
ll read(){  ll x=0,f=1; char ch=getchar();  for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-')    f=-1;   for(;ch>='0'&&ch<='9';ch=getchar())   x=x*10+ch-'0';  return x*f; } 
void write(ll x){   if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  } 
void writeln(ll x){ write(x);   puts("");   }
ll n,m,sum,p[1000010],mp[1000010];
bool cls(ll x,ll y){
	if (x==0||y==0)	return 0;
	ll x1=(x-1)/m+1,y1=x%m,
	   x2=(y-1)/m+1,y2=y%m;
	if (!y1)	y1+=m;
	if (!y2)	y2+=m;
	if ((x1-1==x2)&&(y1==y2))	return 1;
	if ((x1+1==x2)&&(y1==y2))	return 1;
	if ((x1==x2)&&(y1-1==y2))	return 1;
	if ((x1==x2)&&(y1+1==y2))	return 1;
	return 0;
}
int main(){
	srand(19890604);
	n=read();	m=read();	sum=n*m;
	for(;;){
		if (clock()>1.9*CLOCKS_PER_SEC)	break;//CLOCKS_PER_SEC
		For(i,1,sum)	p[i]=i,mp[i]=0;
		random_shuffle(p+1,p+sum+1);	bool LF=1;
		For(i,1,sum){
			bool fl=0;
			For(ci,0,10){
				ll x=(rand()<<15|rand())%n+1,y=(rand()<<15|rand())%m+1;
				while(mp[(x-1)*m+y])	x=(rand()<<15|rand())%n+1,y=(rand()<<15|rand())%m+1;
				if ((y>1)&&cls(mp[(x-1)*m+y-1],p[i]))	continue;
				if ((y<m)&&cls(mp[(x-1)*m+y+1],p[i]))	continue;
				if ((x>1)&&cls(mp[(x-2)*m+y],p[i]))	continue;
				if ((x<n)&&cls(mp[x*m+y],p[i]))	continue;
				mp[(x-1)*m+y]=p[i];	fl=1;break;
			}if (!fl){	LF=0;	break;	}
		}if (LF){
			puts("YES");	ll pos=1;
			For(i,1,n){
				For(j,1,m)	printf("%d ",mp[pos++]);
				puts("");
			}
			return 0;
		}
	}puts("NO");
}