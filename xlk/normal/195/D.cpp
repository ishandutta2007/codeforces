#include<stdio.h>
#include<set>
using namespace std;
set<long double>s;
int n,b,k;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&k,&b),k?(s.insert((long double)b/k),0):0;
	printf("%d",s.size());
}