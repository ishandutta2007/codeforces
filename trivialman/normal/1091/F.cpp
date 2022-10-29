#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 1e9+7;
const int N = 1e5+10;

LL n,l[N],t=0,sta=0,twiceG=0;
char s[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	rep(i,1,n)cin>>l[i];
	cin>>(s+1);
	bool water=false;
	rep(i,1,n){
		if(s[i]=='L'){
			sta -= l[i];
			t += l[i];
			if(sta<0) t -= sta * (water?3:5), sta=0;
		}else if(s[i]=='W'){
			water = true;
			t += l[i]*3;
			sta += l[i];
		}else{
			t += l[i]*5;
			sta += l[i];
			twiceG += l[i]*2;
		}
		twiceG = min(twiceG, sta);
	}
	t -= (5-1)/2*twiceG;
	t -= (3-1)/2*(sta-twiceG);
	cout<<t<<endl;
	return 0;
}