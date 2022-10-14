#pragma GCC optimize("O3")
//
//  main.cpp
//  Death Stars
//
//  Created by  on 2018/4/14.
//  Copyright  2018 . All rights reserved.
//

#include <cstring>
#include <iostream>

using namespace std;
typedef unsigned long long ull;

int n,m,a[200020],b[200020] = {0},c[200020],ans = 4100625,t = 0,ov = 0,s = 0;

int main() {
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i];
		t-=c[i];
		//cout<<t<<endl;
	}
	
	for(int e = 0;e<n;e++){
		if(b[a[e]]<c[a[e]]){
			t+=1;
		}else{
			ov+=1;
		}
		//cout<<e<<' '<<t<<endl;
		b[a[e]]+=1;
		if(t<0)continue;
		while(b[a[s]]>c[a[s]]){
			b[a[s]]-=1;
			s+=1;
			ov-=1;
		}
		//cout<<s<<' '<<e<<endl;
		ans = min(ans,ov);
	}
	if(ans!=4100625)cout<<ans<<endl;
	else cout<<-1<<endl;
	return 0;
}