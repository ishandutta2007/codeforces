//
//  main.cpp
//  Round 488
//
//  Created by  on 2018/7/1.
//  Copyright  2018 . All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct P{
	double x,y;
	P operator - (const P &rhs) const{
		return (P){x-rhs.x,y-rhs.y};
	}
	double det(P r){
		return x*r.y-y*r.x;
	}
};

P a[4],b[4];

int main() {
	for(int i=0;i<4;i++){
		cin>>a[i].x>>a[i].y;
	}
	for(int i=0;i<4;i++){
		cin>>b[i].x>>b[i].y;
	}
	int ans = 0;
	for(int x=4;x<8;x++)for(int y=4;y<8;y++){
		if((a[x%4]-a[(x-1)%4]).det(b[y%4]-a[x%4])*(a[x%4]-a[(x-1)%4]).det(b[(y-1)%4]-a[x%4])<=0)
			if((b[y%4]-b[(y-1)%4]).det(a[x%4]-b[y%4])*(b[y%4]-b[(y-1)%4]).det(a[(x-1)%4]-b[y%4])<=0){
				ans = 1;
			}
	}
	P ac = (P){(a[0].x+a[3].x)/2.0,(a[0].y+a[3].y)/2.0},bc = (P){(b[0].x+b[3].x)/2.0,(b[0].y+b[3].y)/2.0};
	double bs = (b[0]-b[3]).det(ac-b[0]);
	int o = 1;
	for(int i=1;i<4;i++)if((b[i]-b[i-1]).det(ac-b[i])*bs<=0)o = 0;
	if(o) ans = 1;
	bs = (a[0]-a[3]).det(bc-a[0]);
	o = 1;
	for(int i=1;i<4;i++)if((a[i]-a[i-1]).det(bc-a[i])*bs<=0)o = 0;
	if(o) ans = 1;
	if(ans){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}