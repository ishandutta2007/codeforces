//CF 1023B
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
int main()
{
	LL n,k;
	cin>>n>>k;
	if(k<=1+n)
		cout<<(k-1)/2;
	else{
		if(n-1+n<k)
			cout<<0;
		else
			cout<<(n+n-k+1)/2;
	}
	return 0;
}