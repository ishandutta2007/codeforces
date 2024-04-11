#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef pair<int,int>ii;
const int N = 100009, M = 2 * N;
vector<pair<int,int> >a[3000];
int n,ans,cnt[2];
void gao1(int x,int f = -1)
{
	fe(i,a[x])
	if(i->X!=f)
	{
		cnt[i->Y]++;
		gao1(i->X,x);
	}
}

int gao2(int x,int f=-1)
{
	int re=0;
	fe(i,a[x])
		if(i->X!=f)
			re=min(re,gao2(i->X,x)+(i->Y?-1:1));
	ans=min(ans,cnt[1]+re);
	return re;
}
int main()
{
	cin>>n;
	ans=n-1;
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		a[x].push_back(make_pair(y,0));
		a[y].push_back(make_pair(x,1));
	}
	for(int i=0;i<n;i++)
	{
		cnt[0]=cnt[1]=0; gao1(i);
		if(ans>cnt[1])
			ans=cnt[1];
		gao2(i);
	}
	cout<<ans<<endl;
}