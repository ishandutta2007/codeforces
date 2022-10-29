#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const int P = 998244353;
const int N = 1005;
const double PI = acos(-1);
mt19937 rng(time(0));

int T, n, miss, a[N], cnt[N];
int id[N], b[N];
vector<int> ans;

int mex(){
	rep(i,0,n) if(!cnt[i]) return i;
}

void change(int i){
	int old = a[i];
	a[i] = mex();
	cnt[old]--, cnt[a[i]]++;
	ans.PB(i);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>T;
	while(T--){
		cin>>n;
		memset(cnt,0,sizeof cnt);
		rep(i,1,n) cin>>a[i], cnt[a[i]]++;
		
		ans.clear();
		while(1){
			int x = mex();
			if(x < n) change(x+1);
			else{
				bool flag = true;
				rep(i,1,n) if(a[i]!=i-1) {
					flag = false;
					change(i);
					break;
				}
				if(flag) break;
			}
		}
		
		cout<<ans.size()<<endl;
		for(auto x:ans) cout<<x<<" ";cout<<endl;
	}
	return 0;
}