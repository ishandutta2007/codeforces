#include <iostream>
#include <cstdio> 
using namespace std;
char m[3][3];
bool judge(char x)
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
	if(n1>n2+1 or n2>n1)
	{
		cout<<"illegal"<<endl;
		return 0;
	}
	if(n1==n2+1&&judge('X')&&!judge('0')) 
	{
		cout<<"the first player won"<<endl;
		return 0;
	}
	if(n1==n2&&!judge('X')&&judge('0'))
	{
		cout<<"the second player won"<<endl;
		return 0;
	}
	if(!judge('X')&&!judge('0'))
	{
		if(n1==5&&n2==4)
		{
			cout<<"draw"<<endl;
			return 0;
		}
		if(n1==n2)
		{
			cout<<"first"<<endl;
			return 0;
		}
		if(n1==n2+1)
		{
			printf("second\n");
			return 0;
		}
	}
	cout<<"illegal"<<endl;
	return 0;
}