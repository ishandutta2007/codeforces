#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353; //1000000007

int N;
char S[200100];
char A[200100], B[200100];

int main() {
	int tt;
	scanf("%d",&tt);
	while(tt--) {
		scanf("%d",&N);
		scanf(" %s",S);
		bool mang = (S[0]=='0'||S[N-1]=='0');
		int c = 0;
		for (int i=0;i<N;i++) c+=(S[i]=='0');
		if (c%2) mang = 1;
		if (mang) {
			puts("NO");
			continue;
		}
		int a = 1, b = 1;
		for (int i=1;i+1<N;i++) {
			if (S[i]=='1') {
				if (a+b==2) A[i] = B[i] = '(', a++, b++;
				else A[i] = B[i] = ')', a--, b--;
			}
			else {
				if (b-a==2) A[i]='(',B[i]=')',a++,b--;
				else A[i]=')',B[i]='(',a--,b++;
			}
		}
		A[0]=B[0]='(';
		A[N-1]=B[N-1]=')';
		A[N]=B[N]=0;
		printf("YES\n%s\n%s\n",A,B);
	}

	return 0;
}