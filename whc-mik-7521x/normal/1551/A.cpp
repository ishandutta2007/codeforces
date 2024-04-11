#include<bits/stdc++.h>
using namespace std;
int t,ans1,ans2,w;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&w);
		ans1=ans2=w/3;
		if(w%3==2)ans2++;
		if(w%3==1)ans1++;
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
}