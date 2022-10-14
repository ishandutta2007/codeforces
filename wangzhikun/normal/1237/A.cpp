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
int main() {
	read(n);
	int cu;
	int sub = 0;
	for(int i=0;i<n;i++){
		read(cu);
		if(cu%2 == 0){
			cout<<cu/2<<endl;
			continue;
		}
		if(cu>0)cu+=1;
		cu/=2;
		cu-=sub;
		sub^=1;
		cout<<cu<<endl;
	}
	return 0;
}