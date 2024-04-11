#include<bits/stdc++.h>
using namespace std;
int n;
inline int ask(int x){
	if (x==0||x==n+1)return 1e9;
	printf("? %d\n",x);
	fflush(stdout);
	scanf("%d",&x);
	return x;
}
int main(){
	scanf("%d",&n);
	int l=1,r=n;
	while (1){
		int mid=(l+r)/2;
		int v1=ask(mid-1),v2=ask(mid),v3=ask(mid+1);
		if (v2<v1&&v2<v3){
			printf("! %d\n",mid);
			fflush(stdout);
			return 0;
		}
		else if (v1<v2)r=mid-1;
		else l=mid+1;
	}
}