//CF 789E
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
int a[1005],az[1005],af[1005],dpz[300005],dpf[300005];
int main()
{
	int n,k,i,j,x,sz,sf,maxs,ans;
	cin>>n>>k;
	for(i=1;i<=k;i=i+1){
		scanf("%d",&x);
		a[x]=1;
	}
	if(a[n]==1){
		cout<<1<<endl;
		return 0;
	}
	sf=0;
	for(i=0;i<n;i=i+1)
		if(a[i]){
			sf++;
			af[sf]=n-i;
		}
	sz=0;
	for(i=n+1;i<=1000;i=i+1)
		if(a[i]){
			sz++;
			az[sz]=i-n;
		}
	if(sf==0||sz==0){
		cout<<-1<<endl;
		return 0;
	}
	maxs=300000;
	for(i=1;i<=maxs;i=i+1){
		dpz[i]=maxs;
		dpf[i]=maxs;
	}
	dpz[0]=1;
	for(i=1;i<=sz;i=i+1)
		for(j=0;j+az[i]<maxs;j=j+1)
			if(dpz[j])
				dpz[j+az[i]]=min(dpz[j+az[i]],dpz[j]+1);
	dpf[0]=1;
	for(i=1;i<=sf;i=i+1)
		for(j=0;j+af[i]<maxs;j=j+1)
			if(dpf[j])
				dpf[j+af[i]]=min(dpf[j+af[i]],dpf[j]+1);
	ans=maxs;
	for(i=1;i<maxs;i=i+1)
		ans=min(ans,dpz[i]-1+dpf[i]-1);
	cout<<ans<<endl;
	return 0;
}