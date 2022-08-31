//CF 791A
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

int main()
{
	int a,b,ans;
	cin>>a>>b;
	ans=0;
	while(a<=b)
	{
		a=3*a;
		b=2*b;
		ans=ans+1;
	}
	cout<<ans<<endl;
	return 0;
}