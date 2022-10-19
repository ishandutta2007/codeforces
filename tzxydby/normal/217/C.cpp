#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
char in[N];
inline int run(int& np)
{
	if(in[np]=='0')
	{
		np++;
		return 1;
	}
	if(in[np]=='1')
	{
		np++;
		return 2;
	}
	if(in[np]=='?')
	{
		np++;
		return 4;
	}
	np++;
	int x1=run(np);
	char c=in[np];
	np++;
	int x2=run(np);
	np++;
	int r=0;
	for(int i=1;i<8;i*=2)
	{
		if(!(x1&i))
			continue;
		for(int j=1;j<8;j*=2)
		{
			if(!(x2&j))
				continue;
			if(i!=4&&j!=4)
			{
				int xx1=(i==2);
				int xx2=(j==2);
				if(c=='^')
					r|=(1<<(xx1^xx2));
				else if(c=='&')
					r|=(1<<(xx1&xx2));
				else if(c=='|')
					r|=(1<<(xx1|xx2));
			}
			else
			{
				if(c=='^')
				{
					if(i==4&&j==4)
						r|=3;
					else
						r|=4;
				}
				else if(c=='&')
				{
					if(i==4&&j==4)
						r|=5;
					else if(i==2||j==2)
						r|=4;
					else
						r|=1;
				} 
				else
				{
					if(i==4&&j==4)
						r|=6;
					else if(i==2||j==2)
						r|=2;
					else
						r|=4;
				 } 
			} 
		}
	} 
	return r;
}
int main()
{
	scanf("%*d");
	scanf("%s",in);
	int np=0;
	puts((run(np)&4)?"YES":"NO");
	return 0;
}