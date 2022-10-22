#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 10000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;
typedef pair<int,int> pii ;
int d[2010000];
int n,m;
string s[1010000];
queue<pii> q;
int * ptr1[1010000],* ptr2[1010000];
int main()
{
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		ptr1[i]=new int[m];
		ptr2[i]=new int[m];
		for (int j=0;j<m;j++)
			ptr1[i][j]=ptr2[i][j]=INF;
		cin>>s[i];
		//cout<<s[i]<<endl;;
	}
	ptr1[0][0]=0;
	q.push({0,0});
	while (!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		//cout<<x<<' '<<y<<' '<<s[x][y]<<endl;
		q.pop();
		if (x<n && y+1<m && s[x][y+1]!='#')
		{
			if (ptr1[x][y+1]==INF)
			{
				ptr1[x][y+1]=ptr1[x][y]+1;
				q.push({x,y+1});
			}
		}
		if (x+1<n && y<m && s[x+1][y]!='#')
		{
			if (ptr1[x+1][y]==INF)
			{
				ptr1[x+1][y]=ptr1[x][y]+1;
				q.push({x+1,y});
			}
		}
	//WRT(q.empty());
	}
	ptr2[n-1][m-1]=0;
	q.push({n-1,m-1});
	while (!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		//MRK();
		//cout<<x<<' '<<y<<endl;
		//cout<<ptr2[x][y]<<' '<<ptr1[x][y]<<endl;
		if (ptr2[x][y]+ptr1[x][y]==n+m-2)
			d[x+y]++;
		if (y && s[x][y-1]!='#')
		{
			if (ptr2[x][y-1]==INF)
			{
				ptr2[x][y-1]=ptr2[x][y]+1;
				q.push({x,y-1});
			}
		}
		if (x && s[x-1][y]!='#')
		{
			if (ptr2[x-1][y]==INF)
			{
				ptr2[x-1][y]=ptr2[x][y]+1;
				q.push({x-1,y});
			}
		}
	}
	bool f=false;
	if (ptr1[n-1][m-1]==INF)
		f=true;
	for (int i=0;i<n;i++)
	{
		delete ptr1[i];
		delete ptr2[i];
	}
	if (f)
	{
		cout<<0;
		return 0;
	}
	for (int i=1;i<=n+m-3;i++)
	{
		//cout<<i<<' '<<d[i]<<endl;
		if (d[i]==1)
		{
			cout<<1;
			return 0;
		}
	}
	cout<<2;
	return ~~(0^_^0);
}