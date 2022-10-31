#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,lli>;

int n,m,arr[5001];
int main() {
	scanf("%d%d",&n,&m);
	int mx=0;
	for(int i=3;i<=n;i++) {
		mx += (i-1)/2;
	}
	if(mx < m) {
		puts("-1");
		return 0;
	}

	int T = 100000;
	if(m==0) {
		for(int i=0;i<n;i++) printf("%d\n",(i+1)*T+1);
		return 0;
	}

	int v=1;
	for(int i=0;i<n;i++) {
		if(m > i/2) {
			m -= i/2;
			arr[i] = v++;
		} else {
			int st = i%2, fi=i-1;
			while((fi-st+1)/2 > m) st+=2;
			arr[i] = arr[st] + arr[fi];
			for(int j=i+1;j<n;j++) {
				arr[j] = (j-i)*T+1;
			}
			break;
		}
	}

	for(int i=0;i<n;i++) printf("%d ",arr[i]);

	return 0;
}