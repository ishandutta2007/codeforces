//
//  main.cpp
//  Round 477
//
//  Created by  on 2018/4/29.
//  Copyright  2018 . All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll x1,y1,x2,y2;
ll n,m,cl,ce,v,q;
ll l[100010],e[100010];

ll lb(ll *a,ll rb,ll y){
	ll l = -1,r = rb-1,mid;
	while(r-l>1){
		mid = (l+r)/2;
		if(a[mid]>=y)r = mid;
		else l = mid;
	}
	return r;
}
ll fd(ll *a,ll oy1,ll oy2,ll r){
	ll y2 = max(oy1,oy2);
	ll y1 = min(oy1,oy2);
	ll cans = 999999999999;
	ll p1 = lb(a, r, y1),p2 = lb(a, r, y2);
	//cout<<p1<<' '<<p2<<endl;
	for(ll i=p1-2;i<p1+3;i++){
		if(i>=0 && i<r){
			cans = min(cans,max(y2,a[i])-min(y2,a[i])+max(y1,a[i])-min(y1,a[i]));
		}
	}
	for(ll i=p2-2;i<p2+3;i++){
		if(i>=0 && i<r){
			cans = min(cans,max(y2,a[i])-min(y2,a[i])+max(y1,a[i])-min(y1,a[i]));
		}
	}
	/*
	if((a[p1]<=y2 && a[p1]>=y1) || (a[p2]>=y1 && a[p2]<=y2)||(p2>0&&a[p2-1]>=y1)){
		cans = min(cans,y2-y1);
	}
	if(p1>0){
		cout<<"SEC"<<(y1-a[p1-1])*2+y2-y1<<endl;
		cans = min(cans,(y1-a[p1-1])*2+y2-y1);
	}
	if(p2<r && a[p2]>=y2){
		//cout<<a[p2]<<' '<<y2<<endl;
		cout<<"THI"<<(a[p2]-y2)*2+y2-y1<<endl;
		cans = min(cans,(a[p2]-y2)*2+y2-y1);
	}
	 */
	//cout<<"AN"<<cans<<endl;
	return cans;
}
int main() {
	cin>>n>>m>>cl>>ce>>v;
	for(int i=0;i<cl;i++)cin>>l[i];
	for(int i=0;i<ce;i++)cin>>e[i];
	sort(l,l+cl);
	sort(e,e+ce);
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>x1>>y1>>x2>>y2;
		if(x1 == x2){
			cout<<abs(y1-y2)<<endl;
			continue;
		}
		ll dista = fd(l,y1,y2,cl),distb = fd(e,y1,y2,ce);
		cout<<min(dista+abs(x1-x2),distb+((abs(x1-x2)+v-1)/v))<<endl;
	}
	return 0;
}