#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;

int n, m;

void prework(){

}

void read(){

}

inline double sqr(double x){
	return x * x;
}

int r;

int a[MAXN];
double y[MAXN];

void solve(int casi){
//	cout << "Case #" << casi << ": ";
	scanf("%d%d", &n, &r);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		double ans = r;
		for (int j = 1; j < i; j++){
			if (fabs(a[j] - a[i]) - 2 * r < eps){
				double p = sqrt(max(0.0, sqr(2 * r) - sqr(a[j] - a[i])));
				ans = max(ans, y[j] + p);
			}
		}
		y[i] = ans;
	}
	for (int i = 1; i <= n; i++)
		printf("%.15f%c", y[i], " \n"[i == n]);
}

void printans(){

}


int main(){
//	std::ios::sync_with_stdio(false);
	prework();
	int T = 1;
//	cin>>T;
	for(int i = 1; i <= T; i++){
		read();
		solve(i);
		printans();
	}
	return 0;
}