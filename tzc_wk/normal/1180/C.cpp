#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100005],b[100005],q,mx,num=1;
deque<int> dq;
vector<pair<int,int> > ans;
signed main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)	cin>>a[i],mx=max(mx,a[i]);
	for(int i=1;i<=n;i++)	dq.push_back(a[i]);
	ans.push_back({0,0});
	while(dq.front()!=mx){
		int A=dq.front();dq.pop_front();
		int B=dq.front();dq.pop_front();
		dq.push_front(max(A,B));dq.push_back(min(A,B));
//		cout<<"The numbers of the "<<num<<"-th performance: "<<A<<" and "<<B<<".\n";
		ans.push_back({A,B});
		num++;
	}
	int cnt=1;
	while(!dq.empty()){
		b[cnt++]=dq.front();
		dq.pop_front();
	}
	while(q--){
		int m;cin>>m;
		if(m<num)	cout<<ans[m].first<<" "<<ans[m].second<<endl;
		else{
			int left=m-(num-1);
			int rem=left%(n-1);
			if(rem==0)	rem=n-1;
			cout<<mx<<" "<<b[rem+1]<<endl;
		}
	}
	return 0;
}