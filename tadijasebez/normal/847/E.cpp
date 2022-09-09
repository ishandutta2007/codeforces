#include <stdio.h>
#include <cstring>
const int N=100050;
char line[N];
int n;
int abs(int x){ return x>0?x:-x;}
int max(int a, int b){ return a>b?a:b;}
int max(int a, int b, int c){ return max(a,max(b,c));}
bool Check(int x)
{
	int j=0,i;
	for(i=0;i<n;i++)
	{
		while(i<n && line[i]!='P') i++;
		while(j<n && line[j]!='*') j++;
		if(j>=n) return true;
		if(i==n) return false;
		if(abs(i-j)>x) continue;
		if(i<j)
		{
			j=i+x+1;
		}
		else
		{
			j=max(i+1,i+1+x-2*(i-j),i+1+(x-(i-j))/2);
		}
		//printf("%i %i %i\n",x,i,j);
	}
	if(j>=n) return true;
	return false;
}
int main()
{
	scanf("%i",&n);
	scanf("%s",&line);
	int top=n*2;
	int bot=0,mid,sol=n*2;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(Check(mid)) top=mid-1,sol=mid;
		else bot=mid+1;
	}
	printf("%i\n",sol);
	return 0;
}