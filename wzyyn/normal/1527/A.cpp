#include<bits/stdc++.h>
using namespace std;

void solve(){
	int x,y;
	scanf("%d",&x);
	for (y=x;y!=(y&(-y));y-=y&(-y));
	cout<<y-1<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}