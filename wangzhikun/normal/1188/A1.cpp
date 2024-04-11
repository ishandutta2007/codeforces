//determined
#include <cmath>
#include <cstdio>
#include <cstring>
#include <complex>
#include <cassert>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
typedef unsigned long long ull;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();};
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
	x*=f;
}

int n,u,v,d[100010];
int main(){
	read(n);
	for(int i=1;i<n;i++){
		read(u);read(v);
		d[u]+=1;
		d[v]+=1;
	}
	for(int i=1;i<=n;i++){
		if(d[i] == 2){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	return 0;
}