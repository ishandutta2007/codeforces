#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXDEP = 19;
LL w[400010];
int N,d[400010];
int anc[400010][MAXDEP + 1]; 
LL sum[400010][MAXDEP + 1];

typedef long long LL;

int main()
{
	N = 1;
	w[1] = 0;
	w[0] = 1e9 + 10;
	d[1] = 1;
	int Q;
	LL last = 0;
	scanf("%d",&Q);
	while(Q--)
	{
		LL type,p,q;
		scanf("%lld%lld%lld",&type,&p,&q);
		LL R,W,X;
		R = p ^ last;
		W = q ^ last;
		X = q ^ last;
		if (type == 1)
		{
			N++;
			w[N] = W;
			LL now = R;
			//d[N] = d[R] + 1;
			if (w[R] >= w[N])
			{
				anc[N][0] = R;
			}
			else
			{
				for (int i=MAXDEP;i>=0;i--)
				if (w[anc[R][i]] < w[N]) 
					R = anc[R][i];
				anc[N][0] = anc[R][0];
			}
			d[N] = d[anc[N][0]] + 1;
			for (int i=1;i<=MAXDEP;i++)anc[N][i] = anc[anc[N][i-1]][i-1];
			sum[N][0] = w[N];
			for (int i=1;i<=MAXDEP;i++)sum[N][i] = sum[N][i-1] + sum[anc[N][i-1]][i-1]; 
			//printf("N = %d\n",N);
			//for (int i=0;i<=2;i++)printf("%d %d %d\n",i,anc[N][i],sum[N][i]);
		}
		else
		{
			int ans = 0;
			for (int i=MAXDEP;i>=0;i--)
			{
				if ((1 << i) <= d[R] && sum[R][i] <= X)
				{
					X -= sum[R][i];
					R = anc[R][i];
					ans += (1 << i);
				}
			}
			printf("%d\n",ans);
			last = ans;
		}
	} 
}