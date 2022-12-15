
#include<bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)
#define forsn(i,s,n) for(int i=s;i<n;i++)
#define rforn(i,n) for(int i=n;i>=0;i--)
#define rforsn(i,s,n) for(int i=n;i>=s;i--)
#define forstl(p,s) for(auto p:s)

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;

const int MOD=1e9+7;

int main(){
	ios::sync_with_stdio(false);
	int n;cin>>n;
	i64 sumx=0,sumy=0;
	forn(i,2*n){
		int x,y;cin>>x>>y;
		sumx+=x;
		sumy+=y;
	}
	cout<<sumx/n<<" "<<sumy/n<<endl;
	return 0;
}