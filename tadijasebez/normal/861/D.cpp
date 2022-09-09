#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=70050;
const int M=N*11;
int Trie[M][10],clock,x[M];
char word[20];
char words[N][20];
void Set(int &c, int pos, int ind)
{
	if(!c) c=++clock;
	if(!x[c] || x[c]==ind) x[c]=ind;
	else x[c]=-1;
	if(pos==9) return;
	Set(Trie[c][word[pos]-'0'],pos+1,ind);
}
int ans;
int min(int a, int b){ return a>b?b:a;}
void FindMin(int c, int pos, int depth, int ind)
{
	if(!c || x[c]==ind) ans=min(ans,depth);
	else
	{
		if(pos==9) return;
		FindMin(Trie[c][word[pos]-'0'],pos+1,depth+1,ind);
	}
}
pair<int,int> sol;
int main()
{
	int n,i,j,root=0;
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",&words[i]);
		for(j=0;j<9;j++) word[j]=words[i][j];
		for(j=0;j<9;j++) Set(root,j,i+1);
	}
	if(n==1)
	{
		printf("%c\n",words[0][0]);
		return 0;
	}
	for(i=0;i<n;i++)
	{
		sol.first=0;
		sol.second=8;
		for(j=0;j<9;j++) word[j]=words[i][j];
		for(j=0;j<9;j++)
		{
			ans=11;
			FindMin(root,j,0,i+1);
			if(ans!=11)
			{
				//printf(":D");
				if(ans-1<sol.second-sol.first)
				{
					sol=make_pair(j,ans+j-1);
				}
			}
		}
		if(sol.first>sol.second)
		{
			printf("%c",word[0]);
		}
		for(j=sol.first;j<=sol.second;j++)
		{
			printf("%c",word[j]);
		}
		printf("\n");
	}
}