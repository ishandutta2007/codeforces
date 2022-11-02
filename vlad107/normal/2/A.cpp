#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <limits>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>
#include <numeric>
#include <cmath>
#include <complex>
#include <list>
#include <ctime>

#define MAXN 1111

int main()
{
        std::ios_base::sync_with_stdio(0);
        std::map <std::string, int> a;
	std::map <std::string, bool> was;
        std::string name[MAXN];
	int score[MAXN];
        a.clear();
        int n;
        std::cin >> n;
        int res = 0;
        for (int i = 0; i < n; i++)
                {
                        std::cin >> name[i] >> score[i];      
                        a[name[i]] += score[i];
                }       
	for (int i = 0; i < n; i++)
		if (a[name[i]] > res) res = a[name[i]];
	was.clear();         
	for (int i = 0; i < n; i++)
		if (a[name[i]] == res) was[name[i]] = true;
		else was[name[i]] = false;
	a.clear();
	for (int i = 0; i < n; i++)
		{
			a[name[i]] += score[i];
			if (was[name[i]] && a[name[i]] >= res)
				{
					std::cout << name[i];
					break;
				}
		}
	return 0;
}