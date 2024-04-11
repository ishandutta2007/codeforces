#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

int T, i, x, y, a, b;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&x,&y,&a,&b);
		if(x==a||y==b) printf("%d\n",abs(x-a)+abs(y-b));
		else printf("%d\n",abs(x-a)+abs(y-b)+2);
	}
	return 0;
}