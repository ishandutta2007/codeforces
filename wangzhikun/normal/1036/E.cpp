//  Created by  on 2018/9/7.

#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;int f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
struct P{
	ll x,y;
	P operator - (const P &r) const{
		P np;
		np.x = x-r.x;
		np.y = y-r.y;
		return np;
	}
	P operator + (const P &r) const{
		P np;
		np.x = x+r.x;
		np.y = y+r.y;
		return np;
	}
	P operator * (ll d){
		return (P){x*d,y*d};
	}
	P operator / (ll d){
		return (P){x/d,y/d};
	}
	ll det(P r){
		return x*r.y-y*r.x;
	}
} a[1005],b[1005];
P intersection(P p1,P p2,P q1,P q2){
	return p1+(p2-p1)*(q2-q1).det(q1-p1)/(q2-q1).det(p2-p1);
}
unordered_map<ll, int> amp,bmp;
ll n,cans = 0;
int main() {
	read(n);
	for(int i=0;i<n;i++){
		read(a[i].x);read(a[i].y);
		read(b[i].x);read(b[i].y);
		cans+=gcd(abs(a[i].x-b[i].x),abs(a[i].y-b[i].y))+1;
	}
	//cout<<cans<<endl;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if((a[i]-b[i]).det(a[j]-b[j]) == 0)continue;
			P cu = intersection(a[i], b[i], a[j], b[j]);
			//cout<<i<<' '<<j<<' '<<cu.x<<' '<<cu.y<<endl;
			if((cu-a[i]).det(b[i]-a[i]) == 0 &&  (cu-a[j]).det(b[j]-a[j]) == 0){
				//cout<<i<<' '<<j<<endl;
				if(cu.x<=max(a[i].x,b[i].x) && cu.x>=min(a[i].x,b[i].x) && cu.x<=max(a[j].x,b[j].x) && cu.x>=min(a[j].x,b[j].x))
				if(cu.y<=max(a[i].y,b[i].y) && cu.y>=min(a[i].y,b[i].y) && cu.y<=max(a[j].y,b[j].y) && cu.y>=min(a[j].y,b[j].y)){
					if(!amp[(cu.x+1000000)*2e9+(cu.y+1e6)*1000+i]){
						amp[(cu.x+1000000)*2e9+(cu.y+1e6)*1000+i] = 1;
						bmp[(cu.x+1000000)*2e6+(cu.y+1e6)]+=1;
						if(bmp[(cu.x+1000000)*2e6+(cu.y+1e6)]>1)cans-=1;
					}
					if(!amp[(cu.x+1000000)*2e9+(cu.y+1e6)*1000+j]){
						amp[(cu.x+1000000)*2e9+(cu.y+1e6)*1000+j] = 1;
						bmp[(cu.x+1000000)*2e6+(cu.y+1e6)]+=1;
						if(bmp[(cu.x+1000000)*2e6+(cu.y+1e6)]>1)cans-=1;
					}
				}
			}
		}
	}
	cout<<cans<<endl;
	return 0;
}