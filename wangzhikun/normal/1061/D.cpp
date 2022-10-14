#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
priority_queue< pii,vector<pii>,greater<pii> > Q;
priority_queue< int,vector<int>,less<int> > Q2;
priority_queue< int,vector<int>,greater<int> > Q3;
int n,x,y,l,r;
ll mod = 1e9+7;
int main() {
	read(n);read(x);read(y);
	for(int i=0;i<n;i++){
		read(l);read(r);
		Q.push(make_pair(l,r));
	}
	ll ans = 0;
	while(!Q.empty()){
		pii c = Q.top();Q.pop();
		while(!Q3.empty()){
			int f = Q3.top();
			if(f>=c.first)break;
			Q3.pop();
			Q2.push(f);
		}
		//int lans = ans;
		
		if(!Q2.empty()){
			int lt = Q2.top();Q2.pop();
			if(1ll*(c.first-lt)*y<x){
				ans+= (1ll*(c.second-lt)*y)%mod;
			}else{
				ans+= (1ll*(c.second-c.first)*y+x)%mod;
			}
		}else{
			ans+= (1ll*(c.second-c.first)*y+x)%mod;
		}
		//cout<<c.first<<' '<<ans-lans<<endl;
		Q3.push(c.second);
	}
	cout<<ans%mod<<endl;
	return 0;
}