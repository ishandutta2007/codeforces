#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=500050;
const int S=700;
int sum[S][S],a[N];
int main()
{
	int q;
	scanf("%i",&q);
	//q=N;
	//srand(time(0));
	while(q--)
	{
		int t,x,y;
		scanf("%i %i %i",&t,&x,&y);
		//t=rand()&1;
		//x=rand()%(N-1)+1;
		//y=rand()%2001-1000;
		if(t==1)
		{
			a[x]+=y;
			for(int i=1;i<S;i++) sum[i][x%i]+=y;
		}
		else
		{
			if(x<S) printf("%i\n",sum[x][y]);
			else
			{
				int tmp=0;
				for(int i=y;i<N;i+=x) tmp+=a[i];
				printf("%i\n",tmp);
			}
		}
	}
	//printf("%.3f\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}