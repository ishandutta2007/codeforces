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

LL T[2][4];
LL n, res=1000000000000000000LL;
LL R[2][2];
LL A[2][1000006];

LL jebaj(LL ind, LL p, LL k)
{
	LL tmp=1, pp=p;
	p=A[ind][p];
	while(p!=k)
	{
		if(p==pp || tmp>2000001) return -1;
		tmp++;
		p=A[ind][p];
	}
	return tmp;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> n;
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<4; j++)
			cin>> T[i][j];
		for(int j=0; j<n; j++)
			A[i][j]=(((LL)j*T[i][2])+T[i][3])%n;
		R[i][0]=jebaj(i, T[i][0], T[i][1]);
		R[i][1]=jebaj(i, T[i][1], T[i][1]);
	}
	//printf("%d %d %d %d\n", R[0][0], R[0][1], R[1][0], R[1][1]);
	if(R[0][0]==-1 || R[1][0]==-1)
	{
		cout<< "-1\n";
		return 0;
	}
	if(R[0][0]==R[1][0])
	{
		cout<< R[0][0] << '\n';
		return 0;
	}
	if(R[0][0]>R[1][0] && R[1][1]!=-1 && (R[0][0]-R[1][0])%R[1][1]==0)
	{
		cout<< R[0][0] << '\n';
		return 0;
	}
	if(R[1][0]>R[0][0] && R[0][1]!=-1 && (R[1][0]-R[0][0])%R[0][1]==0)
	{
		cout<< R[1][0] << '\n';
		return 0;
	}
	//printf("kurwaaaaa");
	if(R[1][1]!=-1 && R[0][1]!=-1)
	{
		for(int i=1; i<=R[1][1]+R[1][0]; i++)
		{
			if((R[0][1]*i+(R[0][0]-R[1][0]))>=0 && (R[0][1]*i+(R[0][0]-R[1][0]))%R[1][1]==0)
			{
				res=min(res, R[0][1]*i+R[0][0]);
				break;
			}
		}
		for(int i=1; i<=R[0][1]+R[0][0]; i++)
		{
			
			if((R[1][1]*i+(R[1][0]-R[0][0]))>=0 && (R[1][1]*i+(R[1][0]-R[0][0]))%R[0][1]==0)
			{
				res=min(res, R[1][1]*i+R[1][0]);
				break;
			}
		}
	}
	if(res==1000000000000000000LL) cout<< "-1\n";
	else cout<< res << '\n';
	return 0;
}