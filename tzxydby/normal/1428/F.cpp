#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,t;
long long x,y;
char s[N];
vector<int>v;
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=n;i>=1;i--)
	{
		if(s[i]=='1')
		{
			t++;
			if(!v.size())
				x+=n-i+1;
			else
			{
				x+=v.back()-i;
				v.pop_back();
			}
		}
		else
		{
			for(int j=t;j>=1;j--)
				v.push_back(i+j);
			t=0;
		}
		y+=x;
	}
	printf("%lld\n",y);
	return 0;
}