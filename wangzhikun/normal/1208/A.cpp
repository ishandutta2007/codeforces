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

int T,n,a,b;
int main() {
	read(T);
	while(T--){
		read(a);read(b);read(n);
		if(n%3 == 0){
			cout<<a<<endl;
		}
		if(n%3 == 1){
			cout<<b<<endl;
		}
		if(n%3 == 2){
			cout<<(a^b)<<endl;
		}
	}
	return 0;
}