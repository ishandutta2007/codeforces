#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int N=2e5+5;
int n,k,tmp=1;
priority_queue<int> q;
int main(){
	cin>>n>>k;
	while(tmp<=n){
		if(tmp&n)q.push(tmp);
		tmp<<=1;
	}
	if(k>=q.size()&&k<=n){
		cout<<"YES"<<endl;
		while(q.size()!=k){
			int t=q.top();
			q.pop();
			q.push(t/2);
			q.push(t/2);
		}
		while(!q.empty()){
			cout<<q.top()<<" ";
			q.pop();
		}
	}else
		cout<<"NO"<<endl;
	return 0;
}