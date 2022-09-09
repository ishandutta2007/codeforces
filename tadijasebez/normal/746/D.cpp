#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
vector<int> A,B;
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,k,a,b,i,j;bool sw=0;
	scanf("%i %i %i %i",&n,&k,&a,&b);
	if(a<b) sw=1,a^=b,b^=a,a^=b;
	while(a) A.pb(min(a,k)),a-=A.back(),B.pb(1),b--;
	b++;B.pop_back();
	if(b<0) return printf("NO\n"),0;
	B.pb(0);
	for(i=0;i<B.size();i++)
	{
		int x=min(b,k-B[i]);
		B[i]+=x;
		b-=x;
	}
	if(b) return printf("NO\n"),0;
	if(sw)
	{
		for(i=0;i<A.size();i++)
		{
			for(j=0;j<A[i];j++) printf("B");
			for(j=0;j<B[i];j++) printf("G");
		}
	}
	else
	{
		for(i=0;i<A.size();i++)
		{
			for(j=0;j<A[i];j++) printf("G");
			for(j=0;j<B[i];j++) printf("B");
		}
	}
	printf("\n");
	return 0;
}