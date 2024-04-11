#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int ct;
string str;
vector <int> LR, RL, LL, RR, Ve[Maxn];
set <int> L, R;
deque <int> De;
int main()
{
	cin >> str;
	int siz = str.size();
	for (int i = 0; i < siz; i++)
	{
		if (str[i] == 'L')
		{
			if (!R.size())
			{
				L.insert(++ct);
				Ve[ct].push_back(i);
			}
			else
			{
				int now = *R.begin();
				Ve[now].push_back(i);
				R.erase(now);
				L.insert(now);
			}
		}
		else
		{
			if (!L.size())
			{
				R.insert(++ct);
				Ve[ct].push_back(i);
			}
			else
			{
				int now = *L.begin();
				Ve[now].push_back(i);
				L.erase(now);
				R.insert(now);
			}
		}
	}
	for (int i = 1; i <= ct; i++)
	{
		int x = str[*Ve[i].begin()], y = str[*Ve[i].rbegin()];
		if (x == 'L') x = 1;
		else x = 2;
		if (y == 'L') y = 1;
		else y = 2;
		if (x == 1 && y == 2)
			for (vector <int> :: iterator it = Ve[i].begin(); it != Ve[i].end(); it++)
				LR.push_back(*it);
		if (x == 2 && y == 1)
			for (vector <int> :: iterator it = Ve[i].begin(); it != Ve[i].end(); it++)
				RL.push_back(*it);
		if (x == 1 && y == 1) LL.push_back(i);
		if (x == 2 && y == 2) RR.push_back(i);
	}
	if (LR.size() && RL.size())
	{
		if (*LR.rbegin() > *RL.rbegin()) RL.push_back(*LR.rbegin()), LR.pop_back();
		else LR.push_back(*RL.rbegin()), RL.pop_back();
	}
	for (vector <int> :: iterator it = LR.begin(); it != LR.end(); it++)
		De.push_back(*it);
	for (vector <int> :: iterator it = RL.begin(); it != RL.end(); it++)
		De.push_back(*it);
	if (!LR.size() && !RL.size())
	{
		if (LL.size())
		{
			int now = *LL.rbegin();
			for (vector <int> :: iterator it = Ve[now].begin(); it != Ve[now].end(); it++)
				De.push_back(*it);
			LL.pop_back();
		}
		else if (RR.size())
		{
			int now = *RR.rbegin();
			for (vector <int> :: iterator it = Ve[now].begin(); it != Ve[now].end(); it++)
				De.push_back(*it);
			RR.pop_back();
		}
	}
	while (LL.size() || RR.size())
	{
		if (str[De.back()] == 'L' && RR.size())
		{
			int now = *RR.rbegin();
			for (vector <int> :: iterator it = Ve[now].begin(); it != Ve[now].end(); it++)
				De.push_back(*it);
			RR.pop_back();
		}
		else if (str[De.back()] == 'R' && LL.size())
		{
			int now = *LL.rbegin();
			for (vector <int> :: iterator it = Ve[now].begin(); it != Ve[now].end(); it++)
				De.push_back(*it);
			LL.pop_back();
		}
		else if (str[De.front()] == 'L' && RR.size())
		{
			int now = *RR.rbegin();
			for (vector <int> :: reverse_iterator it = Ve[now].rbegin(); it != Ve[now].rend(); it++)
				De.push_front(*it);
			RR.pop_back();
		}
		else if (str[De.front()] == 'R' && LL.size())
		{
			int now = *LL.rbegin();
			for (vector <int> :: reverse_iterator it = Ve[now].rbegin(); it != Ve[now].rend(); it++)
				De.push_front(*it);
			LL.pop_back();
		}
	}
	printf("%d\n", ct - 1);
	while (De.size())
		printf("%d ", De.front() + 1), De.pop_front();
	return 0;
}