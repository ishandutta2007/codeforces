#include <bits/stdc++.h>
using namespace std;
char str[10100];
int main()
{
	cin>>str;
	set <int> s;int tem;char sb[6];
	for(int i=0;i<=strlen(str);i++)
	{
		if(str[i]==','||str[i]=='\0')
		{
			int p=0,q=i;
			while((--q)>=0&&str[q]!=',')sb[p++]=str[q];
			sb[p]='\0';strrev(sb);sscanf(sb,"%d",&tem);
			s.insert(tem);
		}
	}
	vector <int> a(s.begin(),s.end());
	int ansx[1010],ansy[1010],p=0;
	for(int i=0;i<a.size()-1;i++)
	{
		int pos=i;
		while(i+1<a.size()&&a[i]+1==a[i+1])
			i++;
		ansx[p]=a[pos];ansy[p++]=a[i];
	}
	if(ansy[p-1]!=a[a.size()-1])
	{
		ansx[p]=a[a.size()-1];
		ansy[p++]=a[a.size()-1];
	}
	for(int i=0;i<p;i++)
	{
		if(i!=p-1)
		{
			if(ansx[i]==ansy[i])
			printf("%d,",ansx[i]);
			else
			printf("%d-%d,",ansx[i],ansy[i]);
		}
		else
		{
			if(ansx[i]==ansy[i])
			printf("%d\n",ansx[i]);
			else
			printf("%d-%d\n",ansx[i],ansy[i]);
		}
	}
	return 0;
}