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

int gcd (int a,int b){
	if(a%b==0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}
}

int main(){

	int n,m,z;
	cin>>n>>m>>z;
	if (n<m)
	{
		int t=n;
		n=m;
		m=t;
		
	}
	cout<<z/(n*m/gcd(n,m));
	return 0;
}