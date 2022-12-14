#include <iostream>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 300000
char str[max_n+2];
il void test(){
	int n;
	scanf("%d\n%s",&n,str);
	str[n]=str[0];
	bool flg=1;
	for(int i=1; i<=n; ++i)
		if(str[i]=='<'){
			flg=0;
			break;
		}
	if(flg){
		printf("%d\n",n);
		return;
	}
	flg=1;
	for(int i=1; i<=n; ++i)
		if(str[i]=='>'){
			flg=0;
			break;
		}
	if(flg){
		printf("%d\n",n);
		return;
	}
	int ans=0;
	for(int i=1; i<=n; ++i)
		if(str[i]=='-'||str[i-1]=='-')
			++ans;
	printf("%d\n",ans);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}