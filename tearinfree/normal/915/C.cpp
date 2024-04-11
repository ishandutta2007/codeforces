#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long lli;

char s[30],t[30];
int n;

bool dfs(int idx,int state,lli val,int f) {
	if(idx == n){
		printf("%lld\n",val);
		return true;
	}
	
	bool flag=false;

	int mx=-1,id=-1;
	for(int i=0;i<n;i++) if( !(state>>i & 1) && (f || s[i] <= t[idx]) && mx < s[i]-'0') {
		mx=s[i]-'0';
		id=i;
	}
	if(id!=-1) {
		val = val * 10 + mx;
		if(mx < t[idx]-'0') flag=dfs(idx+1, state | 1<<id, val, 1);
		else flag=dfs(idx+1, state | 1<<id, val, f);
		val/=10;
	}
	if(!flag) {
		mx=id=-1;
		for(int i=0;i<n;i++) if( !(state>>i & 1) && s[i] < t[idx] && mx < s[i]-'0') {
			mx=s[i]-'0';
			id=i;
		}
		if(id==-1) return false;
		val = val*10+mx;
		dfs(idx+1, state | 1<<id, val, 1);
	}
	return true;
}

int main() {
	scanf("%s%s",s,t);
	n=strlen(s);
	if(strlen(t) > n) dfs(0,0,0,1);
	else dfs(0,0,0,0);
	return 0;
}