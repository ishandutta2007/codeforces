#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,k,ans,l[2005],r[2005];
char s[2005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		k--;
		scanf("%s",s+1);
		ans=0;
		for(int i=2;i<=2*k;i+=2)
		{
			if(s[i-1]!='(')
			{
				ans++;
				l[ans]=i-1;
				for(int j=i;j<=n;j++)
				{
					if(s[j]=='(')
					{
						r[ans]=j;
						break;
					}
				}
				for(int i=1;i<=(r[ans]-l[ans]+1)/2;i++)
				  swap(s[l[ans]+i-1],s[r[ans]-i+1]);
			}
			if(s[i]!=')')
			{
				ans++;
				l[ans]=i;
				for(int j=i+1;j<=n;j++)
				{
					if(s[j]==')')
					{
						r[ans]=j;
						break;
					}
				}
				for(int i=1;i<=(r[ans]-l[ans]+1)/2;i++)
				  swap(s[l[ans]+i-1],s[r[ans]-i+1]);
			}
		}
		for(int i=2*k+1;i<=2*k+n/2-k;i++)
		{
			if(s[i]!='(')
			{
				ans++;
				l[ans]=i;
				for(int j=i+1;j<=n;j++)
				{
					if(s[j]=='(')
					{
						r[ans]=j;
						break;
					}
				}
				for(int i=1;i<=(r[ans]-l[ans]+1)/2;i++)
				  swap(s[l[ans]+i-1],s[r[ans]-i+1]);
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=ans;i++)printf("%d %d\n",l[i],r[i]);
	}
	return 0;
}