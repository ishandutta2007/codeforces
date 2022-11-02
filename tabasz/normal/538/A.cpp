#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back
#define PII pair<int, int>

string a="CODEFORCES", b;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> b;
	int s=b.size();
	for(int i=0; i<s; i++)
	{
		for(int j=i; j<s; j++)
		{
			string c;
			c.append(b, 0, i);
			c.append(b, j+1, s-j-1);
			if(c==a)
			{
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}