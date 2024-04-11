// CF 846B
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
int a[111];
int main()
{
	int n,k,m,i,j,t;
	LL s,ans,anss;
	cin>>n>>k>>m;
	s=0;
	for(i=1;i<=k;i=i+1){
		cin>>a[i];
		s+=(LL)a[i];
	}
	sort(a+1,a+k+1);
	anss=0;
	for(i=0;i<=n;i=i+1){
		if((LL)i*s>m)
			break;
		ans=(LL)i*(k+1);
		t=m-i*s;
		for(j=1;j<=k;j=j+1){
			if((n-i)*a[j]>t)
				break;
			ans+=(LL)n-i;
			t-=(n-i)*a[j];
		}
		if(j<=k&&t)
			ans+=(LL)t/a[j];
		anss=max(anss,ans);
	}
	cout<<anss<<endl;
	return 0;
}