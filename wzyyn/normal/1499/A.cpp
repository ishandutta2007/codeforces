#include<bits/stdc++.h>
using namespace std;

int F(int x,int y){
	return min(x,y)+abs(x-y)/2;
}
void solve(){
	int n,a,b,x,y;
	scanf("%d%d%d%d%d",&n,&a,&b,&x,&y);
	puts(F(a,b)>=x&&F(n-a,n-b)>=y?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}