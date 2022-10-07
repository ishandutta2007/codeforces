#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int t,n,a[1005],match[1005];
int pos[500005],val[500005],top;
int len[500005],num;
map<int,int>last;
void rev(int p)
{
	len[++num]=2*n-p+1;
	for(int i=p;i<=2*n;i++)
	{
		pos[++top]=i-1;
		val[top]=a[2*n-i+p];
	}
	for(int i=p;i<=(2*n+p)/2;i++)
	{
		swap(a[i],a[2*n-i+p]);
		swap(match[i],match[2*n-i+p]);
	}
}
void solve(int x,int y)
{
	if(y==x+1)return;
	rev(x);
	rev(2*n-(y-x)+1);
	rev(2*n-(y-x)+2);
	rev(x);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		last.clear();
		top=num=0;
		int tot=n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(!last[a[i]])last[a[i]]=i;
			else
			{
				pos[++top]=tot;
				val[top]=a[i];
				match[tot+1]=last[a[i]];
				match[tot+2]=i;
				a[tot+1]=a[tot+2]=a[i];
				last[a[i]]=0;
				tot+=2;
			}
		}
		if(tot!=2*n)
		{
			printf("-1\n");
			continue;
		}
		for(int i=2*n;i>n;i--)
		{
			int j=i+1;
			while(j<=2*n&&match[i]>match[j])j++;
			solve(i,j);
		}
		printf("%d\n",top);
		for(int i=1;i<=top;i++)printf("%d %d\n",pos[i],val[i]);
		printf("%d\n",num+1);
		printf("%d ",2*n);
		for(int i=num;i>=1;i--)printf("%d ",2*len[i]);
		printf("\n");
	}
	return 0;
}