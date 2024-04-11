#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
const LL P = 1e9+7;
const LL INF = 1e12;
const int N = 1e5+5;
const double pi = acos(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

LL w,cnt[10],s=0;
int a[805];
bool dp[7000];

int main(){
	//freopen("test.in","r",stdin);
	cin>>w;
	rep(i,1,8)cin>>cnt[i],s+=cnt[i]*i;
	if(s<w){
		cout<<s<<endl;
		return 0;
	}
	
	s = 0;
	rep(i,1,8)if(cnt[i]>100){
		LL x = cnt[i] - 100;
		cnt[i] = 100;
		if(x*i+100>w){
			if(w>100){
				x = (w-100ll)/i;
				w -= x*i;
				s += x*i;
			}
		}else w -= x*i, s += x*i;
	}
	if(w>7000){
		int i=0;
		while(i<(1<<30))++i;
	}
	int m = 0; 
	rep(i,1,8)rep(j,1,cnt[i]){
		a[++m] = i;
	}
	memset(dp,false,sizeof dp);
	dp[0] = true;
	rep(i,1,m)rrep(j,w,a[i]){
		if(dp[j-a[i]]) dp[j] = true;
	}
	LL ans = w;
	while(!dp[ans]) ans--;
	cout<<s+ans<<endl;
	return 0;
}