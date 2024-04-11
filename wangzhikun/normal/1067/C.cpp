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
int main() {
	read(n);
	int a = n/3;
	
	for(int i=0,p=0;i<a;i++,p+=2){
		cout<<1<<' '<<p<<endl;
	}
	for(int i=0,p=1;i<a;i++,p+=2){
		cout<<2<<' '<<p<<endl;
	}
	for(int i=0,p=0;i<n-a-a;i++,p+=2){
		cout<<3<<' '<<p<<endl;
	}
	return 0;
}