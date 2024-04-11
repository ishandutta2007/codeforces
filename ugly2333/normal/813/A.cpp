// CF 813A
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
	int n,i,x,s,y;
	cin>>n;
	s=0;
	for(i=1;i<=n;i=i+1){
		cin>>x;
		s+=x;
	}
	cin>>n;
	for(i=1;i<=n;i=i+1){
		cin>>x>>y;
		if(x<=s&&s<=y){
			cout<<s<<endl;
			return 0;
		}
		if(s<=x){
			cout<<x<<endl;
			return 0;
		}
	}
	cout<<"-1\n";
	return 0;
}