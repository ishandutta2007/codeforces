#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	a--;b--;
	int res=0;
	while (a!=b){a/=2;b/=2;res++;}
	if ((1<<res)==n) {cout<<"Final!"<<endl;}
	else cout<<res<<endl;
}