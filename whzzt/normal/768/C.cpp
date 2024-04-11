#include "bits/stdc++.h"
using namespace std;

const int buf_size = 1024;
int cnt[buf_size],n,k,x,a,to[buf_size],cal[buf_size];
int *go[buf_size],mx,mn;

int main(){
	scanf ("%d%d%d", &n, &k, &x);
	for (int i=1; i<=n; i++) scanf("%d",&a), cnt[a]++;
	for (int i=0; i<buf_size; i++) to[i] = i ^ x, go[i] = &cal[to[i]];
	for (register int i=1; i<=k; i++){
		for (register int i=0; i<buf_size; i+=4)
			cal[i] = cal[i+1] = cal[i+2] = cal[i+3] = 0;
		int sum = 0;
		for (register int i=0; i<buf_size; i++) if (cnt[i]) {
			cal[i] += cnt[i] >> 1, *go[i] += cnt[i] >> 1;
			(sum & 1) ? cal[i] += (cnt[i] & 1) : *go[i] += (cnt[i] & 1);
			sum += cnt[i];
		}
		memcpy (cnt,cal,buf_size << 2);
	}
	for (mx = 1023; !cnt[mx]; mx--);
	for (mn = 0; !cnt[mn]; mn++);
	cout << mx << ' ' << mn << endl;
	return 0;
}