#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define F first
#define S second
#define pb push_back

const int MN = 1e6+6;
int N, i, x; ll cnt;

int main(){
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&x);
		if(x&1) cnt ++;
	}
	if(cnt&1) printf("First\n");
	else if(!cnt) printf("Second\n");
	else printf("First\n");
	return 0;
}