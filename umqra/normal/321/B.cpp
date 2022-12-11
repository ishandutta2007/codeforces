#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

const int N = 1000;

vector <int> attack, def;
int my[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	int mySum = 0, atSum = 0;
	int ans = 0;
	bool h = true;
	for (int i = 0; i < n; i++)
	{
		string str;
		int t;             	
		cin >> str >> t;
		if (str == "ATK")
		{
			attack.push_back(t);
			atSum += t;
		}
		else
			def.push_back(t);
	}	
	for (int s = 0; s < m; s++)
	{
		cin >> my[s];
		mySum += my[s];
	}
	sort(my, my + m);
	sort(attack.begin(), attack.end());
	sort(def.begin(), def.end());	
      
    int itA = 0, itM = m - 1;
    int curSum = 0;
    while (1)
    {
    	if (itM < 0 || itA == (int)attack.size() || attack[itA] > my[itM])
    		break;
    	curSum += my[itM] - attack[itA];
    	itM--, itA++;
    }

    ans = max(curSum, ans);
    itM = 0;
    for (int i = 0; i < (int)def.size(); i++)
    {
    	while (itM < m && my[itM] <= def[i])
    		itM++;
    	if (itM == m)
    	{
    		h = false;
    		break;
    	}             
    	mySum -= my[itM];
    	my[itM] = -1;
    }

    if (!h)
    {
    	printf("%d", ans);
    	return 0;
    }
    itM = m - 1;
    for (int i = (int)attack.size() - 1; i >= 0; i--)
    {
    	while (itM >= 0 && my[itM] < attack[i])
    		itM--;
    	if (itM < 0)
    	{
    		h = false;
    		break;
    	}
    }

    if (h)
    	ans = max(ans, mySum - atSum);

    printf("%d", ans);
	return 0;
}