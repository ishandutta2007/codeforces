#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


std::map<std::vector<int>, int> wut[2];
std::map<int, std::vector<int> > haha;

std::vector<int> lol;
int depth;

void bt()
{
	depth++;
	int ans=wut[depth%2][lol];
	//for(int i=0;i<3;i++)
	//	std::cout << lol[i] << ' ';
	//std::cout << depth%2 << '\n';
	if(ans)
		return;
	wut[depth%2][lol]=depth;
	haha[depth]=lol;
	if(depth%2==0)
		std::swap(lol[0],lol[1]);
	else
		std::swap(lol[1],lol[2]);
	bt();
}

int main()
{
	for(int i=1;i<=3;i++)
		lol.push_back(i);
	depth=-1;
	bt();
	depth--;
	long long int n, x;
	std::cin >> n >> x;
	std::vector<int> now=haha[(n)%depth];
	//std::cout << depth << '\n';
	//for(int i=0;i<3;i++)
	//	std::cout << now[i] << ' ';
	//std::cout << '\n';
	std::cout << now[x]-1 << '\n';


}