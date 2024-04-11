//CF 852B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int M = 105;
const int mod = 1e9+7;
int n,l,m;
struct Mat{
	int a[M][M];
}p,one;
Mat Mul(Mat p1,Mat p2){
	Mat res;
	int i,j,k;
	for(i=0;i<m;i=i+1)
		for(j=0;j<m;j=j+1){
			res.a[i][j]=0;
			for(k=0;k<m;k=k+1)
				res.a[i][j]=(res.a[i][j]+((LL)p1.a[i][k]*p2.a[k][j])%mod)%mod;
		}
	return res;
}
Mat fpow(Mat p1,int x){
	if(x==0)
		return one;
	if(x==1)
		return p1;
	Mat res;
	res=fpow(p1,x/2);
	res=Mul(res,res);
	if(x&1)
		res=Mul(res,p1);
	return res;
}
int t[1111111];
int b[M],c[M];
int main()
{
	int i,j,x;
	LL ans;
	scanf("%d%d%d",&n,&l,&m);
	for(i=1;i<=n;i=i+1){
		scanf("%d",&x);
		b[x%m]++;
	}
	for(i=1;i<=n;i=i+1){
		scanf("%d",t+i);
		p.a[0][t[i]%m]++;
	}
	for(i=1;i<=n;i=i+1){
		scanf("%d",&x);
		x+=t[i];
		c[x%m]++;
	}
	one.a[0][0]=1;
	for(i=1;i<m;i=i+1){
		one.a[i][i]=1;
		for(j=0;j<m;j=j+1)
			p.a[i][j]=p.a[0][(j-i+m)%m];
	}
	//for(i=0;i<m;i=i+1,cout<<endl)
	//	for(j=0;j<m;j=j+1)
	//		cout<<p.a[i][j];
	p=fpow(p,l-2);
	ans=0;
	for(i=0;i<m;i=i+1)
		for(j=0;j<m;j=j+1)
			ans=(ans+((LL)b[i]*c[j]%mod)*(p.a[(i+j)%m][0])%mod)%mod;
	cout<<ans<<endl;
	return 0;
}