#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
#define pb push_back
vector<int> dig;
int main()
{
	ll n;int i;
	scanf("%lld",&n);
	while(n) dig.pb(n%10>4?9-(n%10):n%10),n/=10;
	if(!dig.back()) printf("9"),dig.pop_back();
	while(dig.size()) printf("%i",dig.back()),dig.pop_back();
	printf("\n");
	return 0;
}