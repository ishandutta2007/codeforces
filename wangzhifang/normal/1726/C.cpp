#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
void test(){
	int n;
	scanf("%d",&n);
	int ans=n+1;
	n<<=1;
	char lst='(';
	for(int i=1; i<=n; ++i){
		char ch=getchar();
		if(ch=='('){
			lst='(';
			continue;
		}
		if(ch==')'){
			if(lst=='(')
				--ans;
			lst=')';
			continue;
		}
		--i;
	}
	printf("%d\n",ans);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}