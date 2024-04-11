#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<queue>
#include<math.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back

struct point
{
	int x, y, z;
};
 
vector<point> W;
vector<vector<int> > V;
LL T[10][10], MI[10], MA[10];

LL odl(point a, point b)
{
	return (LL)(b.x-a.x)*(LL)(b.x-a.x)+(LL)(b.y-a.y)*(LL)(b.y-a.y)+(LL)(b.z-a.z)*(LL)(b.z-a.z);
}

bool jebaj(int l)
{
	if(l<8)
	{
		do
		{
			point a;
			a.x=V[l][0];
			a.y=V[l][1];
			a.z=V[l][2];
			W.PB(a);
			if(jebaj(l+1)) return true;
			W.pop_back();
		}while(next_permutation(V[l].begin(), V[l].end()));
	}
	if(l==8)
	{
		//printf("a");
		for(int i=0; i<8; i++)
		{
			MI[i]=1000000000000000000LL;
			MA[i]=0;
		}
		for(int i=0; i<8; i++)
		{
			for(int j=i+1; j<8; j++)
			{
				T[i][j]=odl(W[i], W[j]);
				T[j][i]=T[i][j];
				MI[i]=min(MI[i], T[i][j]);
				MA[i]=max(MA[i], T[i][j]);
				MI[j]=min(MI[j], T[i][j]);
				MA[j]=max(MA[j], T[i][j]);
			}
		}
		for(int i=0; i<8; i++)
		{
			int a=0, b=0, c=0;
			for(int j=0; j<8; j++)
			{
				if(i!=j)
				{
					if(T[i][j]==MI[i]) a++;
					else
					{
						if(T[i][j]==MA[i]) c++;
						else
						{
							if(T[i][j]==2*MI[i]) b++;
							else return false;
						}
					}
				}
			}
			if(a!=3 || b!=3 || c!=1) return false;
		}
		return true;
	}
	return false;
}


int main()
{
	for(int i=0; i<8; i++)
	{
		vector<int> ve;
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		ve.PB(a);
		ve.PB(b);
		ve.PB(c);
		sort(ve.begin(), ve.end());
		V.PB(ve);
	}
	if(jebaj(0))
	{
		printf("YES\n");
		for(int i=0; i<8; i++)
		{
			printf("%d %d %d\n", W[i].x, W[i].y, W[i].z);
		}
	}
	else
		printf("NO\n");
	return 0;
}