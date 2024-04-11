#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define FOR(it,st,en) for(LL it=(st);it<(LL)(en);++it)
#define REP(it,en) FOR(it,0,en)
#define ITE(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define ALLOF(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define X first
#define Y second
typedef long long int LL; 
typedef long double LD;
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef pair<LL,LL> PII;
const LL INF=(LL)1e9; 
const double EPS=(LD)1e-7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	LL h,q;
	cin>>h>>q;
	map<LL,LL> M;
	M[1LL<<(h-1LL)]+=1LL;
	M[1LL<<h]-=1LL;
	REP(i,q){
		LL I,L,R,ans;
		cin>>I>>L>>R>>ans;
		while(I<h){
			L=L*2;
			R=R*2+1LL;
			I++;
		}
		if(ans){
			M[L]+=1LL;
			M[R+1LL]-=1LL;
		}
		else{
			M[1LL<<(h-1LL)]+=1LL;
			M[1LL<<h]-=1LL;
			M[L]-=1LL;
			M[R+1LL]+=1LL;
		}
	}
	bool pos=false;
	bool mulpos=false;
	LL k=0;
	LL acc=0;
	LL l=-INF;
	for(auto p:M){
		acc+=p.Y;
		// cout<<p.X<<" "<<acc<<endl;
		if(acc==q+1){
			l=p.X;
			k=p.X;
		}
		else if(l!=-INF){
			if(pos)mulpos=true;
			if(p.X-l>1)mulpos=true;
			pos=true;
			l=-INF;
		}
	}
	if(mulpos)cout<<"Data not sufficient!"<<endl;
	else if(!pos)cout<<"Game cheated!"<<endl;
	else cout<<k<<endl;
	return 0;
}