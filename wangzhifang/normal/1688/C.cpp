#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
constexpr int max_len=200000;
char str[max_len+1];
void test(){
	int n;
	scanf("%d",&n);
	char ans=0;
	for(int i=n<<1|1; i; --i){
		scanf("%s",str);
		const int l=strlen(str);
		for(int j=0; j<l; ++j)
			ans^=str[j];
	}
	printf("%c\n",ans);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}