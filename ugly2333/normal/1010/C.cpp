//CF1010C
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
int gcd(int x,int y){
	if(!y)
		return x;
	return gcd(y,x%y);
}
int main()
{
	int n,k,i,x,s;
	scanf("%d%d",&n,&k);
	s=k;
	for(i=1;i<=n;i=i+1){
		scanf("%d",&x);
		s=gcd(s,x%k);
	}
	cout<<k/s<<endl;
	for(i=0;i<k;i=i+s)
		cout<<i<<' ';
	return 0;
}