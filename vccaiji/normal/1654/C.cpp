#include<bits/stdc++.h>
using namespace std;
int _,n;
multiset<int> mp;
queue<long long> q;
int main(){
	scanf("%d",&_);
	while(_--){
		long long sum=0;
		mp.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int a;
			scanf("%d",&a);
			mp.insert(a);
			sum+=a;
		}
		while(q.size()) q.pop();
		q.push(sum);
		bool r=1;
		int num=n;
		while(q.size()){
			if(q.size()>num){
				r=0;
				break;
			}
			long long u=q.front();
			q.pop();
			auto it=mp.find(u);
			if(it!=mp.end()){
				mp.erase(it);
				num--;
			}
			else{
				if(u==1){
					r=0;
					break;
				}
				q.push(u/2);
				q.push((u+1)/2);
			}
		}
		if(num) r=0;
		if(r)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}