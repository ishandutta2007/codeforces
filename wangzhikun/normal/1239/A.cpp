//determined
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <complex>
#include <cassert>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) //cerr<<#x<<'='<<x<<endl
using namespace std;
typedef unsigned long long ull;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();};
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
	x*=f;
}

int Fib[200020],mod = 1e9+7,n,m;
int main(){
	Fib[0] = Fib[1] = 1;
	for(int i=2;i<=100010;i++)Fib[i] = (Fib[i-1]+Fib[i-2])%mod;
	read(n);read(m);
	cout<<2*((Fib[n]+Fib[m]-1)%mod)%mod<<endl;
	return 0;
}