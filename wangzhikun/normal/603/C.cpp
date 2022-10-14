#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,k;

int val0(int a){
	if(a<=2)return a;
	if(a%2 == 1)return 0;
	return 1;
}
int val1(int a){
	if(a == 0)return 0;
	if(a%2 == 1){
		if(a<=3)return 1;
		return 0;
	}
	int v1 = val1(a/2),v2 = val1(a-1);
	if((v1 == 0 || v2 == 0) && (v1 == 1 || v2 == 1))return 2;
	return (v1 == 0 || v2 == 0);
}

int main() {
	read(n);read(k);
	int cc = 0,cu = 0;
	for(int i=0;i<n;i++){
		read(cu);
		if(k%2 == 0) cc^=val0(cu);
		else  cc^=val1(cu);
	}
	if(cc == 0){
		cout<<"Nicky\n";
	}else{
		cout<<"Kevin\n";
	}
	return 0;
}