#include <iostream>
#include <string>
#include <cstdlib>

std::string str;
int n;
int x,y;

int dx[4],dy[4];
int cx[4],cy[4];
char d[4],c[4];

int c1[]={0,1,0,-1};
int c2[]={1,0,-1,0};
int d1[]={1,1,-1,-1};
int d2[]={1,-1,1,-1};

int normalize(int a)
{
	if(a>0)
		return 1;
	else if(a<0)
		return -1;
	else
		return 0;
}

int main()
{
	std::cin >> n;
	std::cin >> x >> y;
	for(int i=0;i<n;i++)
	{
		int a, b;
		std::cin >> str >> a >> b;
		int r1=x-a;
		int r2=y-b;
		int n1=normalize(r1);
		int n2=normalize(r2);
		if(abs(r1)==abs(r2))
		{
			for(int i=0;i<4;i++)
			{
				if(n1==d1[i] && n2==d2[i] && (abs(r1)<abs(dx[i]) || dx[i]==0))
				{
					//std::cout << "found on diag " << i;
					if(str[0]=='R')
					{
						//std::cout << " it is false\n";
						d[i]='R';
						dx[i]=r1;
						dy[i]=r2;
					}
					else
					{
						//std::cout << " it is true\n";
						d[i]='B';
						dx[i]=r1;
						dy[i]=r2;
					}
				}
			}
		}
		if(n1==0 || n2==0)
		{
			for(int i=0;i<4;i++)
			{
				if(n1==c1[i] && n2==c2[i] && (abs(r1)<abs(cx[i]) || abs(r2)<abs(cy[i]) || cx[i]+cy[i]==0))
				{
					//std::cout << "found on col/row " << i;
					if(str[0]=='B')
					{
						//std::cout << " it is false\n";
						c[i]='B';
						cx[i]=r1;
						cy[i]=r2;
					}
					else
					{
						//std::cout << " it is true\n";
						c[i]='R';
						cx[i]=r1;
						cy[i]=r2;
					}
				}
			}
		}
	}
	bool ans=false;
	for(int i=0;i<4;i++)
	{
		if(d[i]=='B')
			ans=true;
		if(c[i]=='R')
			ans=true;
	}
	if(ans)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";

}