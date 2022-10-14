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

ll a[3],t;
int main() {
	read(t);
	while(t--){
		read(a[0]);
		read(a[1]);
		read(a[2]);
		sort(a,a+3);
		if(a[0]+a[1]+1<a[2]){
			cout<<"No"<<endl;
		}else{
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}