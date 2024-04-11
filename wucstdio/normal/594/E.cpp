#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[10000005],t[5000005],t1[5000005],t2[5000005],t3[5000005],t4[5000005];
int n,k,m,nowl,z[10000005],A[5000005],l[5000005];
void extend(char*s,int l)
{
	for(int i=0;i<l;i++)t[++nowl]=s[i];
}
void solve1(int n)
{
	for(int i=1;i<=n;i++)t1[i]=s[n-i+1];
}
void solve2(int n)
{
	for(int i=n+1;i<=2*n;i++)s[i]=s[i-n];
	int i=1,j=2,k=0;
	while(i<=n&&j<=n&&k<n)
	{
		if(s[i+k]==s[j+k])k++;
		else if(s[i+k]<s[j+k])j+=k+1,k=0;
		else i+=k+1,k=0;
		if(i==j)j++;
	}
	for(int x=0;x<n;x++)t2[x+1]=s[min(i,j)+x];
}
void solve3(int n)
{
	for(int i=n+1;i<=2*n;i++)s[i]=s[n-(i-n)+1];
	n*=2;
	z[1]=n;
	int l=1,r=1;
	for(int i=2;i<=n;i++)
	{
		if(r<i)
		{
			l=r=i;
			while(r<=n&&s[r]==s[r-l+1])r++;
			z[i]=r-l;
			r--;
		}
		else
		{
			if(z[i-l+1]<r-i+1)z[i]=z[i-l+1];
			else
			{
				l=i;
				while(r<=n&&s[r]==s[r-l+1])r++;
				z[i]=r-l;
				r--;
			}
		}
	}
	n/=2;
	int j=n+1;
	for(int i=n;i>=1;i--)
	{
		int l=i,r=j-1;
		l=n-l+1,r=n-r+1;
		int len=z[r+n];
		if(len<l-r+1)
		{
			if(s[len+1]>s[j-len-1])j=i;
		}
		else
		{
			len=j-i;
			l=len+1,r=j-1;
			if(s[z[l]+1]<s[l+z[l]])j=i;
		}
	}
	int tot=0;
	for(int i=n;i>=j;i--)t3[++tot]=s[i];
	for(int i=1;i<j;i++)t3[++tot]=s[i];
}
void solve4(int n)
{
	int p=m;
	while((A[p+1]-A[p])*2<=(A[p]-A[p-1]))
	{
		bool flag=0;
		for(int i=A[p]-1;i>=A[p-1];i--)
		{
			if(s[i]<s[n-i+A[p-1]])
			{
				flag=1;
				break;
			}
			if(s[i]>s[n-i+A[p-1]])break;
		}
		if(flag)break;
		p--;
	}
	p=A[p];
	int tot=0;
	for(int i=p;i<=n;i++)t4[++tot]=s[i];
	for(int i=p-1;i>=1;i--)t4[++tot]=s[i];
}
void update(char*t1,char*t2,int n)
{
	for(int i=1;i<=n;i++)
	{
		if(t1[i]<t2[i])return;
		if(t2[i]<t1[i])break;
	}
	for(int i=1;i<=n;i++)t1[i]=t2[i];
}
void solve(int n)
{
	solve1(n);
	solve2(n);
	solve3(n);
	solve4(n);
	update(t1,t2,n);
	update(t1,t3,n);
	update(t1,t4,n);
	extend(t1+1,n);
}
int main()
{
	scanf("%s",s+1);
	n=(int)strlen(s+1);
	scanf("%d",&k);
	for(int i=1;i*2<=n;i++)swap(s[i],s[n-i+1]);
	if(k==1)
	{
		for(int i=1;i<=n;i++)t[i]=s[n-i+1];
		for(int i=1;i<=n;i++)
		{
			if(s[i]<t[i])
			{
				printf("%s\n",s+1);
				return 0;
			}
			if(s[i]>t[i])
			{
				printf("%s\n",t+1);
				return 0;
			}
		}
		printf("%s\n",s+1);
		return 0;
	}
	for(int i=1;i<=n;)
	{
		int j=i,k=i+1;
		while(s[j]<=s[k])
		{
			if(s[j]<s[k])j=i;
			else j++;
			k++;
		}
		A[++m]=i;
		l[m]=k-j;
		while(i<=j)i+=k-j;
	}
	A[m+1]=n+1;
	while(m&&k>=3)
	{
		extend(s+A[m],A[m+1]-A[m]);
		if(l[m]!=1||l[m-1]!=1)k--;
		m--;
	}
	if(!m)
	{
		printf("%s\n",t+1);
		return 0;
	}
	solve(A[m+1]-1);
	printf("%s\n",t+1);
	return 0;
}