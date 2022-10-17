#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
void solve(){
	int a,b,c;
	cin>>a>>b>>c;
	if(a==b+c||b==a+c||c==a+b)puts("YES");
	else puts("NO");
}
int main(){
	int t=in();
	while(t--)solve();
	return 0;
}