#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXDEP = 18;
int N;
int h[200010];
int st[200010][MAXDEP + 1],ma[200010][MAXDEP + 1];
int lg[500010];
int nxt[200010][32];

int getmax(int L,int R)
{
	int len = R - L + 1,l = lg[len]; 
	return max(ma[L][l],ma[R-(1<<l)+1][l]);
}

pair<int,int> pos[33];

int main()
{
	for (int i=0,j=1;i<=MAXDEP;j*=2,i++)lg[j] = i;
	for (int i=1;i<=200000;i++)lg[i] = max(lg[i-1],lg[i]);
	//for (int i=1;i<=10;i++)printf("%d\n",lg[i]);
	scanf("%d",&N);
	for (int i=1;i<=N;i++)scanf("%d",&h[i]),st[i][0] = h[i],ma[i][0] = h[i];
	for (int d=1;d<=MAXDEP;d++)
		for (int i=1;i<=N;i++)
			if (i + (1 << (d - 1)) <= N)
			{
				st[i][d] = st[i][d-1] | st[i + (1 << (d - 1))][d - 1];
				ma[i][d] = max(ma[i][d-1], ma[i + (1 << (d - 1))][d - 1]);
			}
			else
			{
				st[i][d] = st[i][d-1];
				ma[i][d] = ma[i][d-1];
			}
	/*
	for (int i=1;i<=N;i++)
		for (int j=0;j<=MAXDEP;j++)
			printf("st[%d][%d] = %d\n",i,j,st[i][j]);
	*/
	for (int i=0;i<32;i++)
		nxt[N + 1][i] = N + 1;
			
	for (int i=N;i>=1;i--)
		for (int j=0;j<32;j++)
			if (h[i] & (1<<j))
				nxt[i][j] = i;
			else
				nxt[i][j] = nxt[i+1][j];
				
	pos[32].first = N + 1;
	LL ans = 0;
	for (int i=1;i<=N;i++)
	{
		for (int j=0;j<32;j++)pos[j] = make_pair(nxt[i][j],j);
		sort(pos,pos+32);
		int vv = 0;
		int lastend = i - 1;
		for (int j=0;j<32;j++)
		{
			vv |= (1 << pos[j].second);
			if (j==31 || pos[j].first != pos[j+1].first)
			{
				if (pos[j].first == N + 1) break;
				int L = pos[j].first, R = pos[j+1].first - 1;
				if (getmax(i,R) < vv)
				{
					ans += R - L + 1;
					continue;
				}
				if (getmax(i,L) >= vv) continue;
				while(L < R - 1)
				{
					int mid = (L + R) >> 1;
					if (getmax(i,mid) < vv)
						L = mid;
					else
						R = mid;
				}
				ans += L - pos[j].first + 1; 
			}
		}
	}
	printf("%lld\n",ans);
}