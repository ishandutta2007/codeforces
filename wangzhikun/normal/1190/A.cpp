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
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();};
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}
	x*=f;
}

ll n,m,k,p[100010];
int main(){
	read(n);read(m);read(k);
	for(int i=0;i<m;i++){
		read(p[i]);
		p[i]-=1;
	}
	int cpo = 0,ans =0,cau = 0;
	while(cpo!=m){
		ans++;
		ll cc = 1;
		ll bel = (p[cpo]-cau)/k;
		while(cpo+1!=m && (p[cpo+1]-cau)/k == bel){
			cpo+=1;
			cc+=1;
		}
		cpo+=1;
		cau+=cc;
	}
	cout<<ans<<endl;
	return 0;
}