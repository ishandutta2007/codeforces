#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,m,l[N],s[N],c[N*2],f[N*2][N];
template<typename T>void umax(T&x,T y){if(x<y)x=y;}
int main(){
	scanf("%d%d",&n,&m);
	int i;
	for(i=n;i>=1;--i)scanf("%d",&l[i]);
	for(i=n;i>=1;--i)scanf("%d",&s[i]);
	for(i=1;i<=n+m;++i)scanf("%d",&c[i]);
	memset(f,192,sizeof(f));
	for(i=0;i<=n+m;++i)f[i][0]=0;
	int j,k,p;
	for(i=1;i<=n;++i){
		for(j=n;j>=1;--j)umax(f[l[i]][j],f[l[i]][j-1]+c[l[i]]-s[i]);
		for(j=l[i],k=n;j<n+m;++j,k>>=1)for(p=0;p<=k;++p)umax(f[j+1][p/2],f[j][p]+p/2*c[j+1]);
	}
	printf("%d\n",f[n+m][0]);
	return 0;
}