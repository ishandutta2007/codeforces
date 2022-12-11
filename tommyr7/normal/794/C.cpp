#include <bits/stdc++.h>
#define Maxn 300007
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
string s1,s2;
int n,cnt1,cnt2;
char ch1[Maxn],ch2[Maxn],ans[Maxn];
int main()
{
	cin>>s1;
	cin>>s2;
	n=s1.length();
	for (int i=1;i<=n;i++)
	{
		ch1[i]=s1[i-1];
		ch2[i]=s2[i-1];
	}
	sort(ch1+1,ch1+n+1);
	sort(ch2+1,ch2+n+1);
	cnt1=1,cnt2=n;
	int lx2=n-n/2+1,rx1=(n+1)/2;
	int i=1;
	while (i<=n)
	{
		if (i%2==0) 
		{
			if (ch2[cnt2]>ch1[cnt1]) ans[i]=ch2[cnt2--],++i; else
			{
				int tot=0;
				for (int j=n;j>=i;j--)
				{
					if (tot%2==0) ans[j]=ch2[lx2++]; 
					if (tot%2==1) ans[j]=ch1[rx1--];
					++tot;
				}
				i=n+1;
			}
		}
		else 
		{
			if (ch1[cnt1]<ch2[cnt2]) ans[i]=ch1[cnt1++],++i; else
			{
				int tot=0;
				for (int j=n;j>=i;j--)
				{
					if (tot%2==0) ans[j]=ch1[rx1--];
					if (tot%2==1) ans[j]=ch2[lx2++];
					++tot;
				}
				i=n+1;
			}
		}
	}
	for (int i=1;i<=n;i++) printf("%c",ans[i]);
	cout << endl;
	return 0;
}