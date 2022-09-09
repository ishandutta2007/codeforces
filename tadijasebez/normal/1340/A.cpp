#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a,T b){T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a,T b){T c=a;a=max(a,b);return a!=c;}
const int N=100050;
struct DSU{
	int p[N],sz[N],n;
	multiset<int> all;
	void init(int _n){
		all.clear();n=_n;
		for(int i=1;i<=n+1;i++){
			p[i]=i;
			sz[i]=1;
			if(i!=n+1)all.insert(sz[i]);
		}
	}
	int Find(int x){return x==p[x]?x:p[x]=Find(p[x]);}
	void Union(int x,int y){
		x=Find(x);y=Find(y);
		all.erase(all.find(sz[x]));
		if(y!=n+1)all.erase(all.find(sz[y]));
		sz[y]+=sz[x];
		p[x]=y;
		if(y!=n+1)all.insert(sz[y]);
	}
	int MX(){return *all.rbegin();}
}DS;
int main(){
	int t;
	scanf("%i",&t);
	while(t--){
		int n;
		scanf("%i",&n);
		vector<int> p(n+1),pos(n+1);
		for(int i=1;i<=n;i++)scanf("%i",&p[i]),pos[p[i]]=i;
		bool ok=1;
		DS.init(n);
		for(int i=1;i<=n;i++){
			int j=pos[i];
			if(DS.sz[j]==DS.MX()){
				DS.Union(j,j+1);
			}else{ok=0;break;}
		}
		if(ok)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}