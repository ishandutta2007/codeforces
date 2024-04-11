#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps=1e-6;
int n,i,head=1,cnt=0;
struct aa
{
	int id,sum;
	double v;
}a[200005];
double value;
int get()
{
	int ans=0,c;
	c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')
	{
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans;
}
bool cmp(aa a,aa b)
{
	return a.v<b.v;
}
bool cmp2(aa a,aa b)
{
	return a.id<b.id;
}
int main()
{
	n=get();
	for(i=1;i<=n;i++)a[i].id=i,a[i].v=(get()+get())/(double){get()};
	sort(a+1,a+n+1,cmp);
	value=a[1].v;
	head=1;cnt=0;
	for(i=1;i<=n;i++)
	{
		if(fabs(value-a[i].v)<=eps)cnt++;
		else
		{
			for(int j=head;j<i;j++)a[j].sum=cnt;
			head=i;
			cnt=1;
			value=a[i].v;
		}
	}
	for(int j=head;j<=n;j++)a[j].sum=cnt;
	sort(a+1,a+n+1,cmp2);
	for(i=1;i<=n;i++)printf("%d ",a[i].sum);
	return 0;
}