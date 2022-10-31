#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <cstring>

using namespace std;
typedef long long lli;

int n,m,k;
char str[2001][2011];

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++) scanf("%s",str[i]);
	
	int ans=0;
	for(int i=0;i<n;i++) {
		int c=0;
		for(int j=0;j<m;j++) {
			if(str[i][j]=='.') c++;
			else c=0;
			if(c>=k) ans++;
		}
	}
	if(k!=1) {
	for(int j=0;j<m;j++) {
		int c=0;
		for(int i=0;i<n;i++) {
			if(str[i][j]=='.') c++;
			else c=0;
			if(c>=k) ans++;
		}
	}
	}
	printf("%d\n",ans);
	
	return 0;
}