// CF 821E
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
const int mod = 1000*1000*1000+7;
struct Mat{
	int a[22][22];
}m[22];
Mat mul(Mat x,Mat y)
{
	Mat res;
	int i,j,k,n;
	n=15;
	for(i=0;i<=n;i=i+1)
		for(j=0;j<=n;j=j+1){
			res.a[i][j]=0;
			for(k=0;k<=n;k=k+1){
				res.a[i][j]+=(LL)x.a[i][k]*y.a[k][j]%mod;
				if(res.a[i][j]>=mod)
					res.a[i][j]-=mod;
			}
		}
	return res;
}
Mat Pow(Mat x,LL k)
{
	if(k==1)
		return x;
	Mat res;
	res=Pow(x,k/2);
	res=mul(res,res);
	if(k&1)
		res=mul(res,x);
	return res;
}
LL a[111],b[111],c[111],l[111];
int main()
{
	int n,i,j,t;
	LL k;
	Mat ans;
	cin>>n>>k;
	for(i=1;i<=n;i=i+1){
		cin>>a[i]>>b[i]>>c[i];
		b[n]=k;
		l[i]=b[i]-a[i];
	}
	for(t=0;t<=15;t=t+1){
		for(i=0;i<=t;i=i+1)
			for(j=0;j<=t;j=j+1){
				if(i-j<2&&j-i<2)
					m[t].a[i][j]=1;
				else
					m[t].a[i][j]=0;
			}
	}
	/*for(i=1;i<n;i=i+1){
		if(c[i]<c[i+1])
			l[i+1]--;
		else
			l[i]--;
	}*/
	ans=Pow(m[c[1]],l[1]);
	for(i=2;i<=n;i=i+1)
		if(l[i]>0)
			ans=mul(ans,Pow(m[c[i]],l[i]));
	cout<<ans.a[0][0]<<endl;
	return 0;
}