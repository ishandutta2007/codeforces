//CF 871D
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
const int N = 1e7+17;
int f[N],s[N],p[N];
LL g[N],s0,s1,s2,s3,ans;
int main()
{
	int n,i,j,t;
	cin>>n;
	t=n-1;
	for(i=2;i<=n;i=i+1){
		if(!f[i]){
			f[i]=i;
			for(j=i+i;j<=n;j=j+i)
				if(!f[j])
					f[j]=i;
			if(i+i>n)
				t--;
			else
				p[f[i]]++;
		}
		else
			p[f[i]]++;
	}
	s0=(LL)n*(n-1)/2-(LL)t*(t-1)/2;
	for(i=n;i>=1;i=i-1){
		g[i]=(LL)(n/i)*(n/i-1)/2;
		for(j=i+i;j<=n;j=j+i)
			g[i]-=g[j];
	}
	s1=(LL)n*(n-1)/2-g[1];
	for(i=1;i<=n;i=i+1)
		s[i]=s[i-1]+p[i];
	s3=(LL)t*(t-1);
	for(i=1;i<=n;i=i+1)
		s3-=(LL)p[i]*s[n/i];
	for(i=2;i<=n;i=i+1)
		if(f[i]!=i||i+i<=n)
			if((LL)f[i]*f[i]<=n)
				s3++;
	s3=s3/2;
	s2=g[1]-s3-s0;
	ans=s1+s2*2+s3*3;
	cout<<ans;
	return 0;
}