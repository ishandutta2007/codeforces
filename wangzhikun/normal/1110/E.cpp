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
ll n,a[100010],b[100010],c[100010],d[100010];
int main() {
	read(n);
	for(int i=0;i<n;i++){
		read(a[i]);
		if(i)c[i] = a[i]-a[i-1];
	}
	for(int i=0;i<n;i++){
		read(b[i]);
		if(i)d[i] = b[i]-b[i-1];
	}
	if(a[0]!=b[0] || a[n-1]!=b[n-1]){
		cout<<"No"<<endl;
		return 0;
	}
	sort(c+1,c+n);
	sort(d+1,d+n);
	for(int i=1;i<n;i++){
		if(c[i]!=d[i]){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}