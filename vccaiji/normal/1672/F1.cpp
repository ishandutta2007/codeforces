#include<bits/stdc++.h>
using namespace std;
int _,n,a[210000];
int cnt[210000];
stack<int> x[210000];
pair<int,int> o[210000];
int jj[210000];
int b[210000];
int main(){
	cin>>_;
	while(_--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cnt[a[i]]++;
		for(int i=1;i<=n;i++)o[i]=make_pair(cnt[i],i),cnt[i]=0;
		o[0]=make_pair(0,0);
		sort(o+1,o+n+1);
		for(int i=1;i<=n;i++)while(x[i].size())x[i].pop();
		for(int i=1;i<=n;i++)x[a[i]].push(i);
		for(int i=n;i>=1;i--){
			for(int j=o[i].first-o[i-1].first;j>=1;j--){
				for(int k=n;k>=i;k--){
					jj[k]=x[o[k].second].top();
					x[o[k].second].pop();
				}
				for(int k=n;k>i;k--)b[jj[k]]=jj[k-1];
				b[jj[i]]=jj[n];
			}
		}
		for(int i=1;i<=n;i++)cout<<a[b[i]]<<' ';
		cout<<endl;
	}
	return 0;
}