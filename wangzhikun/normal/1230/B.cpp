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
char a[200020];
int main() {
	read(n);read(k);
	cin>>a;
	for(int i=0;i<n;i++){
		char tgt = '0';
		if(i == 0 && n!=1)tgt = '1';
		if(a[i]!=tgt && k){
			k--;
			a[i] = tgt;
		}
	}
	cout<<a<<endl;
	return 0;
}