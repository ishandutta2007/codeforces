#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
#define DBG if(1)
#define NDBG if(0)

typedef long long ll;
typedef pair<int,int> pii;

const int MN = 5000 + 2;
const ll INF = 1e15;

ll D[MN][MN];

int N, st, ed;
int x[MN], a[MN], b[MN], c[MN], d[MN];

void inp(int *a){
	for(int i=0;i<N;i++) scanf("%d",&a[i]);
}

int main(){
	ll ans = INF;
	scanf("%d%d%d",&N,&st,&ed); st--, ed--;
	inp(x), inp(a), inp(b), inp(c), inp(d);
	if(st > ed){
		swap(st, ed);
		for(int i=0;i<N;i++) swap(b[i],d[i]), swap(a[i],c[i]);
	}
	for(int i=0;i<N;i++)for(int j=0;j<N;j++) D[i][j] = INF;
	if(st!=0)	D[0][1] = (ll) -2*x[0] + b[0] + d[0];
	else D[0][1] = (ll) d[0] - x[0];

	for(int i=1;i<N;i++){
		D[i-1][0] = INF;
		for(int j=0;j<=i;j++){
			int out = j;
			int in = j; if(st <= i-1 && i-1 < ed) in--;
			if(in<0 || out<0 || D[i-1][j] == INF) continue;
			if(i == st){
				if(in>0) D[i][j] = min(D[i][j], D[i-1][j] + c[i] + x[i]);
				D[i][j+1] = min(D[i][j+1], D[i-1][j] + d[i] - x[i]);
				continue;
			}
			if(i == ed){
				D[i][j] = min(D[i][j], D[i-1][j] + b[i] - x[i]);
				if(out>0) D[i][j-1] = min(D[i][j-1], D[i-1][j] + a[i] + x[i]);
				continue;
			}
			if(out>0) D[i][j] = min(D[i][j], D[i-1][j] + a[i] + d[i]);
			if(out>0 && in>0) D[i][j-1] = min(D[i][j-1], D[i-1][j] + a[i] + c[i] + 2*x[i]);
			if(in>0) D[i][j] = min(D[i][j], D[i-1][j] + b[i] + c[i]);
			D[i][j+1] = min(D[i][j+1], D[i-1][j] + b[i] + d[i] - 2*x[i]);
		}
	}
	printf("%lld\n",D[N-1][0]);

	return 0;
}