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

int n,m;

vector<pii> E;
set<pii> S;
int cok[100010];
int main() {
	read(n);read(m);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		if(u>v)swap(u,v);
		E.push_back(make_pair(u,v));
		S.insert(make_pair(u,v));
	}
	for(int i=1;i<n;i++){
		if(n%i!=0)continue;
		int cok = 1;
		for(auto ct:E){
			int c1 = ct.first,c2 = ct.second;
			c1 = (c1+i)%n;
			c2 = (c2+i)%n;
			if(c1>c2)swap(c1,c2);
			if(!S.count(make_pair(c1,c2))){
				cok = 0;
				break;
			}
		}
		if(cok){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}