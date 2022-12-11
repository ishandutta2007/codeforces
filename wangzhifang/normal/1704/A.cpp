#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int max_n=50;
char a[max_n+1],b[max_n+1];
void test(){
	int n,m;
	scanf("%d%d\n%s\n%s",&n,&m,a,b);
	while(m&&a[n-1]==b[m-1])
		--n,--m;
	if(m>1){
		puts("NO");
		return;
	}
	if(!m){
		puts("YES");
		return;
	}
	for(int i=0; i<n; ++i)
		if(a[i]==b[0]){
			puts("YES");
			return;
		}
	puts("NO");
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}