#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	long long sum=0,ans=0;
	scanf("%d",&n);
	priority_queue<long long,vector<long long>,greater<long long>>q;
	for(int i=1;i<=n;i++){
		long long x;
		scanf("%lld",&x);
		if(x+sum>=0){
			sum+=x;
			ans++;
			q.push(x);
		}
		else{
			if(q.size()&&x>q.top()){
				sum+=x-q.top();
				q.pop();
				q.push(x);
			}
		}
	}
	cout<<ans;
	return 0;
}