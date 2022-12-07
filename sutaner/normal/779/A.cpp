#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[10],b[10];
int n;
int main(){
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	scanf("%d",&n);
	int x,sum=0;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		a[x]++;	
	}
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		b[x]++;	
	}
	for(int i=1;i<=5;i++){
		if((a[i]+b[i])&1){
			printf("-1");
			return 0;
		}
		sum+=abs(a[i]-b[i]);
	}
	printf("%d",sum/4);
	return 0;
}