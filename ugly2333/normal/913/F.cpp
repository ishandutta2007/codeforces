//CF 913F
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 2222;
const int MO = 998244353;
void AD(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int fpow(int x,int y=MO-2){
	if(!y)
		return 1;
	int z=fpow(x,y>>1);
	z=mul(z,z);
	if(y&1)
		return mul(z,x);
	return z;
}
int n,a,b,c;
int pa[N*N],pc[N*N],f[N][N];
int g[N],s[N];
int main()
{
	int i,j,x;
	cin>>n>>a>>b;
	a=mul(a,fpow(b));
	b=(1-a+MO)%MO;
	c=mul(b,fpow(a));
	pa[0]=1,pc[0]=1;
	for(i=1;i<=n*n;i=i+1)
		pa[i]=mul(pa[i-1],a),pc[i]=mul(pc[i-1],c);
	f[0][0]=1;
	for(i=1;i<=n;i=i+1){
		for(j=0;j<=n&&j<=i;j=j+1){
			f[i][j]=f[i-1][j];
			AD(f[i][j],mul(f[i-1][j-1],pc[i-j]));
		}
	}
	g[1]=1,s[1]=0;
	for(i=2;i<=n;i=i+1){
		g[i]=1;
		for(j=1;j<i;j=j+1){
			x=mul(g[j],mul(pa[j*(i-j)],f[i][j]));
			AD(g[i],MO-x);
			AD(s[i],mul(x,(s[j]+s[i-j]+j*(i-j)+j*(j-1)/2)%MO));
		}
		//cout<<i<<' '<<s[i]<<endl;
		x=s[i]+mul(g[i],i*(i-1)/2);
		s[i]=mul(x%MO,fpow(1-g[i]+MO));
		//cout<<g[i]<<' '<<s[i]<<endl<<endl;
	}
	cout<<s[n];
	return 0;
}