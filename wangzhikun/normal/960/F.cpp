//
//  main.cpp
//  Pathwalks
//
//  Created by  on 2018/4/12.
//  Copyright  2018 . All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
struct st_n{
	int m,ls = 0,rs = 0,l,r;
} t[2000000];

int n,m;
int u,v,w,cnt = 1;
void change(int u,int p,int v){
	if(t[u].l == t[u].r){
		t[u].m = v;
		return;
	}
	int mid = (t[u].r+t[u].l)/2;
	if(p<=mid){
		if(!t[u].ls){
			t[u].ls = cnt;
			cnt++;
			t[t[u].ls].l = t[u].l;
			t[t[u].ls].r = mid;
		}
		change(t[u].ls,p,v);
	}
	if(p>mid){
		if(!t[u].rs){
			t[u].rs = cnt;
			cnt++;
			t[t[u].rs].l = mid+1;
			t[t[u].rs].r = t[u].r;
		}
		change(t[u].rs,p,v);
	}
	t[u].m = max(t[t[u].ls].m,t[t[u].rs].m);
}
int query(int u,int p){
	if(t[u].l==t[u].r||p>=t[u].r)return t[u].m;
	int mid = (t[u].l+t[u].r)/2;
	if(p>mid){
		return max(t[t[u].ls].m,query(t[u].rs,p));
	}
	return query(t[u].ls,p);
}
int main(){
	cin>>n>>m;
	t[0].l = t[0].r = -1;
	t[0].m = 0;
	for(int i=1;i<=n;i++){
		t[i].l = 0;t[i].r = 100001;
	}
	cnt = n+1;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		change(v,w,query(u,w-1)+1);
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		ans = max(ans,query(i,100010));
	}
	cout<<ans<<endl;
	return 0;
}