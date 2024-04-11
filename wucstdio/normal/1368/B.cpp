#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const char s[]="codeforces";
ll k,now;
int cnt[10];
int main()
{
	for(int i=0;i<10;i++)cnt[i]=1;
	now=1;
	scanf("%lld",&k);
	while(now<k)
	{
		for(int i=0;i<10;i++)
		{
			now=now/cnt[i]*(cnt[i]+1);
			cnt[i]++;
			if(now>=k)break;
		}
	}
	for(int i=0;i<10;i++)
	  for(int j=0;j<cnt[i];j++)
	    printf("%c",s[i]);
	printf("\n");
	return 0;
}