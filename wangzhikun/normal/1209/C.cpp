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

int T;
int n;
char a[200010],ans[200010];
void solve(){
	cin>>n>>a;
	for(int i=1;i<=9;i++){
		int l1 = -1,l2 = -1,ok = -1,ddl = 1e9;
		for(int j=n-1;j>=0;j--){
			if(a[j]<'0'+i){
				ddl = j;
				break;
			}
		}
		for(int j=0;j<n;j++){
			if(a[j]>'0'+i || ((a[j] == '0'+i) && j<=ddl)){
				if(l2>a[j]-'0')ok =j;
				l2 = a[j]-'0';
				ans[j] = '2';
			}else{
				if(l1>a[j]-'0')ok =j;
				l1 = a[j]-'0';
				ans[j] = '1';
			}
		}
		ans[n] = 0;
		//cout<<i<<' '<<ans<<' '<<a<<endl;
		if(ok == -1){
			ans[n] = 0;
			cout<<ans<<endl;
			return;
		}
	}
	cout<<'-'<<endl;
}
int main() {
	read(T);
	while(T--){
		solve();
	}
	return 0;
}