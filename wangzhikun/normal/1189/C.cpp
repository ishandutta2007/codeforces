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

int n,s[100010],q;
int main(){
	read(n);
	for(int i=1;i<=n;i++){
		read(s[i]);
		s[i]+=s[i-1];
	}
	read(q);
	for(int i=0;i<q;i++){
		int l,r;
		read(l);read(r);
		cout<<(s[r]-s[l-1])/10<<endl;
	}
	return 0;
}