#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int n,k,a1=0,a2=0,a3=0,a4=0,cnt=1,c;
	for(scanf("%d%d",&n,&k); n&&scanf("%1d",&c); --n,++cnt)
		if(c)
			a3=a3?a3:cnt,a4=cnt;
		else
			a1=a1?a1:cnt,a2=cnt;
	if(a2-a1<k||a4-a3<k){
		puts("tokitsukaze");
		return 0;
	}
	int s[]={a1,a2,a3,a4};
	sort(s,s+4);
	if(s[3]-s[1]>k||s[2]-s[0]>k)
		puts("once again");
	else
		puts("quailty");
	return 0;
}