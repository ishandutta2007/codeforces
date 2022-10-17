#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[10050],res,r;

void chk(int x){
	if(x>n)return;
	res++;
	int nmsl=max(0,x-r+1);
	for(int i=x+r-1;i>=nmsl;i--){
		if(a[i]){
			chk(i+r);
			return;
		}
	}
	cout<<-1;
	exit(0);
}

int main() {
	cin>>n>>r;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	chk(1);
	cout<<res;
}