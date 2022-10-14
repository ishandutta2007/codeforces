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

int n,a[100010],sz[330],mi[330],mx[330],stp[330] = {0},blc;
int walk(int cn,int cmx,int carry = 0,int ts = 0){
	if(carry>n*2) return -1;
	if(cn%blc == 0 && !ts){
		//debug("INI");
		if(mi[cn/blc]*2<cmx || stp[cn/blc]){
			return walk(cn,cmx,carry,1);
		}else{
			if(cn+blc>=n){
				return walk(0,max(cmx,mx[cn/blc]),carry+n-cn);
			}else{
				return walk(cn+blc,max(cmx,mx[cn/blc]),carry+blc);
			}
		}
	}
	if(a[cn]*2<cmx){
		return carry;
	}else{
		return walk((cn+1)%n,max(cmx,a[cn]),carry+1,ts);
	}
	return -1;
}
int main() {
	read(n);
	blc = sqrt(n)+2;
	//cout<<blc<<endl;
	for(int i=0;i<330;i++){
		mi[i] = 1.1e9;
		mx[i] = -1.1e9;
	}
	int cmx = -1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i%blc == 0){
			cmx = -1;
		}
		cmx = max(cmx,a[i]);
		if(a[i]*2<cmx){
			stp[i/blc] = 1;
		}
		mi[i/blc] = min(mi[i/blc],a[i]);
		mx[i/blc] = max(mx[i/blc],a[i]);
	}
	for(int i=0;i<n;i++){
		cout<<walk(i,-1)<<' ';
	}
	cout<<endl;
	return 0;
}