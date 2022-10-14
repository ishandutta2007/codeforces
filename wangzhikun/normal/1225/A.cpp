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

int a,b;
int main() {
	read(a);read(b);
	for(int i=0;i<200;i++){
		int ca = i,cb = i+1;
		while(ca>=10)ca/=10;
		while(cb>=10)cb/=10;
		//cout<<i<<' '<<ca<<' '<<cb<<endl;
		if(ca == a && cb == b){
			cout<<i<<' '<<i+1<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}