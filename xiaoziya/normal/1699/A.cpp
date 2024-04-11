#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n&1)
			puts("-1");
		else printf("%d 0 0\n",n/2);
	}
	return 0;
}