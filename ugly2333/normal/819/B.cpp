// CF 819B
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
int a[1111111],h[1111111];
LL Abs(int x)
{
	if(x<0)
		return -x;
	return x;
}
int main()
{
	int n,i,t,j;
	LL ans,s;
	scanf("%d",&n);
	s=0;
	t=0;
	for(i=1;i<=n;i=i+1){
		scanf("%d",a+i);
		s+=Abs(a[i]-i);
		h[(a[i]-i+n)%n]++;
		if(a[i]<=i)
			t++;
	}
	ans=s;
	j=0;
	for(i=1;i<n;i=i+1){
		s-=Abs(a[n-i+1]-n);
		t--;
		s+=(LL)t;
		s-=(LL)n-1-t;
		s+=Abs(a[n-i+1]-1);
		t+=h[i];
		//cout<<s<<t<<endl;
		ans=min(ans,s);
		if(ans==s)
			j=i;
	}
	cout<<ans<<' '<<j<<endl;
	return 0;
}