// Author : WangZhikun
// Date   : 2018.09.16

#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mid (l+r)/2
#define FF first
#define SS second
#define MP make_pair
#define pll pair<ll,ll>
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;ll f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch = getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch = getchar();}x*=f;
}
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
ll a,b,x,y,d;
int main(){
	read(a);read(b);read(x);read(y);
	d = gcd(x,y);
	x/=d;y/=d;
	cout<<min(a/x,b/y)<<endl;
	return 0;
}