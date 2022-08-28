//CF1091C
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
int n;
vector<LL> v;
LL f(LL k){
	return (LL)(1+n-k+1)*(n/k)/2;
}
int main()
{
	int i;
	cin>>n;
	for(i=1;i*i<=n;i=i+1){
		if(n%i==0){
			v.push_back(f(i));
			v.push_back(f(n/i));
		}
	}
	sort(v.begin(),v.end());
	n=unique(v.begin(),v.end())-v.begin();
	for(i=0;i<n;i=i+1)
		printf("%lld ",v[i]);
	return 0;
}