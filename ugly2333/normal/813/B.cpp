// CF 813B
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
LL a[11111],b[11111],c[11111];
int main()
{
	LL i,x,y,l,r,t,ans;
	int sa,sb,sc,j,k;
	cin>>x>>y>>l>>r;
	sa=0;
	sb=0;
	sc=0;
	t=1e18+10;
	for(i=1;i<=t/x+1;i=i*x){
		sa++;
		a[sa]=i;
	}
	sa++;
	a[sa]=i;
	for(i=1;i<=t/y+1;i=i*y){
		sb++;
		b[sb]=i;
	}
	sb++;
	b[sb]=i;
	//cout<<sa<<endl<<sb<<endl;
	for(j=1;j<=sa;j=j+1)
		for(k=1;k<=sb;k=k+1){
			sc++;
			c[sc]=a[j]+b[k];
			//cout<<a[j]<<' '<<b[k]<<' '<<c[sc]<<endl;
		}
	sort(c+1,c+sc+1);
	ans=0;
	j=1;
	while(j<=sc&&c[j]<l){
		j++;
	}
	ans=max(ans,c[j]-l);
	while(j<=sc&&c[j]<r){
		j++;
		if(c[j]>r)
			break;
		ans=max(ans,c[j]-c[j-1]-1);
	}
	if(c[j]>r||j>sc)
		j--;
	ans=max(ans,r-c[j]);
	ans=min(ans,r-l+1);
	cout<<ans<<endl;
	return 0;
}
//100000000000 100000000000 1 1000000000000000