#include <iostream>
#include <utility>
#include <cstdio>
#include <algorithm>

typedef std::pair<int, int> ii;



int qry(char c, int a, int b) {
	std::cout << c << ' ' << a << ' ' << b << std::endl;
	fflush(stdout);
	std::string str;
	std::cin >> str;
	if(str[0]=='>') return 1;
	if(str[0]=='=') return 0;
	return -1;
}

ii solve(int l, int r)
{
	//std::cout << "solving " << l << ',' << r << '\n';
	if(r-l==0) return ii(l,r);
	if(r-l+1==2)
	{
		int v=qry('?',l,r);
		if(v==1)
			return ii(l,r);
		return ii(r,l);
	}
	ii f=solve(l,(l+r)/2);
	ii s=solve((l+r)/2+1,r);
	if(qry('?',f.first,s.first)==1)
		f.first=s.first;
	if(qry('?',f.second,s.second)==-1)
		f.second=s.second;
	return f;
}

int main()
{
	int tests;
	std::cin >> tests;
	while(tests)
	{
		int n;
		std::cin >> n;
		if(n==1)
		{
			std::cout << "! 1 1" << std::endl;
			tests--;
			continue;
		}
		int on=3;
		ii first_int=solve(1,2);
		while(on<=n)
		{
			ii sec=solve(on,std::min(on+1,n));
			if(qry('?',first_int.first,sec.first)==-1)
				first_int.first=sec.first;
			if(qry('?',first_int.second,sec.second)==1)
				first_int.second=sec.second;
			on+=2;
		}
		std::cout << "! " << first_int.second << ' ' << first_int.first << std::endl;
		fflush(stdout);



		tests--;
	}
}