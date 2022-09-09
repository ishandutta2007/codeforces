#include <stdio.h>
#include <map>
using namespace std;
#define ll long long
map<ll,int> C,D;
ll c,d;
bool Solve(int A[], int n)
{
	c=d=0,C.clear(),D.clear();
	int i,k;
	for(i=1;i<=n;i++) d+=A[i],D[A[i]]++;
	for(i=1;i<=n+1;i++)
	{
		if(d>c && (d-c)%2==0 && D[(d-c)/2]) return true;
		if(d<c && (c-d)%2==0 && C[(c-d)/2]) return true;
		if(d==c) return true;
		c+=A[i],d-=A[i],C[A[i]]++,D[A[i]]--;
	}
	return false;
}
const int N=100050;
int a[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	if(Solve(a,n)) printf("YES\n");
	else printf("NO\n");
	return 0;
}