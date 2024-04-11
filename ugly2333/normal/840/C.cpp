//CF 840C
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
const int N = 333;
const int MO = 1e9+7;
int n,m,a[N],b[N],c[1111][1111],d[1111];
LL f[N][N];
map<int,int> M;
map<int,int>::iterator it;
int C(int x,int y){
	if(x<0||y<0||x<y)
		return 0;
	return c[x][y];
}
int fpow(int x,int y=MO-2){
	if(!y)
		return 1;
	LL z=fpow(x,y>>1);
	z=z*z%MO;
	if(y&1)
		z=z*x%MO;
	return z;
}
int main(){
	int i,j,k,l,x;
	LL t,ans=1;
	n=1000;
	for(i=0;i<=n;i=i+1){
		c[i][0]=1;
		for(j=1;j<=i;j=j+1)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%MO;
	}
	d[0]=1;
	for(i=1;i<=n;i=i+1)
		d[i]=(LL)d[i-1]*i%MO;
	cin>>n;
	for(i=1;i<=n;i=i+1){
		cin>>x;
		for(j=2;j*j<=x;j=j+1)
			if(x%(j*j)==0)
				x/=j*j,j--;
		M[x]++;
	}
	for(it=M.begin();it!=M.end();it++)
		a[++m]=(*it).second,ans*=d[a[m]],ans%=MO;
	b[0]=1;
	for(i=1;i<=m;i=i+1)
		b[i]=b[i-1]+a[i];
	f[0][0]=1;
	for(i=0;i<m;i=i+1){
		for(j=0;j<=n;j=j+1){
			f[i][j]%=MO;
			x=a[i+1];
			for(k=0;k<=x;k=k+1){
				for(l=0;k+l<=x;l=l+1){
					t=f[i][j]*C(j,k)%MO*C(b[i]-j,l)%MO*C(x-1,k+l-1)%MO;
					if(t)
						f[i+1][j-k+x-l-k]+=t;
				}
			}
		}
	}
	cout<<f[m][0]%MO*ans%MO;
	return 0;
}