#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;

int n;
int dlog[500100];
struct RMQ {
	int sps[500100][20];
	void init(int arr[]) {
		for (int i=0;i<n;i++) sps[i][0] = arr[i];
		for (int j=1;j<20;j++) {
			for (int i=0;i<n;i++) {
				sps[i][j] = max(sps[i][j-1],(i+(1<<(j-1))<n?sps[i+(1<<(j-1))][j-1]:-INF));
			}
		}
	}
	int getv(int s, int e) {
		int v = dlog[e-s+1];
		return max(sps[s][v],sps[e+1-(1<<v)][v]);
	}
} M[2], m[2];

int arr[500100];
int tmp[500100];
int maxi;

int getv(int idx) {
	int s = 0, e = min(idx,n-1-idx), t = idx%2;
	while(s<=e) {
		int mid = (s+e)/2;
		if (M[t].getv(idx-mid,idx+mid)<-m[1-t].getv(idx-mid,idx+mid)||
			-m[t].getv(idx-mid,idx+mid)>M[1-t].getv(idx-mid,idx+mid)) s = mid+1;
		else e= mid-1;
	}
	maxi = max(maxi,e);
	if (e==0) return arr[idx];
	if (e%2==0) {
		if (M[t].getv(idx - e, idx + e) < -m[1 - t].getv(idx - e, idx + e)) return M[t].getv(idx - e, idx + e);
		return -m[t].getv(idx-e,idx+e);
	}
	if (M[t].getv(idx - e, idx + e) < -m[1 - t].getv(idx - e, idx + e)) return -m[1-t].getv(idx - e, idx + e);
	return M[1-t].getv(idx-e,idx+e);
}

int med(int a, int b, int c) {
	return a+b+c-min({a,b,c})-max({a,b,c});
}
void brute(int arr[], int tmp[]) {
	for (int c=0;;c++) {
		int ch = 0;
		for (int i=1;i+1<n;i++) {
			tmp[i] = med(arr[i-1],arr[i],arr[i+1]);
			if (tmp[i] != arr[i]) ch = 1;
		}
		if (ch==0) {
			printf("%d\n",c);
			return;
		}
		for (int i=1;i+1<n;i++) arr[i] = tmp[i];
	}
}
int brr[500100];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
//		brr[i] = arr[i] = rand()%10+1;
	}
	for (int i=0;i<20;i++) {
		for (int j=(1<<i);j<(1<<(i+1))&&j<=500000;j++) dlog[j] = i;
	}
	for (int t=0;t<2;t++) {
		for (int i=0;i<n;i++) tmp[i] = (i%2==t?arr[i]:-INF);
		M[t].init(tmp);
		for (int i=0;i<n;i++) tmp[i] = (i%2==t?-arr[i]:-INF);
		m[t].init(tmp);
	}
	for (int i=0;i<n;i++) tmp[i] = getv(i);
	printf("%d\n",maxi);
	for (int i=0;i<n;i++) printf("%d ",tmp[i]); puts("");

	return 0;
}