//
//  main.cpp
//  CF965E
//
//  Created by  on 2018/5/8.
//  Copyright  2018 . All rights reserved.
//

#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

struct st_n{
	int nxt[30] = {0};
	priority_queue<int , vector<int>, less<int> > pq;
} tr[200010];

int n,m,usi = 1;
char str[300030];
void dfs(int num){
	int o = tr[num].pq.empty();
	for(int i=0;i<26;i++){
		if(tr[num].nxt[i] == 0)continue;
		int nx = tr[num].nxt[i];
		dfs(nx);
		while(!tr[nx].pq.empty()){
			tr[num].pq.push(tr[nx].pq.top()+1);
			tr[nx].pq.pop();
		}
	}
	if(o){
		tr[num].pq.pop();
		tr[num].pq.push(1);
	}
}
int main() {
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>str;
		m = strlen(str);
		int p = 0;
		for(int j=0;j<m;j++){
			if(tr[p].nxt[str[j]-'a'] == 0){
				tr[p].nxt[str[j]-'a'] = usi;
				usi+=1;
			}
			p = tr[p].nxt[str[j]-'a'];
		}
		tr[p].pq.push(1);
	}
	tr[0].pq.push(0);
	dfs(0);
	int ans = 0;
	while(!tr[0].pq.empty()){
		ans+=tr[0].pq.top();
		tr[0].pq.pop();
	}
	cout<<ans-n<<endl;
	return 0;
}