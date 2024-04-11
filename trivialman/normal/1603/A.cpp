#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define PB push_back
typedef long long LL;
const int P = 998244353;
const int N = 150005;

int T, n;

int main(){
	//freopen("in.txt","r",stdin);
	cin>>T;
	while(T--){
		scanf("%d",&n);
		LL k = 1, x;
		bool flag = true;
		rep(i,1,n) {
			if(k<2e9) k = k * (i+1ll) / __gcd(k, i+1ll);
			scanf("%lld",&x);
			if(x%k==0) flag = false;
		}
		printf(flag?"YES\n":"NO\n");
	}
}