//*

#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
#define MN 200000
#define TN 262144

using namespace std;

int N;
int A[MN], B[MN];
int add[MN],p[MN],pos[MN];
int T[2 * TN];

bool cmpB(int a, int b){
	return B[a] < B[b];
}
bool cmpA(int a, int b){
	return A[a] < A[b];
}

int sum(int l, int r){
	int v = 0;
	for (l += TN, r += TN; l <= r; l >>= 1, r >>= 1){
		if (l & 1){
			v += T[l];
			l++;
		}
		if (!(r & 1)){
			v += T[r];
			r--;
		}
	}
	return v;
}
void update(int n){
	for (n += TN; n; n >>= 1){
		T[n]++;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
	int i,l,m,r,ans;
	scanf("%d", &N);
	for (i = 0; i < N; i++)scanf("%d", &A[i]);
	for (i = 0; i < N; i++)scanf("%d", &B[i]);
	for (i = 0; i < N; i++)p[i] = i;
	sort(p, p + N, cmpB);
	for (i = 0; i < N; i++){
		add[p[i]] = sum(p[i], N - 1);
		update(p[i]);
	}
	for (i = 0; i < 2 * TN; i++)T[i] = 0;

	for (i = 0; i < N; i++)p[i] = i;
	sort(p, p + N, cmpA);
	for (i = 0; i < N; i++){
		pos[p[i]] = sum(p[i], N - 1);
		update(p[i]);
	}
	for (i = 0; i < 2 * TN; i++)T[i] = 0;

	for (i = N - 1; i >= 0; i--){
		if (pos[i] + add[i] >= N - i){
			if (i)add[i - 1] += (pos[i] + add[i]) / (N - i);
			pos[i] = (pos[i] + add[i]) % (N - i);
		}
		else{
			pos[i] += add[i];
		}
	}
	for (i = 0; i < N; i++){
		l = 0, r = N - 1;
		while (l <= r){
			m = (l + r) >> 1;
			int val = sum(0, m) + pos[i];
			if (val < m){
				r = m - 1;
			}
			else if(val==m){
				r=m-1;
				ans=m;
			}
			else{
				l = m + 1;
			}
		}
		A[i] = ans;
		update(ans);
	}
	for (i = 0; i < N; i++)printf("%d ", A[i]);
	return 0;
}

//*/