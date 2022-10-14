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
const int N = 1000010;
ll n,w,l[N];
ll s[N] = {0};
struct S{
	int p,v,typ;
	bool operator < (const S &rhs) const{
		if(p == rhs.p)return typ>rhs.typ;
		return p<rhs.p;
	}
};

int main() {
	read(n);read(w);
	for(int i=0;i<n;i++){
		//cout<<"##"<<endl;
		int m;
		read(m);
		vector<S> P;
		P.push_back((S){1,0,1});
		P.push_back((S){w-m+1,0,-1});
		P.push_back((S){m+1,0,1});
		P.push_back((S){w+1,0,-1});
		for(int i=1;i<=m;i++){
			read(l[i]);
			P.push_back((S){i,l[i],1});
			P.push_back((S){i+w-m+1,l[i],-1});
		}
		sort(P.begin(),P.end());
		multiset<int> cs;
		for(int i=0;i<P.size()-1;i++){
			S c = P[i];
			if(c.typ == 1){
				cs.insert(c.v);
			}else{
				cs.erase(cs.find(c.v));
			}
			if(P[i].p!=P[i+1].p){
				s[P[i].p]+=*cs.rbegin();
				s[P[i+1].p]-=*cs.rbegin();
			}
		}
	}
	for(int i=1;i<=w;i++){
		s[i]+=s[i-1];
		cout<<s[i]<<' ';
	}
	cout<<endl;
	return 0;
}