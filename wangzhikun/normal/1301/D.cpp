#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
	read(first);
	read(args...);
}

int n,m,k;
vector<pair<int,string>> ops;
void mv(string a,int times){
	if(!k || !times)return;
	if(times*a.length()<=k){
		ops.push_back(make_pair(times,a));
		k-=times*a.length();
	}else{
		int cc = k/a.length();
		if(cc)ops.push_back(make_pair(cc,a));
		k-=cc*a.length();
		if(k){
			ops.push_back(make_pair(1,a.substr(0,k)));
			k =0;
		}
	}
}
int main() {
	read(n,m,k);
	if(k>4*n*m-2*n-2*m){
		cout<<"NO"<<endl;
		return 0;
	}
	mv("R",m-1);
	for(int i=1;i<n;i+=1){
		mv("D",1);
		if(i%2 == 1){
			mv("LUD",m-1);
		}else{
			mv("RUD",m-1);
		}
	}
	if(n%2 == 1){
		mv("L",m-1);
	}else{
		mv("R",m-1);
	}
	for(int i=n-1;i>=1;i--){
		mv("U",1);
		if(i%2 == 1){
			mv("L",m-1);
		}else{
			mv("R",m-1);
		}
	}
	cout<<"YES\n"<<ops.size()<<endl;
	for(auto ct:ops){
		cout<<ct.first<<' '<<ct.second<<endl;
	}
	return 0;
}