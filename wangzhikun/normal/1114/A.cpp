#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) //cerr<<#x<<'='<<x<<endl
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int main() {
	int x,y,z,a,b,c,ans = 1;
	cin>>x>>y>>z>>a>>b>>c;
	if(x>a){
		debug(1);
		ans = 0;
	}
	a-=x;
	b+=a;
	if(y>b){
		debug(2);
		ans = 0;
	}
	b-=y;
	b+=c;
	if(z>b){
		debug(3);
		ans = 0;
	}
	if(ans){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}