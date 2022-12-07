#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;

int xs[300005];

void solve(){
	int a,b;
	scanf("%d%d",&a,&b);
	if (xs[a-1]==b) printf("%d\n",a);
	else printf("%d\n",a+(xs[a]==b?2:1));
}
int main(){
	for (int i=1;i<=300000;i++)
		xs[i]=xs[i-1]^i;
	int T;
	scanf("%d",&T);
	while (T--) solve();
}