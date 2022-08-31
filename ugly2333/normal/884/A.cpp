//CF 884A
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
	int n,t,i,x;
	cin>>n>>t;
	for(i=1;i<=n;i=i+1){
		cin>>x;
		t-=(86400-x);
		if(t<=0){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}