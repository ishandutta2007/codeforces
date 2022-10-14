// Author : WangZhikun
// Date   : 2018.09.06

#include <cmath>
#include <queue>
#include <chrono>
#include <random>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;ll f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch = getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch = getchar();}x*=f;
}
char e[20];
ll l,r,n,k;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main(){
	read(n); read(k);
	l = 1;r = n;
	while(1){
		while(r-l>50){
			cout<<l<<' '<<(r+l)/2<<endl;
			cout.flush();
			cin>>e;
			if(e[0] == 'Y'){
				r = (r+l)/2;
			}else{
				l = (r+l)/2+1;
			}
			if(e[0] == 'B')return 0;
			l = max(l-k,1LL);
			r = min(r+k,n);
			//
		}//cout<<l<<' '<<r<<endl;
		ll c = rng()%(r-l+1)+l;
		cout<<c<<' '<<c<<endl;
		cout.flush();
		cin>>e;
		if(e[0] == 'Y'){
			break;
		}
		if(e[0] == 'B')return 0;
		l = max(l-k,1LL);
		r = min(r+k,n);
	}
	return 0;
}