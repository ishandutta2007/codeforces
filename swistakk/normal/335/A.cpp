#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#define uint long long int
#define MP make_pair
#define PB push_back
#define N 1000005

using namespace std;
char s[N];
int ile[N];

int main()
{
	// nie zapomnij o ll
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int k;
	cin>>k;
	int res = 0;
	for (int i = 1; i <=n; i++)
	{
		ile[int(s[i])]++;
	}
	for (int i = 1; i <= n; i++)
	{
		int act = 0;
		for (int j = 1; j <= 200; j++)
		{
			act += (ile[j] + i - 1) / i;
		}
		if (act <= k)
		{
			cout<<i<<endl;
			for (int j = 1; j <= 200; j++)
			{
				for (int l = 1; l <= (ile[j] + i - 1) / i; l++)
				{
					cout<<char(j);
				}
			}
			
			for (int j = 1; j <= k - act; j++)
			{
				cout<<"a";
			}
			cout<<endl;
			return 0;
		}
	}
	
	cout<<"-1"<<endl;
	
	// nie zapomnij o ll
	return 0;
}