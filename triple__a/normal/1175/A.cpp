#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long ll;

ll u,v,ans=0;
int t;
int main(){
	scanf("%d",&t);
	while(t--){
		ans=0; 
		scanf("%lld%lld",&u,&v);
		while (u>0){
			ans+=u%v;
			u=u-u%v;
			while(u%v==0&&u>0){
				ans++;
				u=u/v; 
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
	
}