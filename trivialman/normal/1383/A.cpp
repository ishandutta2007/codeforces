#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int,2>
typedef long long LL;
const LL P = 1e9+7;
const LL INF = 1e18;
const int N = 1e5+5;
mt19937 rng(time(0));
 
int T, n;
char a[N], b[N];
bool to[25][25];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	cin>>T;
	while(T--){
		cin>>n>>(a+1)>>(b+1);
		bool flag = false;
		rep(i,1,n) if (a[i]>b[i]) flag = true;
		if (flag) {
			cout<<"-1\n";
			continue;
		}
		
		memset(to, false, sizeof to);
		rep(i,1,n) if(a[i]!=b[i]) to[a[i]-'a'+1][b[i]-'a'+1] = true;
		
		int ans = 0;
		rep(i,1,20){
			rep(j,i+1,20) if(to[i][j]){
				rep(k,j+1,20) if(to[i][k]) to[j][k] = true;
				ans++;
				break;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}