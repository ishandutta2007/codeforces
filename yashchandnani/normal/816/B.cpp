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
	int n,q,k;
	cin>>n>>k>>q;
	int l,r;
	vi t;
	for (int i = 0; i < n; ++i)
	{
		cin>>l>>r;
		a[l]++;
		a[r+1]--;
	}
	for (int i = 1; i <200007 ; ++i)
	{
		a[i]=a[i]+a[i-1];
		if (a[i]>=k)
		{
			t.push_back(i);
		}
	}

	for (int i = 0; i < q; ++i)
	{
		cin>>l>>r;
		l=lower_bound(t.begin(),t.end(),l)-t.begin();
		r=upper_bound(t.begin(),t.end(),r)-t.begin();
		cout<<r-l<<endl;
	}

	return 0;
}