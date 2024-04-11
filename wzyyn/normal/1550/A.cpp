#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	int x,y=1;
	scanf("%d",&x);
	for (;y*y<x;++y);
	cout<<y<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}