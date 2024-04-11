#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
	int n,i,o=0,t=0,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		if(x==1) o++;
		else t++;
	}
	if(t) printf("2 "),t--;
	if(o) printf("1 "),o--;
	while(t) printf("2 "),t--;
	while(o) printf("1 "),o--;
	return 0;
}