#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int N;
char S[100100];
int A[100100];
int C[30];

void fi() {
	int p = 0;
	for (int i=0;i<N;i++) {
		if (A[i]!=-1) continue;
		while(C[p]==0) p++;
		A[i] = p;
		C[p]--;
	}
}

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf(" %s",S);
		N = strlen(S);
		bool same = true;
		for (int i=1;i<N;i++) {
			if (S[i]!=S[i-1]) same = false;
		}
		if (same) {
			puts(S);
			continue;
		}
		for (int i=0;i<26;i++) C[i] = 0;
		for (int i=0;i<N;i++) C[S[i]-'a']++;
		int uniq = -1;
		for (int i=0;i<26;i++) {
			if (C[i]==1) {
				uniq = i;
				break;
			}
		}
		if (uniq!=-1) {
			for (int i=0;i<N;i++) {
				if (S[i]=='a'+uniq) {
					swap(S[0],S[i]);
					sort(S+1,S+N);
					break;
				}
			}
			puts(S);
			continue;
		}
		int mini = -1;
		for (int i=0;i<26;i++) {
			if (C[i]) {
				mini = i;
				break;
			}
		}
		for (int i=0;i<N;i++) A[i] = -1;
		if ((C[mini]-1)*2<=N) {
			A[0] = mini;
			for (int i=0;i<C[mini]-1;i++) {
				A[i*2+1] = mini;
			}
			C[mini] = 0;
			fi();
		}
		else {
			int num = 0, smin = -1, tmin = -1;
			for (int i=0;i<26;i++) {
				if (i!=mini && C[i]) {
					if (smin==-1) smin = i;
					else if (tmin==-1) tmin = i;
					num++;
				}
			}
			if (num>=2) {
				A[0] = mini;
				A[1] = smin;
				for (int i=0;i<C[mini]-1;i++) {
					A[i+2] = mini;
				}
				A[C[mini]+1] = tmin;
				C[mini] = 0;
				C[smin]--;
				C[tmin]--;
				fi();
			}
			else {
				A[0] = mini;
				for (int i=0;i<C[smin];i++) {
					A[i+1] = smin;
				}
				for (int i=C[smin]+1;i<N;i++) {
					A[i] = mini;
				}
			}
		}
		for (int i=0;i<N;i++) S[i] = 'a'+A[i];
		puts(S);
	}

	return 0;
}