// Author : WangZhikun
// Date   : 2018.08.16
#include <set>
#include <cmath>
#include <queue>
#include <ctime>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define popcnt __builtin_popcount
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;ll f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch = getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch = getchar();}x*=f;
}
ll a,b;
int main(){
	cin>>a>>b;
	ll po = min(b-1,(a-(b-a-1)));
	cout<<max((ll)0,po/2)<<endl;
	return 0;
}