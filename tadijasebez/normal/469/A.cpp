#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define pb push_back
int main()
{
	vector<int> id;
	int n,p,x,q;
	scanf("%i",&n);
	scanf("%i",&p);while(p--) scanf("%i",&x),id.pb(x);
	scanf("%i",&q);while(q--) scanf("%i",&x),id.pb(x);
	sort(id.begin(),id.end());id.erase(unique(id.begin(),id.end()),id.end());
	if(id.size()==n) printf("I become the guy.\n");
	else printf("Oh, my keyboard!\n");
	return 0;
}