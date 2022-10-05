#include<bits/stdc++.h>
using namespace std;
int n;
int t[210000];
int tt[210000];
int ls[20];
int rs[20];
int lo[1000000];
int main(){
	lo[0]=1;
	lo[1]=1;
	for(int i=2;i<=500000;i++) lo[i]=lo[(i+1)/2]*2;
	int _;
	scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) t[i]=0;
		for(int i=1;i<=n;i++){
			int a;
			scanf("%d",&a);
			t[a]++;
		}
		tt[0]=0;
		for(int i=1;i<=n;i++) tt[i]=tt[i-1]+t[i];
		int u=0,j=0;
		for(int i=0;i<20;i++){
			for(;;){
				if((j==n)||(u+t[j+1]>(1<<i))) break;
				j++;
				u+=t[j]; 
			}
			ls[i]=j;
		}
		u=0;
		j=n+1;
		for(int i=0;i<20;i++){
			for(;;){
				if((j==1)||(u+t[j-1]>(1<<i))) break;
				j--;
				u+=t[j]; 
			}
			rs[i]=j;
		}
		int ans=1000000;
		for(int i=0;i<20;i++){
			for(int ii=0;ii<20;ii++){
				ans=min(ans,(1<<i)+(1<<ii)+lo[max(0,tt[rs[ii]-1]-tt[ls[i]])]-n);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}