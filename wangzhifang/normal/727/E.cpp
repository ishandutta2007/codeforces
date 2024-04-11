#include <cstdio>
#include <cstring>
#include <unordered_map>
#define max_n 2000000
#define mod 998244353
#define mod2 1000000007
#define bas 131
using namespace std;
unordered_map<long long,int>M,N;
int n,m,k,t,ans[max_n+1];
char s[max_n+1];
long long h[max_n+1],h2[max_n+1],p[max_n+1],p2[max_n+1],g[max_n+1],g2[max_n+1];
long long get_hash(int l,int r){
	return (h[r]-h[l-1]*p[r-l+1]%mod+mod)%mod;
}
long long get_hash2(int l,int r){
	return (h2[r]-h2[l-1]*p2[r-l+1]%mod2+mod2)%mod2;
}
#define hs(x,y,m) (x*bas+y)%m
#define makepair(x,y) (x+y*mod)
int main(){
	bool flag;
	long long nowp;
	scanf("%d%d%s%d",&n,&k,s+1,&t);
	m=n*k,p[0]=p2[0]=1;
	memcpy(s+m+1,s+1,m*sizeof(char));
	m<<=1;
	for(int i=0; ++i<=m; h[i]=hs(h[i-1],s[i],mod),h2[i]=hs(h2[i-1],s[i],mod2),p[i]=p[i-1]*bas%mod,p2[i]=p2[i-1]*bas%mod2);
	for(int i=0; ++i<=t; ){
		scanf("%s",s+1);
		for(int j=0; ++j<=k; g[i]=hs(g[i],s[j],mod),g2[i]=hs(g2[i],s[j],mod2),M[makepair(g[i],g2[i])]=i);
	}
	for(int i=0; ++i<=k; ){
		N.clear(),flag=true;
		for(int j=-1; ++j<n; N[nowp]=1,ans[j+1]=M[nowp])
			if(N.count(nowp=makepair(get_hash(j*k+i,j*k+i+k-1),get_hash2(j*k+i,j*k+i+k-1)))||!M.count(nowp)){
				flag=false;
				break;
			}
		if(flag){
			printf("YES\n");
			for(int j=0; ++j<n; printf("%d ",ans[j]));
			printf("%d\n",ans[n]);
			return 0;
		}
	}
	printf("NO");
	return 0;
}