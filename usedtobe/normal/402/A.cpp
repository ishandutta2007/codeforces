#include<cstring>
#include<cstdio>
using namespace std;

int main() {
	int k,a,b,v,ans=0;
	scanf("%d%d%d%d",&k,&a,&b,&v);
	int c=(a/v)+((a%v==0)?0:1);int now=1;--c;++ans;
	while (c) {
		if (b==0) ++ans;
		else {
			if (now==k) {
				now=1;
				++ans;
			} else {
				++now;
				--b;
			}
		}
		c--;
	}
	printf("%d\n",ans);
	return 0;
}