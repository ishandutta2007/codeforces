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
int n,c,t,l,ans;
int main(){
	read(n),read(c);
	F(i,1,n){
		read(t);
		if(t-l>c)ans=1;
		else ans++;
		l=t;
	}
	cout<<ans<<endl;
	return 0;
}