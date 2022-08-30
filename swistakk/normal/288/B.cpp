#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>
#include <ctime>
#include <cstdio>
#define uint long long int
#define N 1000005
#define M 1000000007
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	int n, k;
	cin>>n>>k;
	uint wynik=1;
	for(int i=1; i<=k-1; i++)
	{
		wynik*=k;
		wynik%=M;
	}
	for(int i=1; i<=n-k; i++)
	{
		wynik*=n-k;
		wynik%=M;
	}
	cout<<wynik<<endl;
	
	
	return 0;
}