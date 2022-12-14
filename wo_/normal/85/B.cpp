#include<cstdio>
#include<queue>
#include<iostream>

using namespace std;

long long times[100100][4];

int num[3],t[3];

int main()
{
	int N;
	scanf("%d%d%d",num,num+1,num+2);
	scanf("%d%d%d",t,t+1,t+2);
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		times[i][0]=tmp;
	}
	for(int w=0;w<3;w++)
	{
		//w->w+1
		queue<long long> que;
		for(int i=0;i<N;i++)
		{
			if(que.size()<num[w])
			{
				times[i][w+1]=times[i][w]+t[w];
				que.push(times[i][w]+t[w]);
			}
			else if(que.front()<=times[i][w])
			{
				while(!que.empty()&&que.front()<=times[i][w])
				{
					que.pop();
				}
				times[i][w+1]=times[i][w]+t[w];
				que.push(times[i][w]+t[w]);
			}
			else
			{
				times[i][w+1]=que.front()+t[w];
				que.push(times[i][w+1]);
				que.pop();
			}
		}
	}
	long long M=0;
	for(int i=0;i<N;i++)
	{
		M=max(M,times[i][3]-times[i][0]);
	}
	//printf("%d\n",M);
	cout<<M<<"\n";
	return 0;
}