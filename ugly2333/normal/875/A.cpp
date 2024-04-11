//CF 875A
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
int s,ans[111];
int main()
{
	int n,i,t,x;
	cin>>n;
	for(i=n-1;i>=1&&i>=n-100;i=i-1){
		t=i,x=0;
		while(t){
			x+=t%10;
			t/=10;
		}
		if(x+i==n)
			ans[++s]=i;
	}
	sort(ans+1,ans+s+1);
	cout<<s<<endl;
	for(i=1;i<=s;i=i+1)
		cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}