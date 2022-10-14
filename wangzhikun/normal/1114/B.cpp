#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) cerr<<#x<<'='<<x<<endl
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
ll n,m,k,a[200010],b[200010],ans;
map<int,int> S;
int main() {
	read(n);read(m);read(k);
	for(int i=0;i<n;i++){
		read(a[i]);
		b[i] = a[i];
	}
	sort(b,b+n);
	ll ans = 0;
	for(int i=n-1;i>=n-m*k;i--){
		ans = ans+b[i];
		S[b[i]]+=1;
	}
	cout<<ans<<endl;
	int cnt = 0,su = 0;
	for(int i=0;i<n;i++){
		if(S[a[i]]){
			cnt+=1;
			S[a[i]]-=1;
		}
		if(cnt == m){
			cout<<i+1<<' ';
			su+=1;
			cnt = 0;
		}
		if(su == k-1)break;
	}
	cout<<endl;
	return 0;
}