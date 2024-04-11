#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=100050;
int x[N],y[N],id[N];
bool comp(int i, int j){ return x[i]<x[j];}
int main()
{
	int n,s,i;
	scanf("%i %i",&s,&n);
	for(i=1;i<=n;i++) scanf("%i %i",&x[i],&y[i]),id[i]=i;
	sort(id+1,id+1+n,comp);
	for(i=1;i<=n;i++){ if(s<=x[id[i]]) return printf("NO\n"),0;s+=y[id[i]];}
	printf("YES\n");
	return 0;
}