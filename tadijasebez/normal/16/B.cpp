#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long
ll sol;
pair<int,int> box[50];
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,m,i;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++) scanf("%i %i",&box[i].second,&box[i].first);
	sort(box+1,box+1+m);
	reverse(box+1,box+1+m);
	for(i=1;i<=m;i++)
	{
		int x=min(n,box[i].second);
		sol+=(ll)x*box[i].first;
		n-=x;
	}
	printf("%lld\n",sol);
	return 0;
}