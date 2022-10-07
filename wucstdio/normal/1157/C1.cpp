#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[200005],now,l,r,top;
char s[200005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	l=1,r=n;
	while(1)
	{
		if(l>r)break;
		if(a[l]>now&&a[r]>now)
		{
			if(a[l]<a[r])
			{
				s[++top]='L';
				now=a[l];
				l++;
			}
			else
			{
				s[++top]='R';
				now=a[r];
				r--;
			}
		}
		else if(a[l]>now)
		{
			s[++top]='L';
			now=a[l];
			l++;
		}
		else if(a[r]>now)
		{
			s[++top]='R';
			now=a[r];
			r--;
		}
		else break;
	}
	printf("%d\n",top);
	s[++top]='\0';
	printf("%s\n",s+1);
	return 0;
}