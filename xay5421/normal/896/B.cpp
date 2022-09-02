#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int a[1005];
int main(){
	int n,m,c;
	scanf("%d%d%d",&n,&m,&c);
	rep(i,1,m){
		int x;
		scanf("%d",&x);
		if(x<=c/2){
			rep(i,1,n)if(!a[i]||x<a[i]){
				a[i]=x;
				printf("%d\n",i);
				fflush(stdout);
				break;
			}
		}else{
			per(i,n,1)if(!a[i]||x>a[i]){
				a[i]=x;
				printf("%d\n",i);
				fflush(stdout);
				break;
			}
		}
		bool flg=0;
		rep(i,1,n)if(!a[i])flg=1;
		rep(i,1,n-1)if(a[i]>a[i+1])flg=1;
		if(!flg)break;
	}
	return 0;
}