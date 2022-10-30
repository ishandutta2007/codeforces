#include <cstdio>
#include <algorithm>

using namespace std;

int n,m;
char S[100013];

int main() {
	scanf("%d%d %s",&n,&m,S+1);
	long long ans = 0;
	char prev1 = 0, prev2 = 0;
	int loc = 0;
	int num = 0;
	for (int i=1;i<=n;i++) {
		if (S[i]==S[i+1]) continue;
		if (prev2 && (S[loc]==S[loc-1] || S[i]!=prev2)) {
            ans-=(long long) num*(num-1)/2;
            num = 1;
		}
		prev2 = prev1;
		prev1 = S[i];
		loc = i;
		num+=1;
		ans+=(long long) (m-1)*n;
	}
	if (prev2) ans-=(long long) num*(num-1)/2;
	printf("%lld\n",ans);

	return 0;
}