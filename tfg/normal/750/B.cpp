#include <iostream>
#include <string>

const int ms=20000;

int fix(int x)
{
	if(x<0)
		return fix(-x);
	int got=x%ms;
	int on=x/ms;
	if(on%2==1)
		return ms-got;
	else
		return got;
}

int main()
{
	int n;
	int x=0, y=0;
	std::string str;
	std::cin >> n;
	bool valid=true;
	for(int i=0;i<n;i++)
	{
		int dist;
		std::cin >> dist >> str;
		if(x==0 && y==0 && str[0]!='S')
			valid=false;
		if(x==0 && y==ms && str[0]!='N')
			valid=false;
		if(str[0]=='S')
			y+=dist;
		else if(str[0]=='N')
			y-=dist;
		else if(str[0]=='E')
			x+=dist;
		else
			x-=dist;
		if((y<0 || y>=2*ms) && str[0]!='S')
			valid=false;
		if((y>ms || y<=-ms) && str[0]!='N')
			valid=false;
		y=fix(y);
		x=fix(x);
		if(y==0 || y==ms)
			x=0;
		//std::cout << "On (" << x << ", " << y << ")\n";
		//if(!valid)
		//	std::cout << "Not valid\n";
	}
	if(x!=0 || y!=0)
		valid=false;
	if(valid)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";

}