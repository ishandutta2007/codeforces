#include<cstdio>
#include<algorithm>

using namespace std;

int dat[100100];
int sorted[100100];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",dat+i);
		sorted[i]=dat[i];
	}
	sort(sorted,sorted+N);
	int cnt=0;
	for(int i=0;i<N;i++)
	{
		if(sorted[i]!=dat[i]) cnt++;
	}
	if(cnt<=2) printf("YES\n");
	else printf("NO\n");
	return 0;
}