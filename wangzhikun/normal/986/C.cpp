// Author: Zhikun
// 2018.07.18

#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define N 200020

using namespace std;
typedef long long ll;

int n,m,cur,vv[4200000] = {0},vvv[4200000] = {0},ans = 0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>cur;
		vv[cur] = 1;
	}
	for(int ech=0;ech<(1<<n);ech++){
		if(vv[ech] && !vvv[ech]){
			ans++;
			queue<int> Q;
			int cur;
			Q.push((1<<n)-ech-1);
			vvv[(1<<n)-ech-1] = 1;
			while(!Q.empty()){
				cur = Q.front();
				Q.pop();
				if(vv[cur]&&(!vvv[(1<<n)-cur-1])){
					Q.push((1<<n)-cur-1);
					vvv[(1<<n)-cur-1] = 1;
				}
				for(int i=0;i<n;i++){
					if(((1<<i) & cur)&&(vvv[cur-(1<<i)] == 0)){
						Q.push(cur-(1<<i));
						vvv[cur-(1<<i)] = 1;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}