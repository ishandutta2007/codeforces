#include <cstdio>
using namespace std;
int a[200005],b[200005][2],que[200005];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	int l=1,r=0,pre=0,bcnt=0;
	for(int i=n; i; --i){
		switch(a[i]){
			case 1:
				++bcnt;
				b[bcnt][0]=i,b[bcnt][1]=i;
				que[++r]=i;
				break;
			case 2:
				if(l>r){
					puts("-1");
					return 0;
				}
				++bcnt;
				b[bcnt][0]=que[l],b[bcnt][1]=i;
				++l,pre=i;
				break;
			case 3:
				++bcnt;
				b[bcnt][0]=i,b[bcnt][1]=i;
				if(!pre&&l>r){
					puts("-1");
					return 0;
				}
				b[++bcnt][0]=i;
				if(pre)
					b[bcnt][1]=pre;
				else{
					b[bcnt][1]=que[l];
					++l;
				}
				pre=i;
				break;
		}
	}
	printf("%d\n",bcnt);
	for(int i=1; i<=bcnt; ++i)
		printf("%d %d\n",b[i][0],b[i][1]);
	return 0;
}