#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int N=30050;
bool x[10000500];
int a[N],b[N];
int sol;
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i",&a[i]),x[a[i]]=true;
	for(i=0;i<n;i++) scanf("%i",&b[i]),x[b[i]]=true;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			sol+=x[a[i]^b[j]];
		}
	}
	if(sol%2==0) printf("Karen\n");
	else printf("Koyomi\n");
	return 0;
}