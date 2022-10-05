#include <bits/stdc++.h>
using namespace std;
string str;
int n,x,y;
struct id
{
	int x,y;
	void clear(void)
	{
		x=y=0;
	}
	id operator - (const id &a) const
	{
		return (id){x-a.x,y-a.y};
	}
	bool operator == (const id &tmp) const
	{
		return x==tmp.x&&y==tmp.y;
	}
}sum,goal;
struct opt
{
	char ch;
	id operator + (id a) const
	{
		if(ch=='U') a.y++;
		if(ch=='D') a.y--;
		if(ch=='R') a.x++;
		if(ch=='L') a.x--;
		return a;
	}
};
opt change(char ch)
{
	opt x;
	x.ch=ch;
	return x;
}
opt minus_change(char ch)
{
	opt x;
	if(ch=='U') ch='D';
	else if(ch=='D') ch='U';
	else if(ch=='L') ch='R';
	else if(ch=='R') ch='L';
	x.ch=ch;
	return x;
}
int main()
{
	sum.clear();
	scanf("%d",&n);
	cin>>str;
	scanf("%d%d",&goal.x,&goal.y);
	for(int i=0;i<n;i++)
		sum=change(str[i])+sum;
	if(sum==goal)
	{
		printf("0");
		return 0;
	}
	if(n%2!=(abs(goal.x)+abs(goal.y))%2){printf("-1");return 0;}
	int l=1,r=n+1;
	while(l+1<=r)
	{
		int mid=l+r>>1;
		id dif,now;
		now.clear();
		for(int i=0;i<mid;i++)
			now=change(str[i])+now;
		dif=goal-(sum-now);
		if(abs(dif.x)+abs(dif.y)<=mid&&(abs(dif.x)+abs(dif.y))%2==mid%2){r=mid;goto A;}
		for(int i=mid;i<n;i++)
		{
			now=change(str[i])+now;
			now=minus_change(str[i-mid])+now;
			dif=goal-(sum-now);
			if(abs(dif.x)+abs(dif.y)<=mid){r=mid;goto A;}
		}
		l=mid+1;
		A:;
	}
	printf("%d",r==n+1?-1:r);
	return 0;
}