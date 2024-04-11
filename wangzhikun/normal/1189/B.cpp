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

int n,a[100010];
int main(){
	read(n);
	for(int i=0;i<n;i++){
		read(a[i]);
	}
	sort(a,a+n);
	if(a[n-3]+a[n-2]<=a[n-1]){
		cout<<"NO\n";
	}else{
		cout<<"YES\n";
		cout<<a[n-2]<<' ';
		for(int i=0;i<n-2;i++)cout<<a[i]<<' ';
		cout<<a[n-1]<<'\n';
	}
	return 0;
}