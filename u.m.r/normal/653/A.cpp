#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int>PII;
typedef pair<ll, ll> PLL;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int a[MAXN];

int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= 1000; i ++)
		a[i] = 0;
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		a[x]++;
	}
//	sort(a + 1, a + n + 1);
	int flag = 0;
	for(int i = 1; i <= 998; i ++)
		if (a[i+1] && a[i+2] && a[i] )
			flag = 1;
	if (flag)
			puts("YES");
	else
			puts("NO");
	return 0;
}