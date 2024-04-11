//CF 842A
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
	int i,l,r,x,y,k;
	cin>>l>>r>>x>>y>>k;
	for(i=x;i<=y;i=i+1){
		if((LL)l<=(LL)i*k&&(LL)i*k<=(LL)r){
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}