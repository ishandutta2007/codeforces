#include<cstring>
#include<string>
#include<set>
#include<map>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define ll int
#define maxn 500010
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
/*void init(){
	For(i,2,N){
		if (!mark[i])	pri[++pri[0]]=i;
		for(ll j=1;j<=pri[0]&&i*pri[j]<=N;j++){
			mark[i*pri[j]]=1;
			if (!(i%pri[j]))	break;
		}
	}
}
int main(){
	n=read();	k=read();
	init();
}*/
ll n,k;
int main(){
	n=read();	k=read();
	ll a=0,b,s1=(n-k+1)/2,s2=(n-k)/2;
	For(i,1,n)	a+=read()&1;
	b=n-a;
//	printf("%d %d %d %d\n",a,b,s1,s2);
	if ((a<=s2)||(b<=s2&&!(k&1))){	printf("Daenerys");	return 0;	}
	if ((b<=s1&&(k&1))){	printf("Stannis");	return 0;	}
	if (n==k){	a&1?printf("Stannis"):printf("Daenerys");	return 0;	}
	if ((n-k)&1)	printf("Stannis");	else	printf("Daenerys");
}