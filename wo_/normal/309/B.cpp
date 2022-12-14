#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>

using namespace std;

int ln[1100100];
int nxt[1100100][22];

string strs[1100100];

char ch[5500500];

int main()
{
	int N,R,C;
	scanf("%d%d%d",&N,&R,&C);
	for(int i=0;i<N;i++)
	{
		scanf("%s",ch);
		string tmp(ch);
		ln[i]=strlen(ch)+1;
		strs[i]=tmp;
	}
	C++;
	int s=0,t=0;
	int nl=0;
	while(s<N)
	{
		while(t<N&&nl<=C)
		{
			if(nl+ln[t]<=C)
			{
				nl+=ln[t];
				t++;
			}
			else break;
		//	if(s==0) printf("%d %d\n",t,nl);
		}
		nxt[s][0]=t;
		nl-=ln[s];
		s++;
	}
	//printf("%d\n",nxt[0][0]);
	for(int j=1;j<22;j++)
	{
		for(int i=0;i<N;i++)
		{
			if(nxt[i][j-1]==N) nxt[i][j]=N;
			else nxt[i][j]=nxt[nxt[i][j-1]][j-1];
		}
	}
	int max_words=-1;
	int max_id=-1;
	for(int i=0;i<N;i++)
	{
		int tmp=i;
		for(int j=0;j<22;j++)
		{
			if(((R>>j)&1)==1) tmp=nxt[tmp][j];
			if(tmp==N) break;
		}
		if(max_words<tmp-i)
		{
			max_words=tmp-i;
			max_id=i;
		}
	}
	if(max_id==-1)
	{
		printf("\n");
		return 0;
	}
//	for(int i=0;i<N;i++) printf("%d ",ln[i]);
//	printf("\n");
	int id=max_id;
	for(int i=0;i<R;i++)
	{
		for(int j=id;j<nxt[id][0];j++)
		{
			printf("%s%c",strs[j].c_str(),j==nxt[id][0]-1?'\n':' ');
		}
		id=nxt[id][0];
		if(id==N) break;
	}
	return 0;
}