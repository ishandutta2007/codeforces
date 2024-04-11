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

int T,n,a[1000010];

void solve(){
	read(n);
	for(int i=0;i<n;i++){
		read(a[i]);
	}
	vector<int> cnt;
	cnt.push_back(1);
	for(int i=1;i<n;i++){
		if(a[i]!=a[i-1])cnt.push_back(1);
		else{
			cnt[cnt.size()-1]++;
		}
	}
	int g = cnt[0];
	int s = 0,b = 0,cc=g,cu = 0;
	int bst[3] = {0,0,0};
	for(int i=1;i<cnt.size();i++){
		cc+=cnt[i];
		if(s<=g){
			s+=cnt[i];
		}else{
			b+=cnt[i];
		}
		if(cc<=n/2 && s>g && b>g){
			bst[0] = g;
			bst[1] = s;
			bst[2] = b;
		}
	}
	cout<<bst[0]<<' '<<bst[1]<<' '<<bst[2]<<endl;
}

int main() {
	read(T);
	while(T--){
		solve();
	}
	return 0;
}