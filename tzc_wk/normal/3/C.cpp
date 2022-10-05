#include <bits/stdc++.h> 
using namespace std;
char m[3][3];
bool win(char x)
{
	if(m[0][0]==x&&m[0][0]==m[1][1]&&m[1][1]==m[2][2])
	{
		return true;
	}	
	if(m[0][2]==x&&m[0][2]==m[1][1]&&m[1][1]==m[2][0])
	{
		return true;
	}
	if(m[0][0]==x&&m[0][0]==m[0][1]&&m[0][1]==m[0][2])
	{
		return true;
	}
	if(m[1][0]==x&&m[1][0]==m[1][1]&&m[1][1]==m[1][2])
	{
		return true;
	}
	if(m[2][0]==x&&m[2][0]==m[2][1]&&m[2][1]==m[2][2])
	{
		return true;
	}
	if(m[0][0]==x&&m[0][0]==m[1][0]&&m[1][0]==m[2][0])
	{
		return true;
	}
	if(m[0][1]==x&&m[0][1]==m[1][1]&&m[1][1]==m[2][1])
	{
		return true;
	}
	if(m[0][2]==x&&m[0][2]==m[1][2]&&m[1][2]==m[2][2])
	{
		return true;
	}
	return false;
}
int n1=0,n2=0;
bool ille(int x,int y)
{
	if(x==y or x==y+1)
	{
		return false;	
	}
	else
		return true;
}
bool fwon(int x,int y)
{
	if(x==y+1&&win('X')&&!win('0')) 
	{
		return true;
	}
	else
		return false;
}
bool swon(int x,int y)
{
	if(x==y&&!win('X')&&win('0')) 
	{
		return true;
	}
	return false;
}
bool d(int x,int y)
{
	if(!win('X')&&!win('0')&&x==5&&y==4)
	{
		return true;
	}
	return false;
}
bool f(int x,int y)
{
	if(!win('X')&&!win('0')&&x==y)
	{
		return true;
	}
	return false;
}
bool s(int x,int y)
{
	if(!win('X')&&!win('0')&&x==y+1)
	{
		return true;
	}
	return false;
}
int main()
{ 
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			cin>>m[i][j];
	for(int i=0;i<3;++i)
	{
		for(int j=0;j<3;++j)
		{
			if(m[i][j]=='X')
			{
				n1++;
			} 
			if(m[i][j]=='0')
			{
				n2++;
			}
		}
	}
	//cout<<win('X')<<"  "<<win('0')<<endl;
	//cout<<n1<<"  "<<n2<<endl;
	if(ille(n1,n2))	{puts("illegal");return 0;}
	if(fwon(n1,n2))	{puts("the first player won");return 0;}
	if(swon(n1,n2))	{puts("the second player won");return 0;}
	if(d(n1,n2))	{puts("draw");return 0;}
	if(f(n1,n2))	{puts("first");return 0;}
	if(s(n1,n2))	{puts("second");return 0;}
	puts("illegal");
	return 0;
}