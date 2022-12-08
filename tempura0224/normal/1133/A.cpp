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
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
	int h1,m1,h2,m2;
	char c;
	cin>>h1>>c>>m1;
	cin>>h2>>c>>m2;
	int h=(h1+h2)/2;
	if((h1+h2)%2)m1+=60;
	int m=(m1+m2)/2;
	if(m>=60){
		m-=60;
		h++;
	}
	printf("%02d:%02d\n",h,m);

	return 0;
}