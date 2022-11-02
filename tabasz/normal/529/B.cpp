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

int n, maxh=0;
LL res=1000000001;
PII T[1005];
priority_queue<int> Q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> n;
	for(int i=0; i<n; i++)
	{
		int a, b;
		cin>> a >> b;
		maxh=max(maxh, max(b, a));
		T[i]=MP(b, a);
	}
	for(int i=1; i<=maxh; i++)
	{
		while(!Q.empty()) Q.pop();
		int rev=0, w=0;
		bool boo=1;
		for(int j=0; j<n; j++)
		{
			if(T[j].F>i)
			{
				if(T[j].S>i)
				{
					boo=0;
					break;
				}
				rev++;
				w+=T[j].F;
			}
			else
			{
				w+=T[j].S;
				if(T[j].F<T[j].S && T[j].S<=i) Q.push(T[j].S-T[j].F);
			}
			if(rev>n/2)
			{
				boo=0;
				break;
			}
		}
		if(!boo) continue;
		while(!Q.empty() && rev<n/2)
		{
			w-=Q.top();
			Q.pop();
			rev++;
		}
		if(boo) res=min(res, (LL)w*(LL)i);
	}
	cout<< res << '\n';
	return 0;
}