#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
int A,B,C;
int a[maxn],b[maxn],c[maxn];
long long f[maxn][maxn][maxn];
long long ans;
inline int cmp(int a,int b){
	return a>b;
}
int main(){
	scanf("%d%d%d",&A,&B,&C);
	for(int i=1;i<=A;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=B;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=C;i++)
		scanf("%d",&c[i]);
	sort(a+1,a+1+A,cmp),sort(b+1,b+1+B,cmp),sort(c+1,c+1+C,cmp);
	for(int i=0;i<=A;i++)
		for(int j=0;j<=B;j++)
			for(int k=0;k<=C;k++){
				if(i>=1&&j>=1)
					f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i]*b[j]);
				if(i>=1&&k>=1)
					f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i]*c[k]);
				if(j>=1&&k>=1)
					f[i][j][k]=max(f[i][j][k],f[i][j-1][k-1]+b[j]*c[k]);
				ans=max(ans,f[i][j][k]);
			}
	printf("%lld\n",ans);
	return 0;
}