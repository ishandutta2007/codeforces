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

int n,frac[100020] = {0},cnt[100020] = {0},k;
int main() {
	for(int i=2;i<=100010;i++){
		if(frac[i] == 0){
			for(int j=i;j<=100010;j+=i)frac[j] = i;
		}
	}
	read(n);read(k);
	ll ans = 0;
	for(int i=0;i<n;i++){
		int cu,ncu = 1;
		read(cu);
		ll cc = 1;
		set<int> cs;
		while(cu!=1){
			int cp = frac[cu];
			int cnt = 0;
			while(cu%cp==0){
				cu/=cp;
				cnt+=1;
			}
			cnt%=k;
			if(cnt!=0){
				for(int j=0;j<cnt;j++)ncu*=cp;
				if(log(cc)+log(cp)*k>log(1e12)){
					goto nxt;
				}else{
					for(int j=0;j<k;j++)cc*=cp;
				}
			}
		}
		if(cc/ncu < 100010) ans+=cnt[cc/ncu];
		nxt:;
		cnt[ncu]+=1;
	}
	cout<<ans<<endl;
	return 0;
}