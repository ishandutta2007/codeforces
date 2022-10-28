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

int f(int x){
	return (10*(x%10)+x/10);
}

int main(){
	int h=0,m=0;
	char c;
	for (int i = 0; i < 2; ++i)
	{
		cin>>c;
		h*=10;
		h+=c-'0';
	}
	cin>>c;
	for (int i = 0; i < 2; ++i)
	{
		cin>>c;
		m*=10;
		m+=c-'0';
	}
	int p=h;
	if (f(h)>=m&&f(h)<60)
	{
		cout<<f(h)-m<<endl;
		return 0;
	}
	else{
		h++;
		h%=24;
	}
	while(f(h)>=60){
		h++;
		h%=24;
	}
	cout<<((h-p+24)%24)*60+f(h)-m;

	return 0;
}