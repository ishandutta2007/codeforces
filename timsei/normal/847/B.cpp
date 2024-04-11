//vector 
#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

int a[N] , n , vis[N] ,L[N] , R[N] , pos[N] , nxt[N] , val[N] , now;

vector<int>Vec[N];

int main(void) {
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++) {
    	int x; scanf("%d",&x);
    	if(!now) {
    		now ++; Vec[now].push_back(x); val[now] = x;
    		continue;
		}
		if(x <= val[now]) {
    		now ++; Vec[now].push_back(x);
    		val[now] = x;
    		continue;			
		}
		int l = 1 , r = now , res = -1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(val[mid] < x) {
				res = mid; r = mid - 1;
			}
			else l = mid + 1;
		}
		Vec[res].push_back(x); val[res] = x;
	}
	for(int i = 1;i <= now;i ++) {
		for(int j = 0;j < (int)Vec[i].size();j ++) cout<<Vec[i][j] <<" ";
		puts("");
	}
}