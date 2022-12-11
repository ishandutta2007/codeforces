#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

#define prev asdojashdasdkj

const int N = (int)1e5 + 100;
set <int> kill;
int a[N];
int pos[N];
int link[N];
int prev[N];
int del[N];
bool used[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		pos[a[i]] = i;
		link[i] = i + 1;
		prev[i] = i - 1;
	}

	for (int i = 1; i <= n; i++)
	{
		if (a[i] > a[i + 1] && i != n)
			kill.insert(-i); 
	}

	int ans = 0;
	while (1)
	{                       
		if (kill.size() == 0)
			break;
		ans++;
		set <int>::iterator it = kill.begin();
		int curInd = 0;
		while (it != kill.end())
		{
			int curPos = -(*it);   
			del[curInd++] = link[curPos];
			used[link[curPos]] = 1;
			it++;               
		}                                                                      
		for (int i = 0; i < curInd; i++)
		{
			int t = del[i];
			int locPrev = prev[t];
			int locNext = link[t];
			link[locPrev] = locNext;
			prev[locNext] = locPrev;
		}                   
		it = kill.begin();  
		while (it != kill.end())
		{
			int curPos = -(*it);
			if (link[curPos] > n || a[curPos] < a[link[curPos]] || used[curPos])
			{
				set <int>::iterator it2 = it;
				it++;
				kill.erase(it2);
			}
			else
				it++;
		}                
	}          

	printf("%d", ans);

	return 0;
}