#include <bits/stdc++.h>
using namespace std;

long long ans=19;
int n, i;

bool check(long long n){
	long long sum = 0;
	while(n){
		sum += n%10;
		n /= 10;
	}
	return sum==10;
}

int main(){
	scanf("%d",&n); int cnt = 1;
	while(cnt != n){
		ans += 1;
		while(!check(ans)) ans+=1;
		cnt++;
	}
	printf("%lld\n",ans);
	return 0;
}