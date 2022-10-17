#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),m--;
		if(n&1)
			m+=m/(n/2);
		printf("%d\n",(1+m%n-1)%n+1);
	}
	return 0;
}