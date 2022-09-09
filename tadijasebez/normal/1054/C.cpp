#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int a[N],l[N],r[N],id[N];
bool comp(int i, int j){ return l[i]+r[i]<l[j]+r[j];}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&l[i]);
	for(i=1;i<=n;i++) scanf("%i",&r[i]),id[i]=i;
	sort(id+1,id+1+n,comp);
	for(int j=1;j<=n;j++)
	{
		i=id[j];int p=id[j-1];
		if(j!=1 && l[i]+r[i]==l[p]+r[p]) a[i]=a[p];
		else a[i]=n-j+1;
	}
	//for(i=1;i<=n;i++) printf("%i ",a[i]);
	for(i=1;i<=n;i++)
	{
		int L=0,R=0;
		for(int j=1;j<i;j++) if(a[j]>a[i]) L++;
		for(int j=i+1;j<=n;j++) if(a[j]>a[i]) R++;
		if(l[i]!=L || r[i]!=R) return printf("NO\n"),0;
	}
	printf("YES\n");
	for(i=1;i<=n;i++) printf("%i ",a[i]);
	return 0;
}