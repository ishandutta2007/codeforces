#include<stdio.h>
#include<algorithm>
#include<vector>
#include<functional>
#define all(A) (A).begin(), (A).end()
#define II(A) int (A); scanf("%d",&(A));
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int c1[5];
int c2[5];

int main(){
	II(N)II(M);
	for(int i=1;i<=N;i++){
		c1[i%5]++;
	}
	for(int i=1;i<=M;i++){
		c2[i%5]++;
	}
	ll ans = (ll)c1[0]*c2[0];
	for(int i=1;i<5;i++){
		ans += (ll)c1[i]*c2[5-i];
	}
	printf("%lld\n",ans);
	return 0;
}