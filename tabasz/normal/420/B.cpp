#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<iostream>
#include<map>
#include<math.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back
#define D double

vector<int> W;
vector<pair<char, int> > V;
int T[100003];
bool B[100003], bw[100003];
char c;

int main()
{
	//ios_base::sync_with_stdio(0);
	int n, m, li=0;
	scanf("%d%d%c", &n, &m, &c);
	for(int i=0; i<m; i++)
	{
		int a;
		scanf("%c %d", &c, &a);
		V.PB(MP(c, a));
		if(T[a]==0)
		{
			if(c=='+') T[a]=1;
			else
			{
				T[a]=2;
				B[a]=1;
				li++;
			}
		}
		scanf("%c", &c);
	}
	for(int i=1; i<=n; i++)
	{
		if(!T[i]) W.PB(i);
		else bw[i]=1;
	}
	int can=-1;
	bool boo=0;
	for(int i=0; i<V.size(); i++)
	{
		if(li==1)
		{
			if(!boo)
			{
				for(int i=1; i<=n; i++)
				{
					if(B[i]) can=i;
					else bw[i]=0;
				}
			}
			boo=1;
		}
		if(V[i].F=='+')
		{
			B[V[i].S]=1;
			if(li>0) bw[V[i].S]=0;
			else
			{
				if(boo && V[i].S!=can) bw[can]=0;
			}
			li++;
		}
		else
		{
			B[V[i].S]=0;
			if(li>1) bw[V[i].S]=0;
			li--;
		}
	}
	for(int i=1; i<=n; i++) if(bw[i]) W.PB(i);
	sort(W.begin(), W.end());
	printf("%d\n", (int)W.size());
	for(int i=0; i<W.size(); i++) printf("%d ", W[i]);
	printf("\n");
	return 0;
}