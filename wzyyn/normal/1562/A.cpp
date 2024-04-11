#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

void solve(){
	int l,r;
	scanf("%d%d",&l,&r);
	if (l*2>r) printf("%d\n",r-l);
	else printf("%d\n",(r+1)/2-1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}