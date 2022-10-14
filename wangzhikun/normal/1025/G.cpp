//  Created by  on 2018/9/5.

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
	x = 0;ll f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch = getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch = getchar();}x*=f;
}

ll n,mod = 1e9+7,p2[1010],deg[1010] = {0},cu;
int main() {
	read(n);
	p2[0] = 1;
	for(int i=1;i<510;i++)p2[i] = p2[i-1]*2%mod;
	for(int i=0;i<n;i++){
		read(cu);
		if(cu!=-1)deg[cu]+=1;
	}
	ll po = p2[n-1]-1,cup = 0;
	for(int i=0;i<=n;i++){
		cup = (cup+p2[deg[i]]-1)%mod;
	}
	cout<<(po-cup+mod)%mod<<endl;
	return 0;
}