#include <bits/stdc++.h>
using namespace std;
const int Maxn=55;
set <int> Se[Maxn];
int m,n;
bool vis[Maxn][Maxn];
vector <bitset<10005> > Bi(Maxn); 
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		for(int j=1;j<=tmp;j++)
		{
			int x;
			scanf("%d",&x);
			Bi[i].set(x);
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=i+1;j<=m;j++)
			if(!(Bi[i]&Bi[j]).any()) 
			{
				printf("impossible");
				return 0;
			}
	printf("possible");
	return 0;
}