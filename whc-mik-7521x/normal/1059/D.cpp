#include<bits/stdc++.h>
using namespace std;
int n;
long double x[100005],y[100005];
bool check(long double r){
	long double ma=-1e17,mi=1e17;
	for(int i=1;i<=n;i++){
		if(r*2<y[i])return 0;
		long double len=sqrt(2*y[i]*r-y[i]*y[i]);
		mi=min(mi,x[i]+len);
		ma=max(ma,x[i]-len);
	}
	return mi>ma;
}
int main(){
	scanf("%d",&n);
	int pd=0;
	for(int i=1;i<=n;i++){
		scanf("%Lf%Lf",&x[i],&y[i]);
		if(y[i]>0){
			if(pd==2){
				cout<<-1;
				return 0;
			}
			pd=1;
		}
		if(y[i]<0){
			if(pd==1){
				cout<<-1;
				return 0;
			}
			pd=2;
		}
		y[i]=fabs(y[i]);
	}
	long double l=0,r=1e15,mid,ans=-1;
	int t=0;
	while(t<=128){
		t++;
		mid=(r+l)/2.0;
		if(check(mid)){
			r=mid;
			ans=mid;
		}
		else l=mid;
	}
	printf("%Lf",ans);
	return 0;
}