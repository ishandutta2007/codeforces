#include<bits/stdc++.h>
using namespace std;
const int maxn=200007;
int n,q,ans=0,cnt=0,mx=0,ed;
int a[maxn];
vector<int> rec[maxn];
int main(){
	cin>>n>>q;
	for (int i=1;i<=n;++i){
		cin>>a[i];
		rec[a[i]].push_back(i);
	} 
	ed=0;
	for (int i=1;i<=n;++i){
		cnt++;
		mx=max((int)rec[a[i]].size(),mx);
		ed=max(ed,rec[a[i]][rec[a[i]].size()-1]);
		if (ed==i){
			ans+=cnt-mx;
			cnt=0,mx=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}