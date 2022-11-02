#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

int val[1048];

void read(){

}

void solve(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		val[i] = 1e9 + 1;
	vector<int> lst;
	for (int i = 9; i >= 0; --i){
		lst.clear();
		for (int j = 0; j < n; ++j)
			if (j >> i & 1)
				lst.push_back(j + 1);
		if (lst.size()){
			printf("%d\n", (int)lst.size());
			for (int j = 0; j < lst.size(); ++j)
				printf("%d%c", lst[j], "\n "[j + 1 < lst.size()]);
			fflush(stdout);

			for (int t, j = 0; j < n; ++j){
				scanf("%d", &t);
				if (~j >> i & 1)
					val[j] = min(val[j], t);
			}
		}

		lst.clear();
		for (int j = 0; j < n; ++j)
			if (~j >> i & 1)
				lst.push_back(j + 1);
		if (lst.size()){
			printf("%d\n", (int)lst.size());
			for (int j = 0; j < lst.size(); ++j)
				printf("%d%c", lst[j], "\n "[j + 1 < lst.size()]);
			fflush(stdout);

			for (int t, j = 0; j < n; ++j){
				scanf("%d", &t);
				if (j >> i & 1)
					val[j] = min(val[j], t);
			}
		}
	}
	puts("-1");
	for (int i = 0; i < n; ++i)
		printf("%d%c", val[i], "\n "[i + 1 < n]);
}

void printans(){

}
	

int main(){
	int T = 1;
//	cin>>T;
	while(T--){
		read();
		solve();
		printans();
	}
	return 0;
}