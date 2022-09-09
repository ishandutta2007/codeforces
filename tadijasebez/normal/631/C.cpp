#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=200050;
int R[N],T[N],cnt,A[N],B[N];
int main()
{
	int n,m,t,r,i,j;
	scanf("%i %i",&n,&m);
	for(i=0;i<n;i++) scanf("%i",&A[i]),B[i]=A[i];
	for(i=0;i<m;i++)
	{
		scanf("%i %i",&t,&r);
		while(cnt>0 && r>=R[cnt-1]) cnt--;
		R[cnt]=r,T[cnt++]=t;
	}
	int l=0;r=R[0];R[cnt++]=0;
	sort(B,B+r);
	for(i=1;i<cnt;i++)
	{
		for(j=R[i-1];j>R[i];j--)
		{
			if(T[i-1]==1) A[j-1]=B[--r];
			else A[j-1]=B[l++];
		}
	}
	for(i=0;i<n;i++) printf("%i ",A[i]);
	printf("\n");
	return 0;
}