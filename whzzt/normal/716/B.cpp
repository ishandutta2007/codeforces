#include"algorithm"
#include"iostream"
#include"memory.h"
#include"string.h"
#include"stdlib.h"
#include"stdio.h"
#include"math.h"
#include"vector"
#include"queue"
#include"map"
#include"set"
#define UP(i,l,r,d) for(int i=l;i<=r;i+=d)
#define DN(i,r,l,d) for(int i=r;i>=l;i-=d)
#define F(i,l,r) for(int i=l;i<=r;i++)
#define D(i,r,l) for(int i=r;i>=l;i--)
#define clr(x,y) memset(x,y,sizeof(x))
#define cpy(x,y) memcpy(x,y,sizeof(y))
#define LLINF 1000000000000000000ll
#define INF 0x3f3f3f3f
#define gch getchar()
#define EPS 1e-12
#define eps 1e-6
using namespace std;
template<class integer>
inline void read(integer&x){
	x=0;char ch=gch;int f=1;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch='0',ch=gch;}
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=0,ch=gch;x*=f;
}
char s[50005];int l;
int f[27];bool flag;
int main(){
	scanf("%s",s);l=strlen(s);
	F(i,0,l-26){
		F(j,0,25)f[j]=0;
		F(j,0,25)if(s[i+j]!='?')f[s[i+j]-'A']++;
		flag=1;F(j,0,25)if(f[j]>1){flag=0;break;}
		if(flag){
			int k=0;
			F(j,0,25){
				while(f[k])k++;
				if(s[i+j]=='?'){
					s[i+j]='A'+k;
					k++;
				}
			}
			F(j,i+26,l)if(s[j]=='?')s[j]='A';
			puts(s);
			return 0;
		}
		if(s[i]=='?')s[i]='A';
	}
	puts("-1");
	return 0;
}