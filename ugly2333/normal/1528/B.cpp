//CF1528B
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
const int N = 1111111;
const int MO = 998244353;
int n,f[N];
int main()
{
	int i,j,s;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j+=i)
			f[j]++;
	s=0;
	for(i=1;i<n;i++){
		s=s*2%MO;
		s+=f[i];
		s%=MO;
	}
	s+=f[n];
	s%=MO;
	cout<<s;
	return 0;
}