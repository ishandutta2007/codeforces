#include<bits/stdc++.h>
using namespace std;

const int maxn=300007;
int n,q,a[maxn];
pair<int,int> vec[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>q;
	while(q--){
		cin>>n;
		for (int i=1;i<=n;++i){
			cin>>a[i];
			vec[i]={n+1,-1};
		}
		for (int i=1;i<=n;++i){
			vec[a[i]].first=min(i,vec[a[i]].first);
			vec[a[i]].second=max(i,vec[a[i]].second);
		}
		int i=1,t=1,ct=1,ans=0;
		while (vec[i].second==-1) i++;
		while (i<=n){
			int l=i;
			i++;
			while (i<=n&&vec[i].second==-1) i++;
			t++;
			if (i>n) break;
			if (vec[i].first>vec[l].second){
				ct++;
			}
			else{
				ans=max(ans,ct);
				ct=1;
			}
		}
		ans=max(ans,ct);
		cout<<t-ans-1<<endl;
	} 
	return 0;
}