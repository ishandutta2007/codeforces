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

int n,m,mp[4][60] = {0};
int mva[20020],mvb[20020],mvc[20020],mvn = 0;
void mv(int r,int c,int r1,int c1){
	if(mp[r][c] == 0)return;
	//cout<<r1+1<<' '<<c1+1<<endl;
	mva[mvn] = mp[r][c];
	mvb[mvn] = r1+1;
	mvc[mvn] = c1+1;
	if(mp[r1][c1]!=0 && (r1 == 1||r1 == 2)){
		cout<<"Wrong Move!"<<endl;
	}
	mp[r1][c1] = mp[r][c];
	mp[r][c] = 0;
	mvn+=1;
}
pair<int,int> find(int cco,int x,int y){
	int br = -1000,bc = -1000;
	for(int i=0;i<n;i++){
		if(mp[1][i]==cco){
			if(abs(1-x)+abs(i-y)<abs(br-x)+abs(bc-y)){
				br = 1;
				bc = i;
			}
		}
		if(mp[2][i]==cco){
			if(abs(2-x)+abs(i-y)<abs(br-x)+abs(bc-y)){
				br = 2;
				bc = i;
			}
		}
	}
	return make_pair(br, bc);
}
int main() {
	cin>>n>>m;
	for(int i=0;i<4;i++) for(int j=0;j<n;j++) cin>>mp[i][j];
	for(int j=0;j<n;j++) {
		if(mp[1][j] == mp[0][j]){
			mv(1,j,0,j);
		}
		if(mp[2][j] == mp[3][j]){
			mv(2,j,3,j);
		}
	}
	if(m == n*2 && mvn == 0){
		cout<<-1<<endl;
		return 0;
	}
	for(int col=1;col<=m;col++){
		int cr,cc,dr = 233,dc = 233;
		pair<int,int> cp = find(col,0,0);
		if(cp.first == -1000)continue;
		cr = cp.first;cc = cp.second;
		for(int i=0;i<n;i++){
			if(mp[0][i]==col){
				dr =0; dc = i;
			}
			if(mp[3][i]==col){
				dr =3; dc = i;
			}
		}
		//cout<<cr<<' '<<cc<<' '<<dr<<' '<<dc<<endl;
		cp = find(0,cr,3-cc);
		int spr = cp.first,spc = cp.second;
		
		if(spr == cr){
			mv(3-cr,spc,cr,spc);
			spr = 3-spr;
		}
		while(spc>cc){
			mv(spr,spc-1,spr,spc);
			spc-=1;
		}
		while(spc<cc){
			mv(spr,spc+1,spr,spc);
			spc+=1;
		}
		if(abs(cr-dr)!=1){
			mv(cr,cc,3-cr,cc);
			cr = 3-cr;
		}
		if(cc<dc){
			mv(3-cr,cc+1,3-cr,cc);
			mv(cr,cc+1,3-cr,cc+1);
			mv(cr,cc,cr,cc+1);
			cc+=1;
		}
		if(cc>dc){
			mv(3-cr,cc-1,3-cr,cc);
			mv(cr,cc-1,3-cr,cc-1);
			mv(cr,cc,cr,cc-1);
			cc-=1;
		}
		while(cc<dc){
			mv(3-cr,cc-1,cr,cc-1);
			mv(3-cr,cc,3-cr,cc-1);
			mv(3-cr,cc+1,3-cr,cc);
			mv(cr,cc+1,3-cr,cc+1);
			mv(cr,cc,cr,cc+1);
			cc+=1;
		}
		while(cc>dc){
			mv(3-cr,cc+1,cr,cc+1);
			mv(3-cr,cc,3-cr,cc+1);
			mv(3-cr,cc-1,3-cr,cc);
			mv(cr,cc-1,3-cr,cc-1);
			mv(cr,cc,cr,cc-1);
			cc-=1;
		}
		//cout<<dr<<endl<<endl<<endl;
		mv(cr,cc,dr,dc);
	}
	
	if(mvn>20000){
		cout<<-1<<endl;
		return 0;
	}
	cout<<mvn<<endl;
	for(int i=0;i<mvn;i++){
		cout<<mva[i]<<' '<<mvb[i]<<' '<<mvc[i]<<endl;
	}
	return 0;
}