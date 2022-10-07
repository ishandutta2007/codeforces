#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int p[6]={1,4,2,3,5,0};
int n;
int main()
{
	scanf("%d",&n);
	int ans=0;
	for(int i=0;i<6;i++)
	  if(n&(1<<i))ans+=1<<(6-p[i]-1);
	printf("%d\n",ans);
	return 0;
}