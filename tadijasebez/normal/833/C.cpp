#include <stdio.h>
int a[20],b[20],num[10],pos,sol;
bool Check(int cur, bool left, bool right)
{
	if((!left && !right) || cur==-1) return true;
	int top,bot;
	if(left) bot=a[cur];
	else bot=0;
	if(right) top=b[cur];
	else top=9;
	if(top<bot) return false;
	int i;
	for(i=bot;i<=top;i++)
	{
		if(num[i]>0)
		{
			num[i]--;
			bool eh=Check(cur-1,left && i==bot,right && i==top);
			num[i]++;
			if(eh) return true;
		}
	}
	return false;
}
void dfs(int cur, int cnt)
{
	if(cur==9)
	{
		num[9]=cnt;
		if(Check(pos-1,true,true)) sol++;
	}
	else
	{
		int i;
		for(i=0;i<=cnt;i++)
		{
			num[cur]=i;
			dfs(cur+1,cnt-i);
		}
	}
}
int main()
{
	long long l,r;
	scanf("%lld %lld",&l,&r);
	while(l>0)
	{
		a[pos++]=l%10;
		l/=10;
	}
	pos=0;
	while(r>0)
	{
		b[pos++]=r%10;
		r/=10;
	}
	dfs(0,pos);
	printf("%i\n",sol);
	return 0;
}