//CF 569A
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
	int t,s,q,ans;
	cin>>t>>s>>q;
	ans=0;
	while(s<t){
		ans++;
		s*=q;
	}
	cout<<ans<<endl;
	return 0;
}