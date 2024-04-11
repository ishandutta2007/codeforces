//  Created by  on 2018/8/18.

#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

template<typename T> void read(T &x){
	x = 0;int f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,l[1000010],r[1000010],al[2000010],siz = 0,vis[1000010] = {0},vvv[2000020] = {0},ccount = 0,cmax1,cmax2;
vector<int> Mp[2000020];
void upd(int num){
	if(num>=cmax1){
		cmax2 = cmax1;
		cmax1 = num;
	}else{
		if(num>cmax2)cmax2 = num;
	}
}
void dfs(int num){
	siz+=1;
	vis[num] = 1;
	if(!vvv[l[num]]){
		upd(l[num]);
		vvv[l[num]] = 1;
		ccount+=1;
		for(auto cu:Mp[l[num]])if(!vis[cu]) dfs(cu);
	}
	if(!vvv[r[num]]){
		upd(r[num]);
		vvv[r[num]] = 1;
		ccount+=1;
		for(auto cu:Mp[r[num]]) if(!vis[cu]) dfs(cu);
	}
}
int main() {
	read(n);
	for(int i=0;i<n;i++){
		read(l[i]);read(r[i]);
		al[i] = l[i];al[i+n] = r[i];
	}
	sort(al,al+n*2);
	ll aln = unique(al, al+n*2)-al;
	for(int i=0;i<n;i++){
		l[i] = lower_bound(al, al+aln, l[i])-al;
		r[i] = lower_bound(al, al+aln, r[i])-al;
		Mp[l[i]].push_back(i);
		Mp[r[i]].push_back(i);
	}
	int cnt = 1,ans = 0,cans = 1;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			cmax1 = cmax2 = siz = ccount = 0;
			dfs(i);
			if(siz == ccount) ans = max(ans,cmax1);
			if(siz == ccount-1)ans = max(ans,cmax2);
			if(siz> ccount)cans = 0;
		}
	}
	if(cans) cout<<al[ans]<<endl;
	else cout<<-1<<endl;
	return 0;
}