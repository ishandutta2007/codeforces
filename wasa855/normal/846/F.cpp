#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int ans=0;
	while(isdigit(ch))
	{
		ans=ans*10+ch-48;
		ch=getchar();
	}
	return ans;
}
#define N 1000005
int a[N],last[N];
int main()
{
	int n;
	cin>>n;
	double sum=n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		sum+=(double)(i+1)*(double)(n-i)*2.0;
	}
	for(int i=1;i<=n;i++)
	{
		if(last[a[i]])
		{
			sum-=(double)last[a[i]]*(double)(n-i+1)*2.0;
		}
		last[a[i]]=i;
	}
	printf("%.5lf\n",sum/(double)n/(double)n);
	return 0;
}