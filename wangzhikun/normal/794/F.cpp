//
//  main.cpp
//  Round 414
//
//  Created by  on 2018/5/27.
//  Copyright  2018 . All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll read(){
	ll an = 0;char ch = getchar();
	while(!isdigit(ch))ch = getchar();
	while(isdigit(ch)){
		an = an*10+ch-48;
		ch = getchar();
	}
	return an;
}

ll n,q,a[400010] = {0},op,l,r,x,y;

struct st_n{
	ll l,r,dct[10] = {0},dcg[10];
	inline ll value(){
		ll an = 0;
		for(int i=0;i<10;i++)an+=dcg[i]*dct[i];
		return an;
	}
}t[400010];

void build_tree(){
	ll l = 1,cur,cnt = 1;
	while(l<n)l<<=1;
	for(ll i=l;i<l*2;i++){
		cur = a[i-l];
		t[i].l = t[i].r = i-l;
		cnt = 1;
		while(cur>0){
			t[i].dct[cur%10]+=cnt;
			cnt*=10;
			cur/=10;
		}
		for(int j=0;j<10;j++)t[i].dcg[j] = j;
	}
	for(ll i=l-1;i>0;i--){
		t[i].l = t[i*2].l;
		t[i].r = t[i*2+1].r;
		for(int j=0;j<10;j++)t[i].dcg[j] = j;
		for(int j=0;j<10;j++)t[i].dct[j] = t[i*2].dct[j]+t[i*2+1].dct[j];
	}
}

void push(ll id){
	for(int i=0;i<10;i++){
		t[id*2].dcg[i] = t[id].dcg[t[id*2].dcg[i]];
		t[id*2+1].dcg[i] = t[id].dcg[t[id*2+1].dcg[i]];
	}
	ll nccu[10] = {0};
	for(int i=0;i<10;i++){
		nccu[t[id].dcg[i]]+=t[id].dct[i];
	}
	for(int i=0;i<10;i++){
		t[id].dct[i] = nccu[i];
		t[id].dcg[i] = i;
	}
}

void sum_up(ll id){
	for(int i=0;i<10;i++){
		t[id].dct[i] = 0;
	}
	for(int i=0;i<10;i++){
		t[id].dct[t[id*2].dcg[i]]+=t[id*2].dct[i];
		t[id].dct[t[id*2+1].dcg[i]]+=t[id*2+1].dct[i];
	}
}

void change(ll id,ll l,ll r,ll x,ll y){
	if(t[id].l == l && t[id].r == r){
		for(int i=0;i<10;i++)if(t[id].dcg[i] == x)t[id].dcg[i] = y;
		return;
	}
	push(id);
	if(r<=t[id*2].r){
		change(id*2,l,r,x,y);
	}
	else if (l>=t[id*2+1].l){
		change(id*2+1,l,r,x,y);
	}else{
		change(id*2,l,t[id*2].r,x,y);
		change(id*2+1,t[id*2+1].l,r,x,y);
	}
	sum_up(id);
}

ll query(ll id,ll l,ll r){
	if(t[id].l == l && t[id].r == r){
		return t[id].value();
	}
	push(id);
	if(r<=t[id*2].r){
		return query(id*2,l,r);
	}
	else if (l>=t[id*2+1].l){
		return query(id*2+1,l,r);
	}else{
		return query(id*2,l,t[id*2].r)+query(id*2+1,t[id*2+1].l,r);
	}
}

int main() {
	n = read();q = read();
	for(int i=0;i<n;i++){
		a[i] = read();
	}
	build_tree();
	
	for(int i=0;i<q;i++){
		op = read();
		if(op == 1){
			l = read()-1;r = read()-1;x = read();y = read();
			change(1,l,r,x,y);
		}
		else{
			l = read()-1;r = read()-1;
			cout<<query(1,l,r)<<endl;
		}
	}
	return 0;
}