#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back

struct ant
{
	int pos, ind;
	bool dir;
};

int n, R[300003], lef[2];
LL m, t, asd;
char C[5];
vector<ant> V[2];

bool cmp(ant a, ant b)
{
	return a.pos<b.pos;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%lld%lld", &n, &m, &t);
	LL tt=t%m;
	t*=2;
	asd=t/m;
	t%=m;
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d%s", &a, C);
		ant x;
		x.pos=a;
		x.ind=i;
		if(C[0]=='R')
		{
			x.dir=1;
			lef[1]++;
		}
		else
		{
			x.dir=0;
			lef[0]++;
		}
		V[0].PB(x);
		x.pos=m-a+1;
		x.dir=!x.dir;
		V[1].PB(x);
	}
	for(int ind=0; ind<2; ind++)
	{
		sort(V[ind].begin(), V[ind].end(), cmp);
		//printf("%d:\n", ind);
		for(int i=0; i<n; i++)
		{
		//	printf("%d %d %d\n", V[ind][i].pos, V[ind][i].ind, V[ind][i].dir);
			V[ind].PB(V[ind][i]);
			V[ind][n+i].pos+=m;
		}
		int tmp=0, left=0;
		for(int i=0; i<n; i++)
		{
			while(tmp<2*n && V[ind][tmp].pos<=V[ind][i].pos+t)
			{
				if(!V[ind][tmp].dir)
					left++;
				tmp++;
			}
		//	printf("%d %d ind=%d dir=%d tmp=%d left=%d\n", ind, i, V[ind][i].ind, V[ind][i].dir, tmp, left);
			if(V[ind][i].dir)
			{
				LL left2=(left+asd*lef[ind])%n;
				R[V[ind][i+left2].ind]=V[ind][i].pos+tt;
				//printf("%d %d %d\n", i+left, V[ind][i+left].ind, V[ind][i].pos+t);
				while(R[V[ind][i+left2].ind]>m)
					R[V[ind][i+left2].ind]-=m;
				if(ind==1)
					R[V[ind][i+left2].ind]=m-R[V[ind][i+left2].ind]+1;
			}
			else
				left--;
		}
	}
	for(int i=0; i<n; i++)
		printf("%d ", R[i]);
	printf("\n");
	return 0;
}