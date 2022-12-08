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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n;
	cin>>n;
	int a[n];
	vector<int> leaf,node;
	int sum=0;
	rep(i,n){
		cin>>a[i];
		sum+=a[i];
		if(a[i]==1)leaf.push_back(i);
		else node.push_back(i);
	}
	if(sum<2*n-2){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES ";
	int ret=node.size();
	int res=leaf.size();
	cout<<ret+min(2,res)-1<<endl;
	cout<<n-1<<endl;
	rep(i,ret-1){
		cout<<node[i]+1<<" "<<node[i+1]+1<<endl;
		--a[node[i]];
		--a[node[i+1]];
	}
	int i=0;
	rep(j,res-1){
		while(a[node[i]]==0)++i;
		cout<<leaf[j]+1<<" "<<node[i]+1<<endl;
		--a[node[i]];
	}
	if(res)cout<<leaf[res-1]+1<<" "<<node[ret-1]+1<<endl;
    return 0;
}