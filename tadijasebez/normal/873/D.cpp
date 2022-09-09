#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100050;
int k,was,drop[N],a[N],b[N],id[N];
void Try(int l, int r)
{
	if(r-l<=1) return;
	int mid=l+r>>1;
	if(k-was>=2)
	{
		drop[mid]=1;
		was+=2;
		Try(l,mid);
		Try(mid,r);
	}
}
bool comp(int i, int j){ return a[i]<a[j];}
int main()
{
	int n,i;
	scanf("%i %i",&n,&k);
	if(k%2==0) return printf("-1\n"),0;
	was=1;
	Try(0,n);
	if(was!=k) return printf("-1\n"),0;
	int cur=N;
	for(i=0;i<n;i++)
	{
		if(drop[i]) cur--;
		else cur++;
		a[i]=cur;
		id[i]=i;
	}
	sort(id,id+n,comp);
	for(i=0;i<n;i++) b[id[i]]=i+1;
	for(i=0;i<n;i++) printf("%i ",b[i]);
	printf("\n");
	return 0;
}