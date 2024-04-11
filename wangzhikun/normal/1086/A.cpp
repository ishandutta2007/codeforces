#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
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
int take[1010][1010] = {0};
pll p[3];
int main() {
	ll miny = 10000,maxy = -10000;
	for(int i=0;i<3;i++){
		read(p[i].FF);read(p[i].SS);
		miny = min(miny,p[i].SS);
		maxy = max(maxy,p[i].SS);
	}
	sort(p,p+3);
	cout<<(maxy-miny+1)+p[2].FF-p[0].FF<<endl;;
	for(int i=miny;i<=maxy;i++){
		cout<<p[1].FF<<' '<<i<<endl;
	}
	for(int i=p[0].FF;i<p[1].FF;i++){
		cout<<i<<' '<<p[0].SS<<endl;
	}
	for(int i=p[1].FF+1;i<=p[2].FF;i++){
		cout<<i<<' '<<p[2].SS<<endl;
	}
	return 0;
}