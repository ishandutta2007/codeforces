#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 1e5+5;
const double eps = 1e-7;
int T, N, L, i, j, l, r, arr[MN];
long double t, lx, rx;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&L);
		for(i=1;i<=N;i++)
			scanf("%d",&arr[i]);
		t = 0;
		l = 1, r = N;
		lx = 0, rx = L;
		while(l<=r){
			long double ta = (arr[l]-lx)/(long double)l;
			long double tb = (rx-arr[r])/(long double)(N-r+1);
			long double dt = min(ta, tb);
			lx += l*dt, rx -= (N-r+1)*dt; t += dt;
			if(lx+eps>=arr[l]) l++;
			if(rx-eps<=arr[r]) r--;
		}
		if(lx<rx){
			long double dist = (rx-lx);
			t += dist/(long double)(l+N-r+1);
		}
		printf("%.6Lf\n",t);
	}
	return 0;
}