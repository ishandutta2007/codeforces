#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=1000050;
int a[N],b[N];
int main()
{
	int n,s,i;
	scanf("%i %i",&n,&s);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++) scanf("%i",&b[i]);
	bool has=0;
	for(i=s+1;i<=n;i++) if(a[i]==1 && b[i]==1) has=1;
	if(a[1] && a[s]) return 0*printf("YES\n");
	if(a[1] && b[s] && has) return 0*printf("YES\n");
	printf("NO\n");
	return 0;
}