#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

int n,k;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
	#endif
	cin>>n>>k;
	if(n<k){
		cout<<"NO"<<endl;
		return 0;
	}
	priority_queue<int> que;
	for(int i=1;n;i<<=1){
		if(n&i){
			que.push(i);
			n -= i;
		}
	}
	if(k<que.size()){
		cout<<"NO"<<endl;
		return 0;
	}
	while(que.size()<k){
		int x=que.top();
		que.pop();
		que.push(x/2);
		que.push(x/2);
	}
	cout<<"YES"<<endl;
	while(!que.empty()){
		cout<<que.top()<<" ";
		que.pop();
	}
	cout<<endl;
	return 0;
}