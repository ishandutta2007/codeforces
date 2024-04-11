#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iomanip>
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
ll n,k,m,a[100010],su;
int main() {
	read(n);read(k);read(m);
	for(int i=0;i<n;i++){
		read(a[i]);
		su+=a[i];
	}
	sort(a,a+n);
	double ans = 0;
	for(int i=0;i<n;i++){
		if(i<=m)ans = max(ans,(double)(su+min(m-i,k*(n-i)))/(n-i));
		su-=a[i];
	}
	cout<<setprecision(15)<<fixed;
	cout<<ans<<endl;
	return 0;
}