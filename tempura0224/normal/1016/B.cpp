#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;

int main(){
	int n,m,q;
	cin>>n>>m>>q;
	if(n<m){
		rep(i,q)printf("%d\n",0);
		return 0;
	}
	string s,t;
	cin>>s>>t;
	vector<int> sum(n+3,0);
	rep(i,n-m+1){
		if(t==s.substr(i,t.size()))++sum[i+1];
		sum[i+2]+=sum[i+1];
	}
	rep(i,q){
		int l,r;
		scanf("%d%d",&l,&r);
		if(r-l<m-1){
			printf("0\n");
			continue;
		}
		l--;
		printf("%d\n",sum[r-m+1]-sum[l]);
	}
   return 0;
}