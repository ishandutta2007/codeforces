// *

#include<stdio.h>
#pragma warning(disable:4996)
#define MN 100000

int N;
int A[MN],cnt[MN];
long long ans;

int main()
{
//	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
	scanf("%d", &N);
	int i,l,r,lm=(N-1)/2,rm=N/2;
	for (i = 0; i < N; i++)scanf("%d", &A[i]), A[i]--;
	for (i = 0; i < N; i++)if (A[i] != A[N - i - 1])break;
	if (i == N){
		ans = (long long)N*(N + 1) / 2;
		printf("%lld", ans);
		return 0;
	}
	l = i;
	r = N - i - 1;
	for (i = l; i <= r; i++){
		cnt[A[i]]++;
	}

	int key=-1;
	if (N % 2 == 1){
		for (i = 0; i<N; i++)if (cnt[i] & 1)break;
		key = i;
	}

	int oddn = 0;
	for (i = 0; i<N; i++)oddn += (cnt[i] & 1);
	if (N % 2 == 0 && oddn>0){
		puts("0");
		return 0;
	}
	if (N % 2 == 1 && oddn > 1){
		puts("0");
		return 0;
	}
	for (i = r; i >lm; i--){
		if (cnt[A[i]] < 2)break;
		cnt[A[i]] -= 2;
	}
	if (i == lm){
		if (A[lm] == key || key==-1){
			for (i = lm ; i>l; i--){
				if (A[i] != A[N - i - 1])break;
			}
		}
		else{
			i = lm;
		}
	}
	ans += (long long)(l + 1)*(N - i);

	for (i = 0; i < N; i++)cnt[i] = 0;
	for (i = l; i <= r; i++){
		cnt[A[i]]++;
	}
	for (i = l; i <rm; i++){
		if (cnt[A[i]] < 2)break;
		cnt[A[i]] -= 2;
	}
	if (i == rm){
		if (A[rm] == key || key == -1){
			for (i = rm; i < r; i++){
				if (A[i] != A[N - i - 1])break;
			}
		}
		else{
			i = rm;
		}
	}
	ans += (long long)(i + 1)*(N - r);
	ans -= (long long)(l + 1)*(N - r);
	printf("%lld", ans);
	return 0;
}

//*/