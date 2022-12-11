#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char s[N],t[N];
vector<int> a[30];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",s+1,t+1);
		int ls=strlen(s+1),lt=strlen(t+1),now=1,sum=1;
		for(int i=0;i<=25;i++) a[i].clear();
		for(int i=1;i<=ls;i++)
			a[s[i]-'a'].push_back(i);
		for(int i=1;i<=lt;i++)
		{
			int x=lower_bound(a[t[i]-'a'].begin(),a[t[i]-'a'].end(),now)-a[t[i]-'a'].begin();
			if(x<a[t[i]-'a'].size()) now=a[t[i]-'a'][x]+1;
			else
			{
				now=1;
				sum++;
				x=lower_bound(a[t[i]-'a'].begin(),a[t[i]-'a'].end(),now)-a[t[i]-'a'].begin();
				if(x<a[t[i]-'a'].size()) now=a[t[i]-'a'][x]+1;
				else
				{
					sum=-1;
					break;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}