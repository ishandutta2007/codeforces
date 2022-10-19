#include <bits/stdc++.h>
#define N 105
using namespace std;
char s[N];
int t;
int size;
void del(int k)
{
	for(int i=k;i<size;i++)
	{
		s[i]=s[i+1];
	}
	size--;
}
void ins(int k,char c)
{
	for(int i=size-1;i>=k;i--)
	{
		s[i+1]=s[i];
	}
	s[k]=c;
	size++;
}
void Solve()
{
	size=strlen(s);
	int cnt=0;
	for(int i=0;i<size;i++)
	{
		if(s[i]==':')cnt++;
	}
	if(cnt<7)
	{
		for(int i=0;i<size;i++)
		{
			if(s[i]==':' and s[i+1]==':')
			{
				ins(i,':');
				cnt++;
				if(cnt>=7)break;
			}
		}
	}
	else if(cnt>7)
	{
		for(int i=0;i<size;i++)
		{
			if(s[i]==':' and s[i+1]==':')
			{
				del(i);
				cnt--;
				if(cnt<=7)break;
			}
		}
	}
	int pos=0;
	for(int i=0;i<=size;i++)
	{
		if(s[i]==':' or i==size)
		{
			while(i-pos<4)
			{
				ins(pos,'0');
				i++;
			}
			pos=i+1;
		}
	}
}
int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%d\n",&t);
	while(t--)
	{
		gets(s);
		Solve();
		puts(s);
	}
	return 0;
}////