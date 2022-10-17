#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int maxn=500005;
int n,m,T,ans;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),ans+=a[i]-1;
		puts(ans&1? "errorgorn":"maomao90");
	}
	return 0;
}