#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
char str[300005];
int qz[300005];
vector<int>v[600005];
int n;
inline int find(int k,int pos)
{
	int l=0,r=v[k+n].size()-1,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(v[k+n][mid]<=pos)l=mid+1;
		else r=mid-1;
	}
	return v[k+n][r];
}
int main()
{
	int t,q,l,r;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		q=read();
		scanf("%s",str+1);
		for(int i=1;i<=2*n;i++)v[i].clear();
		v[n].push_back(0);
		for(int i=1;i<=n;i++)
		{
			if(str[i]=='+')
			{
				if(i%2==1)qz[i]=qz[i-1]+1;
				else qz[i]=qz[i-1]-1;
				v[qz[i]+n].push_back(i);
			}
			else
			{
				if(i%2==1)qz[i]=qz[i-1]-1;
				else qz[i]=qz[i-1]+1;
				v[qz[i]+n].push_back(i);
			}
		}
		for(int i=1;i<=q;i++)
		{
			l=read();
			r=read();
			if((qz[r]-qz[l-1])==0)printf("0\n");
			else if((qz[r]-qz[l-1])%2==0)
			{
				if(qz[r-1]-qz[l-1]>0)printf("2\n%d %d\n",find(qz[l-1]+(qz[r-1]-qz[l-1]-1)/2,r-2)+1,r);
				else printf("2\n%d %d\n",find(qz[l-1]+(qz[r-1]-qz[l-1]+1)/2,r-2)+1,r);
			}
			else
			{
				if(qz[r]-qz[l-1]>0)printf("1\n%d\n",find(qz[l-1]+(qz[r]-qz[l-1]-1)/2,r-1)+1);
				else printf("1\n%d\n",find(qz[l-1]+(qz[r]-qz[l-1]+1)/2,r-1)+1);
			}
		}
	}
	return 0;
}