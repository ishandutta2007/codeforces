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

int su[1000010],n,m;
char a[1000010],b[1000010];

int main(){
	cin>>a>>b;
	n = strlen(a);m = strlen(b);
	int bsu = 1;
	for(int i=0;i<m;i++){
		bsu = bsu+b[i]-'0';
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		su[i] = su[i-1]+a[i-1]-'0';
		if(i>=m && (su[i]-su[i-m]+bsu)&1)ans++;
	}
	cout<<ans<<endl;
	return 0;
}