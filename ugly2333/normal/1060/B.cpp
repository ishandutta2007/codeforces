//CF1060B
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
int solve(LL n){
	if(n<=18)
		return n;
	if(n%10==9)
		return solve(n/10)+9;
	return max(solve(n/10)+n%10,solve(n/10-1)+10+n%10);
}
int main()
{
	LL n;
	cin>>n;
	cout<<solve(n);
	return 0;
}