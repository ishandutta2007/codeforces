#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n;
char str[200100];

void pung(){
	puts("No");
	exit(0);
}

int main() {
	scanf("%d",&n);
	scanf(" %s",str);
	int c = 0, mini = 0;
	for (int i=0;i<n;i++) {
		if (str[i]=='(') c++;
		else c--;
		mini = min(mini,c);
	}
	if (c) pung();
	if (mini<-1) pung();
	puts("Yes");

	return 0;
}