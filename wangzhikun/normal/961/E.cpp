//
//  main.cpp
//  simple problem
//
//  Created by  on 2018/4/12.
//  Copyright  2018 . All rights reserved.
//

#include <map>
#include <queue>
#include <iostream>

using namespace std;
typedef long long ll;
int n,c;
map<int,int> a;
int lowbit(int x){
	return x&(-x);
}
void modify(int p,int v){
	while(p<1e9+10){
		a[p]+=v;
		p+=lowbit(p);
	}
}
int su(int p){
	int ret = 0;
	while(p>0){
		ret+=a[p];
		p-=lowbit(p);
	}
	return ret;
}
priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> q;
int main() {
	ll ans = 0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c;
		//f(!q.empty())cout<<q.top().first<<endl;
		while(!q.empty()&&q.top().first<i){
			modify(q.top().second,-1);
			//cout<<"DEL:: "<<q.top().first<<' '<<q.top().second<<endl;
			q.pop();
		}
		ans+=su(c);
		//cout<<i<<' '<<ans<<endl;
		q.push(make_pair(c,i));
		modify(i,1);
	}
	cout<<ans<<endl;
	return 0;
}