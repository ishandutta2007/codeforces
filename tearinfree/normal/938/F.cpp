#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

typedef long long lli;
typedef pair<int,int> pii;

struct data {
	int a,b,c;
	data() {}
	data(int a,int b,int c):a(a),b(b),c(c) {}
};

char str[5001];
int vis[1<<12][5001][2],n;

int main() {
	scanf("%s",str+1);
	n = strlen(str+1);

	int l = 0;
	while( (1 << (l+1)) - 1 < n) l++;
	
	queue<data> que;
	que.push(data(0,0,1));
	vis[0][0][1] = 1;
	for(int t=0;t < n - (1<<l) + 1;t++) {
		queue<data> nxt;
		char mx = 'z'+1;
		
		while(!que.empty()) {
			int a=que.front().a, b=que.front().b, c=que.front().c;
			que.pop();
			
			
			for(int i=0;i<l;i++) if(!(a>>i & 1) && b + (1<<i) <= n) {
				int na = a | (1  << i), nb = b + (1<<i), nc = 0;
				if(!vis[na][nb][nc]) que.push(data(na,nb,nc)),vis[na][nb][nc] = 1;
			}
			if(b + 1 <= n) {
				int na = a, nb = b+1, nc = 1;
				if(!vis[na][nb][nc]) {
					vis[na][nb][nc] = 1;
					if(mx < str[nb]) continue;
					else if(mx > str[nb]) {
						while(!nxt.empty()) nxt.pop();
						mx=str[nb];
					}
					nxt.push(data(na,nb,nc));
				}
			}
		}
		printf("%c",mx);
		que = nxt;
	}

	return 0;
}