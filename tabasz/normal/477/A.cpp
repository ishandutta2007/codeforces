#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back
const LL mod=1000000007;

int main()
{
	ios_base::sync_with_stdio(0);
	LL a, b;
	cin>> a >> b;
	LL x=((b*(b-1))/2)%mod, y=((a*(a+1))/2)%mod;
	
	LL res=(((a+y*b)%mod)*x)%mod;
	cout<< res << '\n';
	return 0;
}