#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

int T, X, Y, K, i;
long long a, b;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&X,&Y,&K);
		a = 1LL*K*(Y+1);
		b = 1;
		long long res = ceil((a-b)/(long double)(X-1));
		res += K;
		printf("%lld\n",res);
	}
	return 0;
}