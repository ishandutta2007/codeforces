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
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				if(n%2==0&&(i+n/2-1)%n+1==j)
					putchar('0');
				else if((i+n/2>n&&j<=n)||j<=(i+n/2-1)%n+1)
					putchar('1');
				else putchar('-'),putchar('1');
				putchar(' ');
			}
		puts("");
	}
	return 0;
}