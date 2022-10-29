#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9+7;
const int N = 1e6+5;
const int INF = 1e9;
const double pi = acos(-1);
mt19937 rng(time(0));

char s[N];
int n, i, j, nxt[N][2];
vector<int> start[N];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	scanf("%d\n%s",&n,s+1);
	rep(i,1,n){
		if(s[i]=='?'){
			for(j=i; j<=n&&s[j]=='?'; j++); j--;
			if(i==1 || j==n || s[i-1]==s[j+1]){
				char ch = i==1 ? s[j+1] : s[i-1];
				if (ch!='0' && ch!='1') ch = '0';
				rep(k,i,j) s[i] = ch;
			}
			i = j;
		}
	}
	
	s[0] = '0' + '1' - s[1];
	nxt[n+1][0] = nxt[n+1][1] = n+1;
	rrep(i,n,1){
		nxt[i][1] = (s[i+1]!='0') ? nxt[i+1][1] : i+1;
		nxt[i][0] = (s[i+1]!='1') ? nxt[i+1][0] : i+1;
		if (s[i-1]!='?' && s[i]!=s[i-1]) {
			for(j=i; j<=n&&s[j]!=s[i-1]; j++);
			rep(k,1,j-i) start[k].PB(i);
		}
	}
	
	rep(i,1,n){
		reverse(start[i].begin(), start[i].end());
		start[i].PB(n+1);
		int ans = 0, x = 1;
		while(x <= n){
			int nextx;
			nextx = s[x]!='1' ? nxt[x][0] : 0;
			nextx = max(nextx, s[x]!='0' ? nxt[x][1] : 0);
			if (nextx >= x + i)
				x += i, ans++;
			else {
				x = *lower_bound(start[i].begin(), start[i].end(), x) + i;
				if (x <= n + 1) ans++;
			}
			
		}
		printf("%d ",ans);
	}
	return 0;
}