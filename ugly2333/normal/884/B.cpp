//CF 884B
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
	int n,i,x;
	LL t;
	cin>>n>>t;
	for(i=1;i<=n;i=i+1){
		cin>>x;
		t-=(x+1);
	}
	if(t==-1)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}