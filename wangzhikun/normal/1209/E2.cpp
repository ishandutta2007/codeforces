#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int T,n,m;
struct ech{
	int val[30],kv;
	bool operator < (const ech &rhs) const{
		return kv<rhs.kv;
	}
}alv[4040];

void solve(){
	set0(alv);
	read(n);read(m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			read(alv[j].val[i]);
			alv[j].val[i+n] = alv[j].val[i];
			alv[j].kv = max(alv[j].kv,alv[j].val[i]);
		}
	}
	sort(alv,alv+m);
	int dp[2][5000] = {0},cv[5000] = {0};
	int cuu = 0;
	for(int i=m-1;i>=max(m-n-1,0);i--){
		set0(cv);
		set0(dp[cuu^1]);
		//cout<<i<<endl;
		for(int j=0;j<1<<n;j++){
			//cout<<"   "<<j<<' '<<dp[cuu][j]<<endl;;
			for(int k=0;k<n;k++){
				int cu = 0;
				for(int x=0;x<n;x++){
					if((j>>x)&1)cu+=alv[i].val[x+k];
				}
				cv[j] = max(cv[j],cu);
			}
		}
		for(int j=0;j<1<<n;j++){
			for(int k=j;;k = (k-1)&j){
				dp[cuu^1][j] = max(dp[cuu^1][j],dp[cuu][k]+cv[k^j]);
				if(k == 0)break;
			}
		}
		cuu^=1;
	}
	cout<<dp[cuu][(1<<n)-1]<<endl;
}

int main() {
	read(T);
	while(T--){
		solve();
	}
	return 0;
}