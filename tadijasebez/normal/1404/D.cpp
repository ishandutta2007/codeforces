#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1000050;
int a[N],x[N],f[N],take[N],was[N];
int main(){
	int n;
	scanf("%i",&n);
	if(n%2==0){
		printf("First\n");
		for(int i=1;i<=2*n;i++)printf("%i ",(i-1)%n+1);
		fflush(stdout);
	}else{
		printf("Second\n");
		fflush(stdout);
		for(int i=1;i<=2*n;i++){
			scanf("%i",&a[i]);
			x[a[i]]^=i;
			f[a[i]]=i;
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			if(!was[i]){
				int u=i,d=f[i];
				while(!was[u]){
					was[u]=true;
					sum+=d;sum%=2*n;
					take[d]=1;
					d^=x[u];
					int nxt=d;
					if(d<=n)nxt+=n;
					else nxt-=n;
					u=a[nxt];
					d=nxt;
				}
			}
		}
		int tk=1;
		if(sum==n){
			tk=0;
		}
		for(int i=1;i<=2*n;i++){
			if(take[i]==tk)printf("%i ",i);
		}
		printf("\n");
		fflush(stdout);
	}
	return 0;
}