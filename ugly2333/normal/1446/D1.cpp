//CF1446D1
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
const int N = 222222;
int n,m=100,a[N],b[N],f[N];
int main()
{
	int i,j,p,o,x,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		b[a[i]]++;
	}
	p=0;
	for(i=1;i<=m;i=i+1)
		if(b[i]>b[p])
			p=i;
	o=0;
	for(i=1;i<=m;i=i+1)
		if(b[i]==b[p])
			o++;
	if(o>=2){
		cout<<n;
		return 0;
	}
	ans=0;
	for(i=1;i<=m;i=i+1){
		if(i==p)
			continue;
		for(j=1;j<=n;j=j+1)
			f[j]=N;
		x=0;
		f[0]=0;
		for(j=1;j<=n;j=j+1){
			if(a[j]==p)
				x++;
			if(a[j]==i)
				x--;
			if(x>=0){
				if(f[x]>=N)
					f[x]=j;
				else
					ans=max(ans,j-f[x]);
			}
		}
	}
	cout<<ans;
	return 0;
}