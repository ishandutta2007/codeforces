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
		if(n%7==0)
			printf("%d\n",n);
		else for(int i=n/10*10;i<=n/10*10+9;i++)
			if(i%7==0){
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}