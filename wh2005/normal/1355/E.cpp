#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
#define ll long long
int n,f[100009],h[100009],ml,mr;
ll a,b,c;
void MN(int &x,int y){if(x==-1||x>y) x=y; return ;}
void MX(int &x,int y){if(x==-1||x<y) x=y; return ;}
ll dist(int t){
	for(int i=1;i<=n;i++) h[i]=f[i];
	ll cos=0;int flag;
	if(h[1]>=t) flag=-1;
	else flag=1;
	for(int i=n;i>=1;i--){
		if(h[i]<t) cos+=(t-h[i])*a,h[i]=t;
		else if(h[i]>t){
			if(flag==-1) cos+=(h[i]-t)*b,h[i]=t;
			else{
				while(h[i]-t>=t-h[flag]){
					cos+=(t-h[flag])*c;
					h[i]-=(t-h[flag]),h[flag]=t;
					flag++;if(h[flag]>=t){
						flag=-1;break;
					} 
				}
				if(flag!=-1){cos+=(h[i]-t)*c;h[flag]+=(h[i]-t),h[i]=t;}
				else{cos+=(h[i]-t)*b;h[i]=t;}
			}
		}
	}
	return cos;
}
int main(){
	scanf("%d%lld%lld%lld",&n,&a,&b,&c);ml=-1,mr=-1;
	if(c>a+b) c=a+b;
	for(int i=1;i<=n;i++){
		scanf("%d",&f[i]);
		MN(ml,f[i]);MX(mr,f[i]);
	} 
	sort(f+1,f+n+1);
	int l=ml,r=mr;
	while(l+10<r){
		int p=(l+r)/2,q=(p+r)/2;
		if(dist(p)>dist(q)) l=p;
		else r=q;
	}
	ll ans=-1;
	for(int i=l;i<=r;i++){
		if(ans==-1||ans>dist(i)) ans=dist(i);
	}
	printf("%lld",ans);
	return 0;
}