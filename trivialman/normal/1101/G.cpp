#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
const LL P = 1e9+7;
const int N = 5e5+5;
const LL INF = 1e16;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int n,ans=1,a[N],s[N],b[40];

bool addbase(int x){
	rrep(j,30,0)if(x>>j&1){
		if(!b[j]) { b[j] = x; return true; }
		x ^= b[j];
	}
	return false;
}

int main(){
	//freopen("test.in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",a+i);
	s[0] = 0;
	rep(i,1,n)s[i]=s[i-1]^a[i];
	if(!s[n]){
		printf("-1\n");
		return 0;
	}
	memset(b,0,sizeof b);
	addbase(s[n]);
	rep(i,1,n-1){
		if(addbase(s[i]))++ans;
	}
	cout<<ans<<endl;
	return 0;
}