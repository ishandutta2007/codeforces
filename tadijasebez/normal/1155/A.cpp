#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=300050;
char s[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",s+1);
	for(i=1;i<n;i++) if(s[i]>s[i+1]) break;
	if(i==n) printf("NO\n");
	else printf("YES\n%i %i\n",i,i+1);
	return 0;
}