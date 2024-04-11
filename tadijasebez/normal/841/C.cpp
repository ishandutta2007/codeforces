#include <stdio.h>
#include <algorithm>
using namespace std;
struct sol
{
	int a,b,index;
	inline bool operator < (const sol &c) const
	{
		return b<c.b;
	}
} brr[200050];
bool Compare(sol c, sol d)
{
	return c.index<d.index;
}
int arr[200050];
bool Compare2(int a, int b)
{
	return a>b;
}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i",&arr[i]);
	for(i=0;i<n;i++) scanf("%i",&brr[i].b),brr[i].index=i;
	sort(brr,brr+n);
	sort(arr,arr+n,Compare2);
	for(i=0;i<n;i++)
	{
		brr[i].a=arr[i];
	}
	sort(brr,brr+n,Compare);
	for(i=0;i<n;i++)
	{
		printf("%i ",brr[i].a);
	}
	return 0;
}