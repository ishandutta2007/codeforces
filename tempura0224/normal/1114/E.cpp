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


struct Xor128{
    unsigned x,y,z,w;
 
    Xor128(unsigned w_):x(123456789),y(362436069),z(521288629),w(w_){};
 
    inline unsigned xor128(){
        unsigned t;
        t = x^(x<<11);
        x = y;
        y = z;
        z = w;
        return w = (w^(w>>19))^(t^(t>>8));
    }
 
    int randInt(int x,int y){
        return xor128()%(y-x)+x;
    }
 
    double randDouble(double a,double b){
        return (double)(xor128()&0xffff)/0xffff*(b-a)+a;
    }
};

int gcd(int x,int y){
	if(x<y)swap(x,y);
	return y==0 ? x : gcd(y, x%y);
}

int main(){
	int n;
	cin>>n;
	int ok=0,ng=1e9+1;
	int cnt=60;
	while(ng-ok>1){
		int mid=(ok+ng)/2;
		cout<<"> "<<mid<<endl;
		int x;
		cin>>x;
		if(x)ok=mid;
		else ng=mid;
		--cnt;
	}
	int ma=ng;
	auto rnd=Xor128(1333);
	ll ret=-1;
	while(1){
		--cnt;
		cout<<"? "<<rnd.randInt(1, n+1)<<endl;
		int y;cin>>y;
		if(ma!=y){
			ret=ma-y;
			break;
		}
	}
	rep(i,cnt){
		cout<<"? "<<rnd.randInt(1, n+1)<<endl;
		int y;cin>>y;
		ret=gcd(ret,ma-y);
	}
	cout<<"! "<<ma-(n-1)*ret<<" "<<ret<<endl;
}