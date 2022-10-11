#include <iostream>
#include <string>

std::string str[4];

bool valid(int r, int c)
{
	if(r>=4 || c>=4 || r<0 || c<0)
		return false;
	return true;
}

int aux[]={-1,-1,0,1,1,1,0,-1};
int auy[]={0,1,1,1,0,-1,-1,-1};

bool check(int r, int c, int d, char wut)
{
	int count=0;
	if(wut=='o')
		count++;
	for(int i=0;i<3;i++)
	{
		int row=r+i*aux[d];
		int col=c+i*auy[d];
		//std::cout << "on (" << row << ", " << col << ")\n"; 
		if(!valid(row,col))
			return false;
		if(wut!=str[row][col])
		{
			if(str[row][col]!='.')
				return false;
			if(count>=1)
				return false;
			count++;
		}
	}
	//std::cout << "returning true\n";
	return true;
}

bool check(int r, int c, char wut)
{
	bool ans=false;
	for(int i=0;i<8;i++)
	{
		//std::cout << "checking " << wut << ", direction " << i << " pos (" << r << ", " << c << ")\n";
		ans=ans||check(r,c,i,wut);
	}
	return ans;
}

int main()
{
	for(int i=0;i<4;i++)
	{
		std::cin >> str[i];
	}


	bool win=false, lose=false;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			win=win||check(i,j,'x');
			lose=lose||check(i,j,'o');
		}
	}
	/*if(win)
		std::cout << "Can win\n";
	if(lose)
		std::cout << "Can lose\n";*/

	if(win && !lose)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
}