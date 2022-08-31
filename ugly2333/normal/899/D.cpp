//CF 899D
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
int main()
{
	int n,m,t,i,ans;
	LL j;
	cin>>n;
	m=1,t=n;
	while(t>=5){
		m*=10;
		t/=10;
	}
	ans=0;
	for(i=1;i<=9;i=i+1){
		j=(LL)i*m-1;
		if((LL)n+n-1>=j)
			ans+=min(j/2,n-j/2);
	}
	if(n<5)
		ans=n*(n-1)/2;
	cout<<ans<<endl;
	return 0;
}