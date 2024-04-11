#include<cstdio>
#include<algorithm>

using namespace std;

int a[100100];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	sort(a,a+N);
	int s=0,t=0;
	int best=-1;
	while(s<N)
	{
		while(t<N)
		{
			if(t==N||a[t]>a[s]*2) break;
			t++;
		}
		best=max(best,t-s);
		s++;
	}
	printf("%d\n",N-best);
	return 0;
}