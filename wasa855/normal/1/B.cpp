#include<bits/stdc++.h>
using namespace std;
int r,c;
char a[10005];
bool il(char x)
{
	if((x>='a'&&x<='z')||(x>='A'&&x<='Z'))
	{
		return true;
	}
	return false;
}
bool in(char x)
{
	if(x>='0'&&x<='9')
	{
		return true;
	}
	return false;
}
void work()
{
	scanf("%s",a);
//	printf("%s\n",a);
	r=c=0;
	int num=1;
	int len=strlen(a);
	for(int i=1;i<len;i++)
	{
		if(il(a[i])==true&&il(a[i-1])==false)
		{
			num++;
		}
	}
//	cout<<num<<endl;
	if(num==1)
	{
		int i;
		for(i=0;;i++)
		{
			if(il(a[i])==false)
			{
				break;
			}
			c*=26;
			c+=a[i]-'A'+1;
		}
		for(;i<len;i++)
		{
			r*=10;
			r+=a[i]-'0';
		}
		printf("R%dC%d\n",r,c);
	}
	else
	{
		stack<char> s;
		int i;
		for(i=1;;i++)
		{
			if(in(a[i])==false)
			{
				i++;
				break;
			}
			r*=10;
			r+=a[i]-'0';
		}
		for(;i<len;i++)
		{
			c*=10;
			c+=a[i]-'0';
		}
		while(c>0)
		{
			if(c%26==0)
			{
				s.push('Z');
				c/=26;
				c--;
			}
			else
			{
				s.push(c%26+'A'-1);
				c/=26;
			}
		}
		while(!s.empty())
		{
			printf("%c",s.top());
			s.pop();
		}
		printf("%d\n",r);
	}
}
int main()
{
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		work();
	}
	return 0;
}