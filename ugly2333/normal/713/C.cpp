// CF 713C
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
int a[3333];
priority_queue<int> Q;
int main()
{
	int n,i,x;
	LL ans;
	ans=0;
	cin>>n;
	for(i=1;i<=n;i=i+1){
		cin>>a[i];
		a[i]-=i;
	}
	for(i=1;i<=n;i=i+1)
	{
		Q.push(a[i]);
		x=Q.top();
		if(x>a[i]){
			ans+=(LL)x-a[i];
			Q.pop();
			Q.push(a[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}