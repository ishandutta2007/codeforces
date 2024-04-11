//
//  main.cpp
//  Round 478
//
//  Created by  on 2018/5/2.
//  Copyright  2018 . All rights reserved.
//

#include <cmath>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n,q;
long double x,y,pi = acos(-1);
struct P{
	long double x,y;
	P operator - (const P &rhs) const{
		return (P){x-rhs.x,y-rhs.y};
	}
	P operator + (const P &rhs) const{
		return (P){x-rhs.x,y-rhs.y};
	}
	long double det(P r){
		return x*r.y-y*r.x;
	}
	long double dist(){
		return sqrt(x*x+y*y);
	}
} ve[100010],g;

ll rt = -1,op,o1,o2;
long double sux = 0,suy = 0,sus = 0,rtx = 0,rty = 0;

P rela(ll a,ll b){
	if(a == b)return (P){0,0};
	long double da = (ve[a]-g).dist(),db = (ve[a]-ve[b]).dist(),dc = (ve[b]-g).dist();
	long double de = acos((da*da+db*db-dc*dc)/(2*da*db));
	if(de!=de){
		de = 0;
	}
	if((g-ve[a]).det(ve[b]-g)<0) de*=-1;
	return (P){db*sin(de),-1*db*cos(de)};
}

ll uninit = 1,d1 = 0,d2 = 1,fr;
int main() {
	cout<<fixed<<setprecision(15);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>ve[i].x>>ve[i].y;
	}
	for(int i=1;i<n-1;i++){
		long double cs = (ve[i]-ve[0]).det((ve[i+1]-ve[0])),cx = (ve[0].x+ve[i].x+ve[i+1].x)/3,cy = (ve[0].y+ve[i].y+ve[i+1].y)/3;
		sus+=cs;
		sux += cx*cs;
		suy += cy*cs;
	}
	sux/=sus;
	suy/=sus;
	g.x = sux;
	g.y = suy;
	//cout<<sux<<' '<<suy<<endl;
	for(int i=0;i<q;i++){
		cin>>op;
		if(op == 1){
			cin>>o1>>o2;
			o1-=1;o2-=1;
			ll nessary = 0;
			if(o1 == d1){
				nessary = (rt == d1 && rt!=d2)? 1 : 0;rt = d2;fr = d1;
				d1 = o2;
			}
			else if(o1 == d2){
				nessary = (rt == d2 && rt!=d1)? 1 : 0;rt = d1;fr = d2;
				d2 = o2;
			}
			if(uninit){
				rtx = ve[rt].x;
				rty = ve[rt].y;
				uninit = 0;
			}else{
				if(!nessary) continue;
				P cg = rela(fr,rt);
				rtx+=cg.x;
				rty+=cg.y;
			}
		}
		
		if(op == 2){
			cin>>o1;
			o1-=1;
			if(!uninit){
				P cg = rela(rt,o1);
				cout<<rtx+cg.x<<' '<<rty+cg.y<<endl;
			}else{
				cout<<ve[o1].x<<' '<<ve[o1].y<<endl;
			}
		}
	}
	return 0;
}