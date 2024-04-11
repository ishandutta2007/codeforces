#include<bits/stdc++.h>
using namespace std;
char a[100005];
char b[100005];
int sa[130];
int sb[130];
queue<char> q;
int main()
{
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	scanf("%s",a+1);
	scanf("%s",b+1);
	int n=strlen(a+1);
	for(int i=1;i<=n;i++)
	{
		sa[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		sb[b[i]]++;
	}
	int ans=0;
	for(int i='A';i<='Z';i++)
	{
		ans+=abs(sa[i]-sb[i]);
	}
	ans/=2;
	for(int i=1;i<=n;i++)
	{
		if(sa[a[i]]>sb[a[i]])
		{
			for(int p='A';p<='Z';p++)
			{
				if(p==a[i]&&sa[p]>0&&sb[p]>0)
				{
					sa[p]--;
					sb[p]--;
					break;
				}
				if(sb[p]>sa[p])
				{
					sa[a[i]]--;
					sa[p]++;
					a[i]=p;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	cout<<(a+1)<<endl;
	return 0;
}