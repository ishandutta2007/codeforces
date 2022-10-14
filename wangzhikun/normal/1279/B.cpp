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

ll a[100010],t,n,s;


int main() {
	read(t);
	while(t--){
		read(n);read(s);
		for(int i=1;i<=n;i++)read(a[i]);
		ll cs = 0,cmx = 0,cmid = 0;
		ll ans = 0,ansid = 0;
		for(int i=1;i<=n;i++){
			cs+=a[i];
			if(a[i]>cmx){
				cmx = a[i];
				cmid = i;
			}
			if(cs<=s){
				ansid = 0;
			}else{
				if(cs-cmx<=s){
					ansid = cmid;
				}
			}
		}
		cout<<ansid<<endl;
	}
	return 0;
}