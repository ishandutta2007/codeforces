#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef __int64 LL;
const int MAX=5100;
char map[MAX],ch[MAX];
int l[MAX],r[MAX],u[MAX],d[MAX];
int tl[MAX],tr[MAX],tu[MAX],td[MAX];
int n,m,i,j,k,ans,ma,ct,te,va[MAX];
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<n;i++)
		{
			scanf("%s",ch);
			for(j=0;j<m;j++)
			map[i*m+j]=ch[j];
		}
		for(i=0;i<n;i++)
		{
			l[i*m]=-1;
			for(j=1;j<m;j++)
			{
				if(map[i*m+j-1]=='.')l[i*m+j]=l[i*m+j-1];
				else l[i*m+j]=i*m+j-1;
			}
			r[i*m+m-1]=-1;
			for(j=m-2;j>=0;j--)
			{
				if(map[i*m+j+1]=='.')r[i*m+j]=r[i*m+j+1];
				else r[i*m+j]=i*m+j+1;
			}
		}
		for(i=0;i<m;i++)
		{
			u[i]=-1;
			for(j=1;j<n;j++)
			{
				if(map[j*m-m+i]=='.')u[j*m+i]=u[j*m-m+i];
				else u[j*m+i]=j*m-m+i;
			}
			d[n*m-m+i]=-1;
			for(j=n-2;j>=0;j--)
			{
				if(map[j*m+m+i]=='.')d[j*m+i]=d[j*m+m+i];
				else d[j*m+i]=j*m+m+i;
			}
		}
		ma=0;
		for(i=0;i<n*m;i++)
		{
			if(map[i]=='.')continue;
			for(j=0;j<n;j++)
			for(k=0;k<m;k++)
			{
				if(map[j*m+k]=='.')continue;
				tl[j*m+k]=l[j*m+k];
				tr[j*m+k]=r[j*m+k];
				tu[j*m+k]=u[j*m+k];
				td[j*m+k]=d[j*m+k];
			}
			ct=0;te=i;
			while(te!=-1)
			{
		//		printf("%d %d\n",te/m,te%m);
				tr[tl[te]]=tr[te];
				tl[tr[te]]=tl[te];
				tu[td[te]]=tu[te];
				td[tu[te]]=td[te];
				if(map[te]=='R')te=tr[te];
				else if(map[te]=='L')te=tl[te];
				else if(map[te]=='U')te=tu[te];
				else te=td[te];
				ct++;
			}
			va[i]=ct;
			ma=max(ma,ct);
		}
		ct=0;
		for(i=0;i<n*m;i++)
		{
			if(map[i]=='.')continue;
			if(va[i]==ma)ct++;
		}
		printf("%d %d\n",ma,ct);
	}
}