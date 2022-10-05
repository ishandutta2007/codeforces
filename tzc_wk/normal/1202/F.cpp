#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
int a,b;
int main(){
	scanf("%d%d",&a,&b);
	int ans=0;
	for(int l=1,r;l<=a+b;l=r+1){
		r=(a+b)/((a+b)/l);
		int g=(a+b)/l;
		int al=(a+g)/(g+1),ar=a/g;
		int bl=(b+g)/(g+1),br=b/g;
		if(al<=ar&&bl<=br) ans+=max(0,min(ar+br,r)-max(al+bl,l)+1);
	} printf("%d\n",ans);
	return 0;
}