#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 410000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

char s[MAXN];
int sum[MAXN][26]; 
int q;
int x,y;
set<int> st;

int main()
{
	cin>>s;
	st.insert(1);
	int len=strlen(s);
	for (int i=1;i<=len;i++)
		for (int j=0;j<26;j++)
			sum[i][j]=sum[i-1][j]+(s[i-1]==(j+'a'));
	/*
	for (int i=2;i<=len;i++)
		if (s[i-1]!=s[i-2])
		{
			st.insert(i);
			//WRT(i);
		}
	*/
	cin>>q;
	while (q--)
	{
		scanf("%d%d",&x,&y);
		if (y==x)
		{
			cout<<"Yes"<<endl;
			continue;
		}
		int tmp[26];
		vector<int> v;
		for (int i=0;i<26;i++)
		{
			tmp[i]=sum[y][i]-sum[x-1][i];
			if (tmp[i])
				v.push_back(tmp[i]);
		}
		if (v.size()==1)
		{
			cout<<"No"<<endl;
			continue;
		}
		if (v.size()==2 && s[x-1]==s[y-1])
		{
			cout<<"No"<<endl;
			continue;
		}
		cout<<"Yes"<<endl;
		/*
		if (st.upper_bound(x)==st.upper_bound(y))
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
		*/
	}
	return ~~(0^_^0);
}