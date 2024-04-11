#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
char s[100005];
int n;
ll f[5];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	f[0]=0;
	f[1]=f[2]=f[3]=1000000000;
	for(int i=1;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		int x;
		if(s[i]=='h')x=1;
		else if(s[i]=='a')x=2;
		else if(s[i]=='r')x=3;
		else if(s[i]=='d')x=4;
		else continue;
		f[x]=min(f[x],f[x-1]);
		f[x-1]+=v;
	}
	printf("%I64d\n",min(min(f[0],f[1]),min(f[2],f[3])));
	return 0;
}