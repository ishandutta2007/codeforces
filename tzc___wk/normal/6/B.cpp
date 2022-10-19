#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
bool used[26];
int x,y,k=0,l=0,ans=0;
char c;
char grid[1100][1100];
void check(int a,int b)
{
	if(grid[a][b]!='\0'&&grid[a][b]!='.'&&!used[grid[a][b]-'A'])
	{
		ans++;
		used[grid[a][b]-'A']=true;
	}	
}
void loc()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(grid[i][j]==c)
			{
				x=i,y=j;
				return;
			}
		}	
	}	
}
void len()
{
	for(int i=y;i<m;i++)
	{
		if(grid[x][i]==c)	k++;
	}
	for(int i=x;i<n;i++)
	{
		if(grid[i][y]==c)	l++;
	}
}
void find()
{
	for(int i=y;i<y+k;i++)	check(x-1,i);
	for(int i=y;i<y+k;i++)	check(x+l,i);
	for(int i=x;i<x+l;i++)	check(i,y-1);
	for(int i=x;i<x+l;i++)	check(i,y+k);
}
int main()
{
	cin>>n>>m>>c;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>grid[i][j];
	loc();len();
	//cout<<x<<" "<<y<<endl<<k<<" "<<l<<endl;
	find();
	cout<<ans<<endl;
	return 0;
}