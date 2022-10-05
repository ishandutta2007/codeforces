#include<bits/stdc++.h> 
using namespace std;
int a[1100000];
multiset<long long> ms;
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		ms.clear();
		int n,x;
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) ms.insert(a[i]);
		int r=0;
		for(int i=1;i<=n;i++){
			if((i>1)&&(a[i]==a[i-1])) continue;
			if((a[i]%x>0)||(ms.count(a[i]/x)==0)){
				long long y=a[i];
				int t=0;
				for(;;y*=x){
					//cout<<ms.count()<<endl;
					int uu=ms.count(y);
					if(uu==0) break;
					r+=min(t,uu);
					t=uu-min(t,uu);
					//cout<<t<<endl;
				} 
				//printf("%d\n",r);
			} 
		}
		printf("%d\n",n-2*r);
	} 
	return 0;
}