#include<cstdio>
#include<algorithm>

using namespace std;

int a[100100];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",a+i);
	}
	sort(a,a+N);
	if(a[N-1]==1) a[N-1]=2;
	else a[N-1]=1;
	sort(a,a+N);
	for(int i=0;i<N;i++) printf("%d%c",a[i],i==N-1?'\n':' ');
	return 0;
}