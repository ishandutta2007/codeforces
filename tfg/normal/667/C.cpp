#include <set>
#include <string>
#include <iostream>

std::string str;
std::set<std::string> lul;
int n;

int base='z'-'a'+1;

bool visit[10100][4];
bool memo[10100][4];

bool compare_str(int on, int size)
{
	for(int i=0;i<size;i++)
	{
		if(str[on+i]!=str[on+size+i])
			return true;
	}
	return false;
}

bool can_be(int on, int size)
{
	if(on+size==n)
		return true;
	if(on+size>n)
		return false;
	if(on>=n-1)
		return false;
	if(visit[on][size]) return memo[on][size];
	visit[on][size]=true;
	bool ans=false;
	if(size==3)
	{
		ans=ans||can_be(on+size,2);
		if(on+6<=n)
			ans=ans||(can_be(on+size,3) && compare_str(on,3));
	}
	else
	{
		ans=ans||can_be(on+size,3);
		if(on+4<=n)
			ans=ans||(can_be(on+size,2) && compare_str(on,2));
	}
	return memo[on][size]=ans;
}

int main()
{
	std::cin >> str;
	n=str.size();
	for(int i=5;i<n-1;i++)
	{
		if(!can_be(i,2)) continue;
		std::string s;
		s+=str[i];
		s+=str[i+1];
		if(lul.find(s)==lul.end())
			lul.insert(s);
	}
	for(int i=5;i<n-2;i++)
	{
		if(!can_be(i,3)) continue;
		std::string s;
		s+=str[i];
		s+=str[i+1];
		s+=str[i+2];
		if(lul.find(s)==lul.end())
			lul.insert(s);
	}
	std::set<std::string>::iterator it=lul.begin();
	std::cout << lul.size() << '\n';
	while(it!=lul.end())
	{
		std::cout << *it << '\n';
		it++;
	}
}