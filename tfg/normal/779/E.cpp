#include <iostream>
#include <string>
#include <map>

const int ms=5050;

int n, m;

std::string game[ms];
std::string wut[ms][10];
int to[ms][10];

int now[ms];

int solve(int bit, int haha)
{
	int ans=0;
	//std::cout << "bit " << bit << ", " << haha << '\n';
	for(int i=0;i<n;i++)
	{
		int c;
		if(wut[i][4].size()>0)
		{
			//operation
			int a, b;
			if(wut[i][3][0]=='?')
				a=haha;
			else if(wut[i][3][0]=='1' || wut[i][3][0]=='0')
				a=wut[i][3][bit]-'0';
			else
				a=now[to[i][3]];
			if(wut[i][5][0]=='?')
				b=haha;
			else if(wut[i][5][0]=='1' || wut[i][5][0]=='0')
				b=wut[i][5][bit]-'0';
			else
				b=now[to[i][5]];
			
			//std::cout << "making " << a << " op " << b << '\n';
			if(wut[i][4][0]=='O')
				c=a|b;
			else if(wut[i][4][0]=='X')
				c=a^b;
			else
				c=a&b;
		}
		else
		{
			int a;
			if(wut[i][3][0]=='?')
				a=haha;
			else if(wut[i][3][0]=='1' || wut[i][3][0]=='0')
				a=wut[i][3][bit]-'0';
			else
				a=now[to[i][3]];
			c=a;
		}
		if(c)
			ans++;
		//std::cout << "got " << c << '\n';
		//dude[wut[i][1]]=c;
		now[i]=c;
	}
	return ans;
}

int main()
{
	std::cin >> n >> m;
	std::getline(std::cin, game[0]);
	std::map<std::string, int> dude;
	for(int i=0;i<n;i++)
	{
		std::getline(std::cin, game[i]);
		int on=0;
		for(int j=1;j<10;j++)
		{
			while(on<game[i].size() && game[i][on]!=' ')
				wut[i][j]+=game[i][on++];
			//std::cout << wut[i][j] << "|";
			to[i][j]=dude[wut[i][j]];
			on++;
		}
		dude[wut[i][1]]=i;
		//std::cout << '\n';
	}

	std::string ans[2];
	for(int i=0;i<m;i++)
	{
		int zero=solve(i, 0);
		int one=solve(i, 1);
		if(one>zero)
			ans[1]+='1';
		else
			ans[1]+='0';
		if(one<zero)
			ans[0]+='1';
		else
			ans[0]+='0';
	}
	std::cout << ans[0] << '\n' << ans[1] << '\n';
}