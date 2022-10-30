#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
const LL P = 998244353;
const int N = 1e5+10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,x,a[N];

int main(){
	//freopen("test.in","r",stdin);
	
	scanf("%d%d",&n,&m);
	
	int cnt = 0;
	rep(i,1,m){
		scanf("%d",&x);
		if(!a[x])++cnt;
		++a[x];
		if(cnt==n){
			rep(j,1,n){
				--a[j];
				if(!a[j]) cnt--;
			}
			printf("1");
			continue;
		}
		//cout<<endl<<i<<" "<<x<<endl;
		//rep(j,1,n)cout<<a[j]<<" ";cout<<endl;
		printf("0");
	}
	
	return 0;
}