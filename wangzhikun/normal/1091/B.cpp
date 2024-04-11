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
int n;
pair<int,int> a[1010],b[1010];
int main() {
	read(n);
	for(int i=0;i<n;i++){
		read(a[i].FF);read(a[i].SS);
	}
	for(int i=0;i<n;i++){
		read(b[i].FF);read(b[i].SS);
		b[i].FF*=-1;b[i].SS*=-1;
	}
	sort(a,a+n);
	sort(b,b+n);
	cout<<a[0].FF-b[0].FF<<' '<<a[0].SS-b[0].SS<<endl;
	return 0;
}