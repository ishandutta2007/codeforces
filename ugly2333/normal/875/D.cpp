//CF 875D
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
const int N = 222222;
const int M = 30;
int a[N],b[M+5];
int l[N],r[N];
map<int,int> L;
int main()
{
	int n,i,j,x,y;
	LL ans;
	ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		x=0;
		for(j=0;j<=M;j=j+1){
			y=1<<j;
			if(a[i]&y)
				b[j]=i;
			else
				x=max(x,b[j]);
		}
		l[i]=x+1;
		if(L.find(a[i])!=L.end())
			l[i]=max(l[i],L[a[i]]+1);
		L[a[i]]=i;
	}
	for(j=0;j<=M;j=j+1)
		b[j]=n+1;
	for(i=n;i>=1;i=i-1){
		x=n+1;
		for(j=0;j<=M;j=j+1){
			y=1<<j;
			if(a[i]&y)
				b[j]=i;
			else
				x=min(x,b[j]);
		}
		r[i]=x-1;
	}
	ans=(LL)n*(n+1)/2;
	for(i=1;i<=n;i=i+1){
		ans-=(LL)(i-l[i]+1)*(r[i]-i+1);
	}
	cout<<ans<<endl;
	return 0;
}