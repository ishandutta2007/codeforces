#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005;
int h,a[N];
int main(){
	scanf("%d",&h);
	rep(i,0,h)scanf("%d",&a[i]);
	assert(a[0]==1);
	int tt=0;
	rep(i,0,h-1)tt+=a[i]>1&&a[i+1]>1;
	if(tt>0){
		puts("ambiguous");
		printf("0 ");
		int lst=1,cur=1;
		rep(i,1,h){
			int tmp=cur+1;
			rep(j,1,a[i]){
				printf("%d ",lst);
			}
			cur+=a[i];
			lst=tmp;
		}
		puts("");
		printf("0 ");
		lst=1,cur=1;
		rep(i,1,h){
			int tmp=cur+1;
			rep(j,1,a[i]){
				if(j>1){
					lst=cur;
				}
				printf("%d ",lst);
			}
			cur+=a[i];
			lst=tmp;
		}
		puts("");
	}else{
		puts("perfect");
	}
	return 0;
}