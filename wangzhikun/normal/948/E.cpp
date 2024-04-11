//
//  main.cpp
//  CF470
//
//  Created by  on 2018/4/21.
//  Copyright  2018 . All rights reserved.
//

#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int qa[100010] = {0},qb[100010] = {0},qla[100010] = {0};
int pa[100010] = {0},pb[100010] = {0},pla[100010] = {0};
char a[100010],b[100010];
int n,m;
int la,lb,l1,r1,l2,r2;
int main() {
	cin>>a>>b;
	cin>>n;
	la = strlen(a);
	lb = strlen(b);
	for(int i=1;i<=la;i++){
		if(a[i-1] == 'A'){
			qa[i] = qa[i-1]+1;
			qla[i] = qla[i-1];
			qb[i] = qb[i-1];
		}else{
			qa[i] = qa[i-1];
			qla[i] = i;
			qb[i] = qb[i-1]+1;
		}
	}
	for(int i=1;i<=lb;i++){
		if(b[i-1] == 'A'){
			pa[i] = pa[i-1]+1;
			pla[i] = pla[i-1];
			pb[i] = pb[i-1];
		}else{
			pla[i] = i;
			pa[i] = pa[i-1];
			pb[i] = pb[i-1]+1;
		}
	}
	for(int i=0;i<n;i++){
		cin>>l1>>r1>>l2>>r2;
		int cna = qb[r1]-qb[l1-1],cnb = pb[r2]-pb[l2-1];
		int ans = 0;
		if(cnb == cna && cnb==0 && (r2-l2-r1+l1 == 0 ||((r2-l2-r1+l1)%3 == 0 && r2-l2-r1+l1<0))){
			ans = 1;
		}
		//cout<<r2-pla[r2]<<endl;
		if(cna == 0 && cnb%2 == 0 && cnb>0 && (r2-pla[r2] < r1-l1+1)){
			ans = 1;
		}
		if(cnb>cna && (cnb-cna)%2 == 0 && cna>0){
			if((r2-pla[r2] <= r1-qla[r1]))ans = 1;
		}
		if(cnb == cna&&cnb>0){
			if(!((r1-qla[r1]!=r2-pla[r2]) && !((r1-qla[r1]-r2+pla[r2])>0 && (r1-qla[r1]-r2+pla[r2])%3==0)))
				ans = 1;
		}
		cout<<ans;
	}
	cout<<endl;
	return 0;
}