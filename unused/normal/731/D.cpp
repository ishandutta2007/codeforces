#include "bits/stdc++.h"
using namespace std;

bool stree[2097155];
void update(int s,int e)
{
	s+=1048576;e+=1048576;
	while(s<=e)
	{
		if(s&1)stree[s++]=true;
		if(~e&1)stree[e--]=true;
		s>>=1;e>>=1;
	}
}
bool query(int s)
{
	for(s+=1048576;s>=1;s>>=1)
		if(stree[s])return true;
	return false;
}

vector<int> seq[500005];

int main()
{
	int n, c;
	scanf("%d%d",&n,&c);
	for (int i = 0; i < n; i++)
	{
		int t;
		scanf("%d",&t);
		seq[i].resize(t);
		for (int j = 0; j < t; j++)
		{
			scanf("%d",&seq[i][j]);
			--seq[i][j];
		}
	}

	int right = c - 1, left = 0;

	for (int i = 1; i < n; i++)
	{
		int minsize = min(seq[i-1].size(), seq[i].size());
		int j;
		for (j = 0; j < minsize; j++)
		{
			if (seq[i-1][j] != seq[i][j]) break;
		}

		if (j == minsize)
		{
			if (seq[i-1].size() > seq[i].size())
			{
				printf("-1");
				return 0;
			}
			continue;
		}

		// seq[i-1][j], seq[i][j]
		if (seq[i-1][j] > seq[i][j])
		{
			// 0 ~ c - seq[i-1][j] - 1 : false
			// c - seq[i-1][j] ~ c - seq[i][j] - 1 : true
			// c - seq[i][j] ~ c - 1 : false
			update(0, c-seq[i-1][j]-1);
			update(c-seq[i][j],c-1);
		}
		else
		{
			// 0 ~ c - seq[i][j] - 1 : true
			// c - seq[i][j] ~ c - seq[i-1][j] - 1 : false
			// c - seq[i-1][j] ~ c - 1 : true
			update(c-seq[i][j],c-seq[i-1][j]-1);
		}
	}

	for(int i=0;i<c;i++) if(query(i)==false) { printf("%d",i);return 0;}
	printf("-1");
}