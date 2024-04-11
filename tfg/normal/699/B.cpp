#include <cstdio>
#include <iostream>
#include <utility>
#include <string>

typedef std::pair<int, int> ii;
typedef std::pair<double, double> dd;

inline int readint()
{
	int temp;
	scanf("%i",&temp);
	return temp;
}


int anscol=0;
int ansrow=0;
int anscol2;
int ansrow2;
int anss=0;

int main()
{
	int n=readint();
	int m=readint();
	std::string str;
	for(int i=0;i<n;i++)
	{
		std::cin >> str;
		for(int j=0;j<m;j++)
		{
			if(str[j]=='*')
			{
				if(anss==0)
				{
					ansrow=i;
					anscol=j;
					anss=1;
				}
				else if(anss==1)
				{
					if(i==ansrow)
						anss=2;
					else if(j==anscol)
						anss=3;
					else
					{
						anss=5;
						ansrow2=ansrow;
						anscol2=j;
						ansrow=i;
					}
				}
				else if(anss==2)
				{
					if(i!=ansrow)
					{
						anss=4;
						anscol=j;
					}
				}
				else if(anss==3)
				{
					if(j!=anscol)
					{
						anss=4;
						ansrow=i;
					}
				}
				else if(anss==4)
				{
					if(j!=anscol && i!=ansrow)
						anss=10;
				}
				else if(anss==5)
				{
					if(i==ansrow || j==anscol)
					{
						anss=4;
					}
					else if(i==ansrow2 || j==anscol2)
					{
						ansrow=ansrow2;
						anscol=anscol2;
						anss=4;
					}
					else
						anss=10;
				}

			}
		}
	}
	if(anss<10)
		printf("YES\n%i %i\n",ansrow+1,anscol+1);
	else
		printf("NO\n");
}