#include <bits/stdc++.h>
using namespace std;

const int K = 256;
int cnt[K];
char s[1000000];

int main()
{
	int n;
	scanf("%d %s", &n, s);
	for(int i = 0; i < n; i++)
		cnt[s[i]]++;
	int np = 0;
	for(int i = 0; i < K; i++)
		np += cnt[i] & 1;
	if(np == 0)
	{
		string pal;
		for(int i = 0; i < K; i++)
			while(cnt[i])
			{
				pal += (char)i;
				cnt[i] -= 2;
			}
		printf("1\n%s", pal.c_str());
		reverse(pal.begin(), pal.end());
		printf("%s\n", pal.c_str());
		return 0;
	}
	for(int i = max(np, 1); i <= n; i++)
	{
		if(n % i == 0 && n / i % 2 == 1 && (i - np) % 2 == 0)
		{
			vector<char> centers;
			for(int j = 0; j < K; j++)
				if(cnt[j] % 2)
				{
					centers.push_back(j);
					cnt[j]--;
				}
			for(int j = 0; j < K; j++)
				while(cnt[j] > 0 && centers.size() < i)
				{
					cnt[j]-= 2;
					centers.push_back(j);
					centers.push_back(j);
				}
			printf("%d\n", i);
			int j = 0, k = n / i / 2;
			for(auto c: centers)
			{
				string str;
				while(str.size() < k)
				{
					while(str.size() < k && cnt[j] > 0)
					{
						str += (char)j;
						cnt[j] -= 2;
					}
					if(cnt[j] == 0) j++;
				}
				printf("%s%c", str.c_str(), c);
				reverse(str.begin(), str.end());
				printf("%s ", str.c_str());
			}
			puts("");
			return 0;
		}
	}
}