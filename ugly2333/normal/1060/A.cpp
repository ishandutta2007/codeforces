//CF1060A
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
int n,a[111];
string s;
int main()
{
	int i;
	cin>>n>>s;
	for(i=0;i<n;i=i+1)
		a[s[i]-'0']++;
	cout<<min(a[8],n/11);
	return 0;
}