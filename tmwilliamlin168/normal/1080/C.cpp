#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
unsigned long long  T,n,m;
unsigned long long a1,a2,b1,b2,c1,c2,d1,d2,e1,e2;
ll l,r,u,d,x,y,z;
int check(ll i,ll j){
	if((i+j)%2)return 0;//hei
	return 1;//bai
}
int main(){
	cin>>T;
	while(T--){
		x=y=0;
		cin>>n>>m;
		cin>>a1>>b1>>c1>>d1;
		cin>>a2>>b2>>c2>>d2;
		e1=(c1-a1+1)*(d1-b1+1);
		e2=(c2-a2+1)*(d2-b2+1);
		ll ans=n*m;
		ll w=0;
		if(n%2&&m%2)w=ans/2+1;
		else w=ans/2;
		l=max(a1,a2); 
		r=min(c1,c2);
		u=min(d1,d2);
		d=max(b1,b2);
		int f=0;
		if(r>=l&&u>=d){
			ll a=r-l+1,b=u-d+1;
			y=a*b;
			if(y%2){
				if(check(l,d))f=1;
				else f=2;
			}
			else f=3;
		}
		w+=e1/2;
		if(!check(a1,b1)&&e1%2)w++;
		w-=e2/2;
		if(check(a2,b2)&&e2%2)w--;
		w-=y/2;
		if(f==2)w--;
		cout<<w<<" "<<ans-w<<endl;
	}
}