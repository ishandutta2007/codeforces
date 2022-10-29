#include<bits/stdc++.h>
long long n,x,y,ans,i;
int main(){
    scanf("%d",&n);
    for(i=0;i<n;++i,x=y)scanf("%d",&y),ans+=abs(y-x)*(x<y?n-y+1:y);
	printf("%lld\n",ans);
}