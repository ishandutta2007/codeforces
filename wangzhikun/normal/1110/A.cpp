#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl
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
int b,k,c,v,cc,d[100010];
int main() {
	read(b);read(k);
	int c = 1;
	for(int i=0;i<k;i++){
		read(d[i]);
	}
	b%=2;
	for(int i=k-1;i>=0;i--){
		v+=c*d[i];
		c = c*b%2;
	}
	if(v%2 == 0){
		cout<<"even"<<endl;
	}else{
		cout<<"odd"<<endl;
	}
	return 0;
}