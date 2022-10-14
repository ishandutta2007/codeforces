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

const int N = (1<<21)+10;

int n,a[N],l[N],r[N];

void add(int p,int v){
	if(v == l[p] || v == r[p])return;
	if(v>=r[p]){
		l[p] = r[p];
		r[p] = v;
	}else{
		l[p] = max(l[p],v);
	}
}

int main() {
	set0(l);
	set0(r);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		add(a[i],i);
	}
	
	for(int i=1<<21;i>=0;i--){
		for(int j=0;j<20;j++){
			if(i & (1<<j)){
				add(i^(1<<j),l[i]);
				add(i^(1<<j),r[i]);
			}
		}
	}
	
	int ans = 0;
	for(int i=1;i<=n-2;i++){
		int cans = 0,creq = 0;
		for(int j = 20;j>=0;j--){
			//cout<<(1<<j)<<' '<<creq<<endl;
			if((a[i]>>j)&1){
				cans+=(1<<j);
			}else{
				if(l[(creq|(1<<j))]>i){
					creq|=(1<<j);
					cans+=(1<<j);
				}
			}
		}
		//cout<<i<<' '<<cans<<endl;
		ans = max(ans,cans);
	}
	cout<<ans<<endl;
	return 0;
}