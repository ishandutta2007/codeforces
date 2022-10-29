#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
#define PB push_back
#define CL(a,x) memset(a, x, sizeof(a))
typedef long long LL;
const int P = 1e9+7;
const int N = 2e5+5;
const double PI = acos(-1);
mt19937 rng(time(0));

char s[N], ans[N];
int n, T, m, l, r;

void work(int l, int r, char s[]){
	int ma = 0;
	rep(i,l,r){
		bool flag = true;
		rep(j,l,(i+l)/2) if(s[j]!=s[i+l-j]){
			flag = false; break;
		}
		if(flag) ma = max(ma, i);
	}
	if(ma-l+1>m){
		m = ma-l+1;
		rep(i,l,l+m-1) ans[i] = s[i];
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	
	scanf("%d",&T);
	while(T--){
		scanf("%s", s+1);
		n = strlen(s+1);
		m = l = r = 0;
		rep(i,1,n/2){
			if(s[i] != s[n+1-i]){
				l = i, r = n+1-i;
				break;
			}
		}
		if(!l){
			printf("%s\n",s+1);
			continue;
		}
		//cout<<l<<" "<<r<<endl;
		work(l, r, s);
		reverse(s+l,s+r+1);
		work(l, r, s);
		
		rep(i,1,l-1) ans[i] = s[i];
		rep(i,r+1,n) ans[l+m+i-r-1] = s[i];
		ans[l+m+n-r] = '\0';
		printf("%s\n", ans+1);
	}
	return 0;
}