#include <cstdio>
#include <cstring>
#define max_n 100000
#define max_k 100
#define mod 1000000007
#define cs const
using namespace std;
typedef long long ll;
int a[max_n+1];
int comb[max_n+max_k+1][max_k+1],ans[max_n+2][max_k+2];
template<typename T1,typename T2>void madd(T1&x,cs T2&y){
	(x+=y)>=mod&&(x-=mod);
}
template<typename T1,typename T2,typename T3>void madd(T1&x,cs T2&y,cs T3&z){
	(x+=y)>=mod&&(x-=mod);
	(x+=z)>=mod&&(x-=mod);
}
template<typename T1,typename T2>T1 mplus(cs T1&x,cs T2&y){
	T1 ret=x+y;
	return ret>=mod?ret-mod:ret;
}
int main(){
	comb[0][0]=1;
	for(int i=0,*now=comb[0],*prv=comb[0],*ed=comb[max_k]; (now=comb[++i])<=ed; now[0]=now[i]=1,prv=now)
		for(int j=0; ++j<i; now[j]=mplus(prv[j-1],prv[j]));
	for(int i=max_k,*now=comb[max_k],*prv=comb[max_k],*ed=comb[max_k+max_n]; (now=comb[++i])<=ed; now[0]=1,prv=now)
		for(int j=0; ++j<=max_k; now[j]=mplus(prv[j-1],prv[j]));
	int n,m,l,r,k;
	scanf("%d%d",&n,&m),memset(ans,0,sizeof(ans));
	for(int i=0; ++i<=n; scanf("%d",a+i));
	for(++m; --m; ){
		scanf("%d%d%d",&l,&r,&k);
		for(int i=-1; ++i<=k; madd(ans[l][i],comb[k][k-i]));
		for(int i=-1; ++i<=k; madd(ans[r+1][i],mod-comb[k+r-l+1][k-i]));
	}
	for(int i=0; ++i<=n; )
		for(int j=max_k+2; --j; madd(ans[i+1][j-1],ans[i][j],ans[i][j-1]));
	for(int i=0; ++i<=n; printf("%d ",mplus(ans[i][0],a[i])));
    return 0;
}