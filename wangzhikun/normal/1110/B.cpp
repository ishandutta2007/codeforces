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
int n,m,k,p[100010],d[100010];
int main() {
	read(n);read(m);read(k);
	for(int i=0;i<n;i++){
		read(p[i]);
		if(i)d[i-1] = p[i]-p[i-1]-1;
	}
	k--;
	int cans = p[n-1]-p[0]+1;
	sort(d,d+n-1);
	for(int i=0;i<k;i++){
		cans-=d[n-2-i];
	}
	cout<<cans<<endl;
	return 0;
}