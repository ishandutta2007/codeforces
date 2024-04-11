#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld; 
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;
#define _  %  MODULUS
#define __ %= MODULUS


#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

int a[200009];

int main(){
	int n,m;
	cin>>n>>m;
	int a[min(m,n)][max(m,n)],r[min(m,n)],c[max(m,n)],min=501,xx=0;
	
	if (n>m)
	{
		xx=1;
		for (int i = 0; i < n; ++i)
		{
			for(int j=0;j<m;j++){
				cin>>a[j][i];
				
			}
		}
		int t =m;
		m=n;
		n=t;
	}
	else{
		for (int i = 0; i < n; ++i)
		{
			for(int j=0;j<m;j++){
				cin>>a[i][j];
				
			}
		}
	}
	for (int i = 0; i < m; ++i)
	{
		if (min>a[0][i])
		{
			min=a[0][i];
		}
	}
	
	int ans=0;
	for (int i = min; i >=0 ; --i)
	{
		r[0]=i;
		for (int i = 0; i < m; ++i)
		{
			c[i]=max(a[0][i]-r[0],0);
		}
		for (int i = 1; i <n ; ++i)
		{
			r[i]=max(a[i][0]-c[0],0);
		}
		int flag =0;
		for (int i = 0; i < n; ++i)
		{
			for(int j=0;j<m;j++){
				if (a[i][j]!=r[i]+c[j])
				{
					flag=1;
					break;
				}
			}
			if (flag)
			{
				break;
			}
		}

		if (flag==0)
		{
			ans=0;
			for (int i = 0; i < n; ++i)
			{
				ans+=r[i];
			}
			for (int i = 0; i < m; ++i)
			{
				ans+=c[i];
			}
			cout<<ans<<endl;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < r[i]; ++j)
				{
					if (xx==0)
					{
						cout<<"row "<<i+1<<endl;
					}
					else{
						cout<<"col "<<i+1<<endl;
					}
				}
			}
			for (int i = 0; i < m; ++i)
			{
				for (int j = 0; j < c[i]; ++j)
				{
					if (xx==0)
					{
						cout<<"col "<<i+1<<endl;
					}
					else {
						cout<<"row "<<i+1<<endl;
					}
				}
			}
			ans=1;
			break;
		}

	}
	if (ans==0)
	{
		cout<<-1<<endl;
	}

	return 0;
}