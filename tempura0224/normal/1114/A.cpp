#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

const int N = 200, D=16000, K=4000;

pint x[16000];

int main(){
	int a,b,c,x,y,z;
	cin>>a>>b>>c>>x>>y>>z;
	if(a>x){
		cout<<"NO"<<endl;
		return 0;
	}
	x-=a;
	if(b>x+y){
		cout<<"NO"<<endl;
		return 0;
	}
	y-=b;
	if(c>x+y+z){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	return 0;
}