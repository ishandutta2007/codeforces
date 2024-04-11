#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<bitset>
using namespace std;

const int N = 1000005;

bitset<N>vis , can;
int a[105] , n , b[105];

int main() {
	int t;
	cin>>t;
	int cnt;
	for(int k = 1;k <= t;k ++) {
		scanf("%d",&n);
		can = vis = 0;
		for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
		for(int i = 1;i <= n;i ++) {
			for(int j = i + 1;j <= n;j ++) {
				vis[abs(a[i] - a[j])] = 1;
			}
		}
		cnt = 0;
		for(int j = 1;j <= 1000000;j ++) {
			if(cnt == n) {
				puts("YES");
				for(int p = 1;p <= n;p ++) printf("%d ",b[p]);
				puts(""); goto sy;
			}
			if(!can[j]) {
				b[++ cnt] = j;
				can |= (vis << (j));
			}
		}
		puts("NO");
		sy:
			continue;
	}
}