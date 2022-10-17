#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
char s[1000020];
char t[1000020];
int n,m;
long long z;
int r[300];
int cs[4][4],ct[4][4];
int main()
{
	r['B']=0;
	r['R']=1;
	r['G']=2;
	scanf("%s",s);
	scanf("%s",t);
	n=strlen(s);
	m=strlen(t);
	int k=0;
	for(int i=0;i<n;i++)
	{
		while(k<m&&t[k]!=s[i])
			k++;
		if(k<m)
		{
			k++;
			z+=m-k;
		}
		else
			break;
	}
	k=0;
	for(int i=0;i<m;i++)
	{
		while(k<n&&s[k]!=t[i])
			k++;
		if(k<n)
		{
			k++;
			z+=n-k;
		}
		else
			break;
	}
	z=(long long)n*m-z;
	for(int i=1;i<n;i++)
		cs[r[s[i]]][r[s[i-1]]]++;
	for(int i=1;i<m;i++)
		ct[r[t[i]]][r[t[i-1]]]++;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(i-j)
				z-=(long long)cs[i][j]*ct[j][i];
	k=0;
	for(int i=0;i<n;i++)
	{
		while(k<m&&t[k]!=s[i])
		{
			if(k)
				ct[r[t[k]]][r[t[k-1]]]--;
			k++;
		}
		if(k<m)
		{
			if(k)
				ct[r[t[k]]][r[t[k-1]]]--;
			k++;
			if(i)
			{
				if(r[s[i-1]]!=r[s[i]])
					z+=ct[r[s[i-1]]][r[s[i]]];
			}
		}
		else
			break;
	}
	k=0;
	for(int i=0;i<m;i++)
	{
		while(k<n&&s[k]!=t[i])
		{
			if(k)
				cs[r[s[k]]][r[s[k-1]]]--;
			k++;
		}
		if(k<n)
		{
			if(k)
				cs[r[s[k]]][r[s[k-1]]]--;
			k++;
			if(i)
			{
				if(r[t[i-1]]!=r[t[i]])
					z+=cs[r[t[i-1]]][r[t[i]]];
			}
		}
		else
			break;
	}
	printf("%I64d",z);
}