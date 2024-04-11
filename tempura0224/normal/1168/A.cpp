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
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
	int n,m;
	cin>>n>>m;
	int a[n];
	rep(i,n)cin>>a[i];
	int ok=m+1,ng=-1;
	while(ok-ng>1){
		int mid=(ok+ng)/2;
		int cur=0;
		bool can=true;
		rep(i,n){
			if(a[i]+mid<m){
				if(a[i]+mid<cur)can=false;
				else {
					cur=max(cur,a[i]);
				}
			}
			else {
				int x=(a[i]+mid)%m;
				if(x>=cur)continue;
				else cur=max(cur,a[i]);
			}
		}
		if(can)ok=mid;
		else ng=mid;
	}
	cout<<ok<<endl;
	return 0;
}