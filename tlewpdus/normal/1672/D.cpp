#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
int A[200100];
int B[200100];
int C[200100];

int main() {
    int T;
    
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
		for (int i=0;i<N;i++) scanf("%d",&A[i]);
		for (int i=0;i<N;i++) scanf("%d",&B[i]);
		bool mang = false;
		{
			int i=N-1, j=N-1;
			while(i>=0) {
				if (j>=0 && A[i]==B[j]) {
					i--;j--;
				}
				else if (j>=0 && j+1<N && B[j]==B[j+1]) {
					C[B[j]]++;
					j--;
				}
				else if (C[A[i]]>0) {
					C[A[i]]--;
					i--;
				}
				else {
					mang = true;
					break;
				}
			}
		}
		puts(mang?"NO":"YES");
		for (int i=1;i<=N;i++) C[i] = 0;
    }
    
	return 0;
}