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
	int sum[3]={0,0,0};
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>s[i];
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (s[i][j]=='X')
				sum[(i+j)%3]++;
	int mi=0;
	for (int i=1;i<3;i++)
		if (sum[i]<sum[mi])
			mi=i;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (s[i][j]=='X' && (i+j)%3==mi)
				s[i][j]='O';
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