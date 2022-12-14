#include<cstdio>
#include<cstring>

using namespace std;

const long long mod=1000000007;

long long ex[110];

char ch[110];

int main()
{
	scanf("%s",ch);
	int N=strlen(ch);
	ex[0]=1;
	for(int i=1;i<110;i++)
	{
		ex[i]=ex[i-1]*2;
		ex[i]%=mod;
	}
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		if(ch[i]=='0') continue;
		long long tmp=ex[i]*ex[N-1-i];
		tmp%=mod;
		tmp*=ex[N-1-i];
		tmp%=mod;
		ans+=tmp;
		ans%=mod;
	}
	ans+=mod;
	ans%=mod;
	printf("%d\n",(int)ans);
	return 0;
}