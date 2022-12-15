#include <iostream>
using namespace std;

typedef long long ll;
ll a, b, c, i, j, ans=1, tmp, mod = 998244353, cnt[5005][5005];

int main(){
	for(i=0;i<=5000;i++){
		for(j=0;j<=5000;j++){
			if(i == 0 || j == 0) cnt[i][j] = 1;
			else cnt[i][j] = (j*cnt[i-1][j-1]+cnt[i-1][j])%mod;
		}
	}
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	printf("%I64d\n",(((cnt[a][b]*cnt[b][c])%mod)*cnt[a][c])%mod);
	return 0;
}