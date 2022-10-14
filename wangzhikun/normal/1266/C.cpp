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

ll r,c;
int main() {
	read(r);read(c);
	if(r == 1 && c == 1){
		cout<<0<<endl;
		return 0;
	}
	if(c == 1){
		for(int i=1;i<=r;i++){
			cout<<i+1<<endl;
		}return 0;
	}
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cout<<i*(j+r);
			if(j!=c)cout<<' ';
		}
		cout<<endl;
	}
	return 0;
}