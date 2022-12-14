#include<cstdio>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>

using namespace std;

vector<int> saying[2][100100];//0:+

void print(int s)
{
	switch(s)
	{
		case -1:
		printf("Not defined\n");
		break;
		case 0:
		printf("Lie\n");
		break;
		case 1:
		printf("Truth\n");
		break;
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		string in;
		cin>>in;
		int flg=(in[0]=='-');
		in[0]=' ';
		int p=atoi(in.c_str());
		p--;
		saying[flg][p].push_back(i);
	}
	int num=0;
	for(int i=0;i<n;i++)
	{
		num+=saying[1][i].size();
	}
	int target=m-num;
	int truth[100100];
	memset(truth,-1,sizeof(truth));
	vector<int> susp;
	for(int i=0;i<n;i++)
	{
		if(saying[0][i].size()-saying[1][i].size()==target)
		{
			susp.push_back(i);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<saying[1][i].size();j++)
		{
			truth[saying[1][i][j]]=1;
		}
		for(int j=0;j<saying[0][i].size();j++)
		{
			truth[saying[0][i][j]]=0;
		}
	}
	for(int i=0;i<susp.size();i++)
	{
		if(susp.size()==1)
		{
			int s=susp[0];
			for(int j=0;j<saying[0][s].size();j++)
			{
				truth[saying[0][s][j]]=1;
			}
			for(int j=0;j<saying[1][s].size();j++)
			{
				truth[saying[1][s][j]]=0;
			}
		}
		else
		{
			int s=susp[i];
			for(int j=0;j<saying[0][s].size();j++)
			{
				truth[saying[0][s][j]]=-1;
			}
			for(int j=0;j<saying[1][s].size();j++)
			{
				truth[saying[1][s][j]]=-1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		print(truth[i]);
	}
	return 0;
}