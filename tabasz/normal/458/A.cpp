#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<queue>
#include<math.h>
#include<map>
#include<string>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define D double

string s1, s2;
int T[2][100005];

int main()
{
	cin>> s1 >> s2;
	for(int i=0; i<s1.size(); i++) if(s1[i]=='1') T[0][s1.size()-i-1]++;
	for(int i=0; i<s2.size(); i++) if(s2[i]=='1') T[1][s2.size()-i-1]++;
	int x=max(s1.size(), s2.size());
	for(x; x>=0; x--)
	{
		if(T[0][x]>T[1][x])
		{
			if(x<2 || T[0][x]-T[1][x]>x)
			{
				printf(">\n");
				return 0;
			}
			T[0][x-1]+=(T[0][x]-T[1][x]);
			T[0][x-2]+=(T[0][x]-T[1][x]);
		}
		if(T[0][x]<T[1][x])
		{
			if(x<2 || T[1][x]-T[0][x]>x)
			{
				printf("<\n");
				return 0;
			}
			T[1][x-1]+=(T[1][x]-T[0][x]);
			T[1][x-2]+=(T[1][x]-T[0][x]);
		}
	}
	printf("=\n");
	return 0;
}