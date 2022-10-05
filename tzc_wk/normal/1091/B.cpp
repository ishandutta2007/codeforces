#include <bits/stdc++.h>
using namespace std;
int a[1001],b[1001],x[1001],y[1001];
typedef pair<int,int> pii;
map<pii,vector<pii> > Hash;
bool same(pii p1,pii p2){
	return (p1.first==p2.first&&p1.second==p2.second);
}
int n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d %d",&a[i],&b[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			Hash[pii(x[j]+a[i],y[j]+b[i])].push_back(pii(i,j));
		}
	}
	for(map<pii,vector<pii> >::iterator it=Hash.begin();it!=Hash.end();it++){
		vector<pii> k=it->second;
		bool mark[1001];
		if(k.size()<n)	continue;
		cout<<it->first.first<<" "<<it->first.second<<endl;
	}
}