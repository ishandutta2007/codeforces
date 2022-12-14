#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

vector<int> prices[1010];
vector<int> vals;
int less[1010]={},more[1010]={},same[1010]={};

double dp[2][1010];
double ways[2][1010];

double C[1010][1010];
bool saw[1010][1010];

double combi(int a,int b)
{
	//aCb
	if(saw[a][b]) return C[a][b];
	saw[a][b]=true;
	double res=1;
	for(int i=0;i<b;i++)
	{
		res*=(a-i);
		res/=(b-i);
	}
	C[a][b]=res;
	return res;
}

int main()
{
	int N,M,K;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		scanf("%d",&K);
		for(int j=0;j<K;j++)
		{
			int a;
			scanf("%d",&a);
			prices[i].push_back(a);
			vals.push_back(a);
		}
	}
	sort(vals.begin(),vals.end());
	reverse(vals.begin(),vals.end());
	int border=vals[N-1];
	int id;
	for(int i=0;i<N;i++)
	{
		if(vals[i]==vals[N-1])
		{
			id=i;
			break;
		}
	}
	//take gifts price of vals[N-1] N-id times
	int take=N-id;
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<prices[i].size();j++)
		{
			if(prices[i][j]>border) more[i]++;
			else if(prices[i][j]==border) same[i]++;
			else less[i]++;
		}
	}
	memset(saw,false,sizeof(saw));
	//dp[i]=chose i same price and took perfectly
	int t=0;
	for(int i=0;i<=take;i++)
	{
		dp[0][i]=0;
		ways[0][i]=0;
	}
	dp[0][0]=1.0;
	ways[0][0]=1.0;
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<=take;j++)
		{
			dp[1-t][j]=0;
			ways[1-t][j]=0;
			for(int k=0;k<=min(j,same[i]);k++)
			{
				double den=combi(prices[i].size(),more[i]+k);
				double num=combi(same[i],k);
				dp[1-t][j]+=(num/den)*dp[t][j-k];
				ways[1-t][j]+=num*ways[t][j-k];
			}
		}
		t=1-t;
	}
	printf("%.12f\n",dp[t][take]/ways[t][take]);
	return 0;
}