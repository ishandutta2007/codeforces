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
int n,mi = 1e9+7,ma = 0,c;
int main(){
	read(n);
	for(int i=0;i<n;i++){
		read(c);
		ma = max(ma,c);
		mi = min(mi,c);
	}
	cout<<ma-mi+1-n<<endl;;
	return 0;
}