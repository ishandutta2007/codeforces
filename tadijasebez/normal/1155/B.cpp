#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
char s[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",s+1);
	int c=(n-11)/2;
	int a=0;
	for(i=1;i<=n;i++)
	{
		if(s[i]=='8') a++;
		else c--;
		if(c<0) break;
	}
	if(a>(n-11)/2) printf("YES\n");
	else printf("NO\n");
	return 0;
}