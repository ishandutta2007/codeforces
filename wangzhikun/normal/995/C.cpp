//
//  main.cpp
//  Round 492
//
//  Created by  on 2018/7/3.
//  Copyright  2018 . All rights reserved.
//


#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

struct ln{
	ll id;
	ll x,y;
} aln[200020];
struct mmm{
	ll tgt,typ;
};
struct mr{
	vector<mmm> mgs;
	ll sf = 1,tolz = 1;
} mrginfo[200020];

ll n,ans[202020];
ll sq(ll x){return x*x;}
int main() {
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>aln[i].x>>aln[i].y;
		aln[i].id = i;
	}
	for(int i=0;i<n-1;i++){
		
		/*
		 cout<<"======================="<<endl;
		 for(int j=0;j<3;j++){
		 cout<<aln[i+j].x<<"    "<<aln[i+j].y<<"    "<<aln[i+j].id<<"    "<<mrginfo[aln[i+j].id].mrg<<endl;
		 }*/
		
		if(i == n-2)break;
		for(int mt = 1;mt>-3;mt-=2){
			if(sq(aln[i].x+aln[i+1].x*mt)+sq(aln[i].y+aln[i+1].y*mt)<=(ll)1000000000000){
				mrginfo[aln[i+1].id].mgs.push_back((mmm){aln[i].id,mt});
				aln[i+1].x = aln[i].x*mt+aln[i+1].x;
				aln[i+1].y = aln[i].y*mt+aln[i+1].y;
				break;
			}
			if(sq(aln[i].x+aln[i+2].x*mt)+sq(aln[i].y+aln[i+2].y*mt)<=(ll)1000000000000){
				mrginfo[aln[i+2].id].mgs.push_back((mmm){aln[i].id,mt});
				aln[i+2].x = aln[i+2].x+aln[i].x*mt;
				aln[i+2].y = aln[i+2].y+aln[i].y*mt;
				break;
			}
			if(sq(aln[i+1].x+aln[i+2].x*mt)+sq(aln[i+1].y+aln[i+2].y*mt)<=(ll)1000000000000){
				mrginfo[aln[i+2].id].mgs.push_back((mmm){aln[i+1].id,mt});
				aln[i+2].x = aln[i+2].x+aln[i+1].x*mt;
				aln[i+2].y = aln[i+2].y+aln[i+1].y*mt;
				aln[i+1] = aln[i];
				break;
			}
		}
	}
	for(int mt = 1;mt>-3;mt-=2){
		if(sq(aln[n-2].x+aln[n-1].x*mt)+sq(aln[n-2].y+aln[n-1].y*mt)<=(ll)2250000000000){
			mrginfo[n-1].sf=mt;
			break;
		}
	}
	for(int i=n-1;i>=0;i--){
		ans[i] = mrginfo[i].sf;
		for(int j=0;j<mrginfo[i].mgs.size();j++){
			mrginfo[mrginfo[i].mgs[j].tgt].sf=mrginfo[i].mgs[j].typ*mrginfo[i].sf;
		}
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}