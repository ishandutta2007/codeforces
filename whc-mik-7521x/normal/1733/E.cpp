#include<bits/stdc++.h>
using namespace std;
long long px,py,q,t,x,y,a[240],b[240];
int main(){
	scanf("%lld",&q);
	while(q--){
		scanf("%lld%lld%lld",&t,&x,&y);
		if(t<x+y){
			puts("NO");
			continue;
		}
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		a[0]=t-x-y;
		b[0]=a[0]+1;
		for(int i=0;i<x+y;i++){
			for(int o=i;o>=0;o--){
				a[o+1]+=a[o]/2;
				a[o]-=a[o]/2;
				b[o+1]+=b[o]/2;
				b[o]-=b[o]/2;
			}
		}
		px=py=-1;
		for(int i=0;i<240;i++){
			if(a[i]!=b[i]){
				px=i;
				py=x+y-i;
				break;
			}
		}
		if(x==px&&y==py)puts("YES");
		else puts("NO");
	}
}