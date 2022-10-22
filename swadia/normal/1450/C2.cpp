#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))

#ifdef _DEBUG_
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;
#else
#define MRK() ;
#define WRT(x) ;
#endif

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n,k;
char s[310][310];

void work()
{
	int sum[2][3]={{0,0,0},{0,0,0}};
	int f[2][3]={{0,0,0},{0,0,0}};
	int tot=0;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>s[i];
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		{
			if (s[i][j]=='X')
				sum[0][(i+j)%3]++;
			if (s[i][j]=='O')
				sum[1][(i+j)%3]++;
		}
	for (int i=0;i<2;i++)
		for (int j=0;j<3;j++)
			tot+=sum[i][j];
	int mix=0;
	int miy=0;
	bool fxxk=0;
	for (mix=0;mix<3;mix++)
	{
		for (miy=0;miy<3;miy++)
		{
			if (mix==miy)
			{
				continue;
			}
			if (sum[1][mix]+sum[0][miy]<=tot/3)
			{
				MRK();
				//WRT(sum[1][mix]+sum[0][miy])
				//WRT(tot/3)
				fxxk=1;
				break;
			}
		}
		if (fxxk)
			break;
	}
		/*
	int val=INF;
	for (int i=0;i<2;i++)
		for (int j=0;j<3;j++)
			if (sum[i][j]+sum[i^1][(j+1)%3]+sum[i^1][(j+2)%3]<val)
			{
				mix=i;
				miy=j;
			}
	f[mix][miy]=1;
	f[mix^1][(miy+1)%3]=1;
	f[mix^1][(miy+2)%3]=1;
	*/
	int cnt=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		{
			if (s[i][j]=='.')
				continue;
			if ((i+j)%3==mix)
			{
				if (s[i][j]!='X')
					cnt++;
				s[i][j]='X';
			}
			if ((i+j)%3==miy)
			{
				if (s[i][j]!='O')
					cnt++;
				s[i][j]='O';
			}
		}
	WRT(cnt)
	for (int i=0;i<n;i++)
		cout<<s[i]<<endl;
	
}

int main()
{
	#ifdef _DEBUG_
	freopen("C:/Users/DELL/Documents/Dev-C++/sample.in","r",stdin);
	#endif
	int t;
	cin>>t;
	while (t--)
		work();
	return ~~(0^_^0);
}