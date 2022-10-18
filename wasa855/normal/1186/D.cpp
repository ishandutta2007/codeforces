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
#define N 100005
double a[N];
int b[N];
int l[N],r[N];
int main()
{
	int n;
	cin>>n;
	int res=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		l[i]=ceil(a[i]);
		r[i]=floor(a[i]);
		b[i]=l[i];
		res+=b[i];
	}
	int i=1;
	while(res!=0)
	{
		b[i]=r[i];
		res+=r[i]-l[i];
		i++;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",b[i]);
	}
	return 0;
}