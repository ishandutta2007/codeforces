#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N;

int S(int x)
{
	int s = 0;
	while(x)
	{
		s += x % 10;
		x /= 10; 
	}
	return s;
}

vector<int>ans;

int main()
{
	scanf("%d",&N);
	for (int i=N-1;i>=0 && i>=N-100;i--)	
		if (i + S(i) == N) ans.push_back(i);
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++)
		printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
}