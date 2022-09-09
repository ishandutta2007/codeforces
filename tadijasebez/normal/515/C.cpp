#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
const int N=100;
char s[N];
vector<int> sol;
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
	{
		int x=s[i]-'0';
		if(x<2) continue;
		if(x==4) sol.pb(2),sol.pb(2),sol.pb(3);
		else if(x==6) sol.pb(5),sol.pb(3);
		else if(x==8) sol.pb(7),sol.pb(2),sol.pb(2),sol.pb(2);
		else if(x==9) sol.pb(7),sol.pb(3),sol.pb(3),sol.pb(2);
		else sol.pb(x);
	}
	sort(sol.begin(),sol.end());reverse(sol.begin(),sol.end());
	for(i=0;i<sol.size();i++) printf("%i",sol[i]);
	printf("\n");
	return 0;
}