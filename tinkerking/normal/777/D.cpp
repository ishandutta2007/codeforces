#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector<char>s[500010];
vector<LL>f[500010],minf[500010]; 
vector<int>jc[500010],from[500010];
int N,len[500010];
char tmp[500010];
const LL INF = 1000000;

void print(int x,int y)
{
	if (x>1)print(x-1,from[x][y]);
	for (int i=0;i<=y;i++)printf("%c",s[x][i]); 
	puts("");
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%s",tmp);
		len[i]=strlen(tmp);
		for (int j=0;j<len[i];j++)s[i].push_back(tmp[j]);
	}
	//0 1 2
	//2 1 0
	for (int i=0;i<len[1];i++)
	{
		f[1].push_back(len[1] - 1 - i);
		minf[1].push_back(len[1] - 1 - i);
		jc[1].push_back(i);
	}
	for (int i=2;i<=N;i++)
	{
		int cmp=0,cutp;
		for (int j=0;j<len[i];j++)
		{
			int res;
			if (cmp==0)
			{
				if (j>=len[i-1] || s[i][j] > s[i-1][j]) cmp = 1;
				if (j<len[i-1] && s[i][j] < s[i-1][j]) 
				{
					cmp = -1;
					cutp = j;
				}
			}
			
			res = (len[i] - 1 - j);
			if (cmp==-1)
			{
				res += minf[i-1][cutp-1];
				from[i].push_back(jc[i-1][cutp-1]);
			}
			if (cmp==0)
			{
				res += minf[i-1][j];
				from[i].push_back(jc[i-1][j]);
			}
			if (cmp==1)
			{
				res += minf[i-1][len[i-1]-1];
				from[i].push_back(jc[i-1][len[i-1]-1]);
			}
			
			f[i].push_back(res);
			
			if (j==0) 
			{
				minf[i].push_back(f[i][0]);
				jc[i].push_back(0); 
			}
			else 
			{
				if (f[i][j]<minf[i][j-1])
				{
					minf[i].push_back(f[i][j]);
					jc[i].push_back(j); 
				}
				else
				{
					minf[i].push_back(minf[i][j-1]);
					jc[i].push_back(jc[i][j-1]);
				}
				
			} 
		}
	}
	/*
	for (int i=1;i<=N;i++)
	{
		for (int j=0;j<len[i];j++)
		{
			printf("%d ",f[i][j]);
		}
		puts("");
	}
	for (int i=2;i<=N;i++)
	{
		for (int j=0;j<len[i];j++)
		{
			printf("%d ",from[i][j]);
		}
		puts("");
	}
	printf("%d\n",minf[N][len[N]-1]);
	*/
	print(N,jc[N][len[N]-1]);
}