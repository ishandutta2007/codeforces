#include <stdio.h>
const int N=100050;
int max(int a, int b){ return a>b?a:b;}
int BIT[2][N];
void Set1(int index, int val)
{
	for(;index<N;index+=index&-index) BIT[0][index]=max(BIT[0][index],val);
}
void Set2(int index, int val)
{
	for(;index;index-=index&-index) BIT[1][index]=max(BIT[1][index],val);
}
int Get1(int index)
{
	if(index<0) return 0;
	int ans=0;
	for(;index;index-=index&-index) ans=max(ans,BIT[0][index]);
	return ans;
}
int Get2(int index)
{
	if(index<0) return 0;
	int ans=0;
	for(;index<N;index+=index&-index) ans=max(ans,BIT[1][index]);
	return ans;
}
int sol;
int main()
{
	int n,i,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		sol=max(sol,i-max(Get1(x-1),Get2(x+2)));
		sol=max(sol,i-max(Get1(x-2),Get2(x+1)));
		Set1(x,i);
		Set2(x,i);
	}
	printf("%i\n",sol);
	return 0;
}