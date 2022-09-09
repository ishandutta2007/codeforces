#include <bits/stdc++.h>
using namespace std;
void ckmx(int &x,int y){x=max(x,y);}
int main(){
	int n,q;
	scanf("%i %i",&n,&q);
	deque<int> dq;
	int mx=0;
	for(int i=1,x;i<=n;i++)scanf("%i",&x),dq.push_back(x),ckmx(mx,x);
	vector<pair<int,int>> ans;
	while(1){
		int a=dq.front();dq.pop_front();
		int b=dq.front();dq.pop_front();
		if(a==mx){
			dq.push_front(b);
			break;
		}
		ans.push_back({a,b});
		if(a<b)swap(a,b);
		dq.push_back(b);
		dq.push_front(a);
	}
	vector<int> seq(dq.begin(),dq.end());
	while(q--){
		long long k;
		scanf("%lld",&k);
		k--;
		if(k<ans.size())printf("%i %i\n",ans[k].first,ans[k].second);
		else{
			k-=ans.size();
			k%=seq.size();
			printf("%i %i\n",mx,seq[k]);
		}
	}
	return 0;
}