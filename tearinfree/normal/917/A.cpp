#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

char str[5101];
int cache[5101][5101];
int c[5105];
int DP(int l,int r) {
	int &ret=cache[l][r];
	if(ret!=-1) return ret;

	if(l>r) return ret=1;

	ret=0;
	if( (str[l]=='(' || str[l]=='?') && (str[r]==')' || str[r]=='?')) ret=max(ret,DP(l+1,r-1));

	return ret;
}

int main() {
	int n;
	scanf("%s",str);
	n=strlen(str);

	
	int ans=0;
	for(int i=0;i<n;i++) {
		queue<int> que;
		int a=0,b=0;
		for(int j=i;j<n;j++) {
			if(str[j]=='(') {
				a++;
			}
			else if(str[j]==')') b++;
			else {
				b++;
				que.push(j);
			}
			while(!que.empty() && a<b) {
				que.pop();
				a++;b--;
			}
			if(a<b) break;
			if(a==b) ans++;
		}
	}

	printf("%d\n",ans);

	return 0;
}