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


int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>> t;
	while(t--)
	{
		vector<bool> V;
		LL a, b;
		cin>> a >> b;
		b++;
		int li=0;
		while((a>>(li+1))>0LL || (b>>(li+1)>0LL)) li++;
		while(li>=0)
		{
			if((a>>li)%2!=(b>>li)%2)
			{
				V.PB(0);
				while(li>0)
				{
					V.PB(1);
					li--;
				}
				break;
			}
			else V.PB((a>>li)%2);
			li--;
		}
		LL res=0, p=1;
		for(int i=(int)V.size()-1; i>=0; i--)
		{
			if(V[i]) res+=p;
			p*=2LL;
		}
		cout<< res << '\n';
	}
	return 0;
}