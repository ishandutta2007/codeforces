//CF 825C
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
int a[1111];
int main()
{
	int n,k,i,ans,s;
	cin>>n>>k;
	for(i=1;i<=n;i=i+1)
		cin>>a[i];
	sort(a+1,a+n+1);
	ans=0;
	for(i=1;i<=n;i=i+1){
		s=k;
		while(s*2<a[i]){
			ans++;
			s*=2;
		}
		if(s==k)
			k=max(k,a[i]);
		else
			k=a[i];
	}
	cout<<ans<<endl;
	return 0;
}