#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
typedef long long LL;
const LL P = 1e9+7;
const int N = 1e5+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, c[N];
char a[N], b[N];

int calc(char a[], int n){
	int res = 0;
	rep(i,1,n) res += (i&1) ? a[i] : -a[i];
	return res;
}
bool check(int i){
	if(i<=0 || i>=n) return false;
	if(c[i]<0 && (i==1 && a[i]>1 || i>1 && a[i]>0) && a[i+1]>0) return true;
	if(c[i]>0 && a[i]<9 && a[i+1]<9) return true;
	return false;
}

int main(){
	//freopen("test.in","r",stdin);
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n>>(a+1)>>(b+1);
	rep(i,1,n) a[i]-=48, b[i]-=48;
	if(calc(a,n)!=calc(b,n)){
		cout<<-1; return 0;
	}
	LL ans = 0;
	rep(i,1,n-1) c[i] = (b[i]-a[i]) - c[i-1];
	rep(i,1,n-1) ans += 1ll * abs(c[i]);
	//rep(i,1,n-1)cout<<c[i]<<" ";cout<<endl;
	cout<<ans<<endl;
	unordered_set<int> st;
	rep(i,1,n-1) if(check(i)) st.insert(i);
	rep(i,1,1e5){
		if(st.empty()) break;
		int x = *st.begin();
		if(c[x]<0) c[x]++, a[x]--, a[x+1]--, cout<<x<<" -1\n";
		else c[x]--, a[x]++, a[x+1]++, cout<<x<<" 1\n";
		if(!check(x)) st.erase(x);
		if(check(x-1)) st.insert(x-1);
		if(check(x+1)) st.insert(x+1);
		//cout<<a[1]+0<<" "<<a[2]+0<<" "<<a[3]+0<<" "<<a[4]+0<<endl;
	}
	return 0;
}