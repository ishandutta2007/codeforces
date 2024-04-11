//CF1097B
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
int n,a[22];
int main()
{
	int i,j,o;
	cin>>n;
	for(i=0;i<n;i=i+1)
		cin>>a[i];
	for(j=0;j<(1<<n);j=j+1){
		o=0;
		for(i=0;i<n;i=i+1){
			if(j&(1<<i))
				o+=a[i];
			else
				o-=a[i];
		}
		if(o<0)
			o=-o;
		o%=360;
		if(!o){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}