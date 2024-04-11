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

int n;
struct P{
	int id,a,b,c;
	bool operator < (const P &rhs) const{
		if(a!=rhs.a)return a<rhs.a;
		if(b!=rhs.b)return b<rhs.b;
		if(c!=rhs.c)return c<rhs.c;
		return id<rhs.id;
	}
};
vector<P> TP;
int main() {
	read(n);
	TP = vector<P>(n);
	for(int i=0;i<n;i++){
		TP[i].id = i+1;
		read(TP[i].a);
		read(TP[i].b);
		read(TP[i].c);
	}
	sort(TP.begin(),TP.end());
	vector<P> NP,MP,SP;
	for(auto ct:TP){
		if(NP.size() == 0 || NP[NP.size()-1].a!=ct.a || NP[NP.size()-1].b!=ct.b){
			NP.push_back(ct);
		}else{
			cout<<NP[NP.size()-1].id<<' '<<ct.id<<endl;
			NP.pop_back();
		}
	}
	for(auto ct:NP){
		if(MP.size() == 0 || MP[MP.size()-1].a!=ct.a){
			MP.push_back(ct);
		}else{
			cout<<MP[MP.size()-1].id<<' '<<ct.id<<endl;
			MP.pop_back();
		}
	}
	for(int i=0;i<MP.size();i+=2){
		cout<<MP[i].id<<' '<<MP[i+1].id<<endl;
	}
	return 0;
}