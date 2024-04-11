#include <algorithm> 
#include <iostream>
#include <vector>
#include <string>        
#include <cstdio>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e6;

ll num[N];
ll add[N];
int cnt = 1;

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	ll curSum = 0;
	for (int i = 0; i < n; i++)
	{
		int t;		
		scanf("%d", &t);
		if (t == 1)
		{       
			int a, x;
			scanf("%d%d", &a, &x);
			add[a - 1] += x;
			curSum += (ll)a * (ll)x;
		}
		else if (t == 2)
		{
			int k;
			scanf("%d", &k);
			num[cnt++] = k;
			curSum += k;
		}
		else
		{
			curSum -= add[cnt - 1] + num[cnt - 1];
			if (cnt - 2 >= 0)
				add[cnt - 2] += add[cnt - 1];
			add[cnt - 1] = 0;
			cnt--;
		}
		printf("%.7lf\n", (double)curSum / (double)cnt);
	}

	return 0;
}