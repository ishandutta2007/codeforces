#include<cstdio>
#include<algorithm>

using namespace std;

int p[3030];

int main()
{
	int N;
	int cnt=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",p+i);
	for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) if(p[i]>p[j]) cnt++;
	if(cnt%2==0)
	{
		printf("%d\n",cnt*2);
		return 0;
	}
	else
	{
		printf("%d\n",1+((cnt/2)*4));
		return 0;
	}
}