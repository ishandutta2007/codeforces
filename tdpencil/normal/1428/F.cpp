#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll hist[2000005], tot = 0, cur = 0;
int N, S[2000005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i){
		char x;
		cin >> x;
		S[i] = (x - '0');
	}
	for (int i = 1; i <= N; ++i){
		if (S[i] == 0) tot += cur;
		else{
			int l = i, r = i;
			while (r < N && S[r+1] == 1) r++;
			for (int x = 1; x <= (r-l+1); ++x){
				cur += (l-1+x) - hist[x];
				tot += cur;
				hist[x] = r-x+1;
			}
			i = r;
		}
	}
	cout << tot << '\n';
}