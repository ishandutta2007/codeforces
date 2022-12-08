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
	int n,q;
	cin>>n>>q;
	int a[n];
	rep(i,n)cin>>a[i];
	vector<vector<int>> bi(20,vector<int>(n,inf));
	rep(j,20){
		int ok=inf;
		for(int i=n-1;i>=0;i--){
			if(a[i]&(1<<j)){
				bi[j][i]=ok;
				ok=i;
			}
		}
	}
	while(1){
		bool update=false;
		for(int i=n-1;i>=0;--i){
			rep(j,20){
				if(bi[j][i]==inf)continue;
				int nxt=bi[j][i];
				rep(k,20){
					if(bi[k][i]>bi[k][nxt]){
						update=true;
						bi[k][i]=bi[k][nxt];
					}
				}
			}
		}
		if(!update)break;
	}
	while(q--){
		int x,y;
		scanf(" %d %d ",&x,&y);
		--x;--y;
		bool ok=false;
		rep(i,20){
			if(bi[i][x]<=y&&((1<<i)&a[y])){
				ok=true;
				printf("Shi\n");
				break;
			}
		}
		if(!ok)printf("Fou\n");
	}
	return 0;
}