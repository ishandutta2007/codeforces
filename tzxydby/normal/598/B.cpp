#include <bits/stdc++.h>
using namespace std;
char s[10005];
char temp[10005];
int l,r,k;
int q;
int size;
void Init()
{
	gets(s);
	scanf("%d",&q);
}
void move()
{
	r--;
	l--;
	for(int i=0;i<size;i++)
	{
		temp[i]=s[i];
	}
	int mod=r-l+1;
	for(int i=0;i<mod;i++)
	{
		int pos=(i+k)%mod+l;
		temp[pos]=s[i+l];
	}
	for(int i=0;i<size;i++)
	{
		s[i]=temp[i];
	}
}
void Solve()
{
	size=strlen(s);
	move();
}
int main()
{
    Init();
	while(q--)
	{
		scanf("%d%d%d",&l,&r,&k);
		Solve();
	}
	puts(s);
	return 0;
}