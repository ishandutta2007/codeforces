#include <bits/stdc++.h>
using namespace std;
const int N=55;
int a[N];
int main()
{
	int n,i,mn=N,c=0;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),mn=min(mn,a[i]);
	for(i=1;i<=n;i++) if(a[i]==mn) c++;
	if(c>n/2) printf("Bob\n");
	else printf("Alice\n");
	return 0;
}