//CF 204A
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
map<int,int> M;
int a[111111],b[111111],p[211111];
int main()
{
	int n,i,j,s,ans,x;
	cin>>n;
	s=0;
	for(i=1;i<=n;i=i+1){
		cin>>a[i]>>b[i];
		if(M[a[i]]==0){
			s++;
			M[a[i]]=s;
		}
		if(M[b[i]]==0){
			s++;
			M[b[i]]=s;
		}
		a[i]=M[a[i]];
		b[i]=M[b[i]];
		p[a[i]]++;
		if(a[i]!=b[i])
			p[b[i]]++;
	}
	ans=n+1;
	for(i=1;i<=s;i=i+1){
		//cout<<p[i]<<endl;
		if(2*p[i]<n)
			continue;
		x=0;
		for(j=1;j<=n;j=j+1){
			if(a[j]==i)
				x++;
		}
		ans=min(ans,(n+1)/2-min(x,(n+1)/2));
	}
	if(ans==n+1)
		ans=-1;
	cout<<ans<<endl;
	return 0;
}