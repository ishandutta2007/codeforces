#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		int l,r;
		scanf("%d%d",&l,&r);
		if(l*2-1>=r)
			puts("YES");
		else puts("NO");
	}
	return 0;
}