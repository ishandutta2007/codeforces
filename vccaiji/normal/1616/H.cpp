#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,x;
int a[460000];
int t[410000];
int solve(int i,int type,vector<int> &v,vector<int> &vv){
	if(v.size()==0&&(vv.size()==0||type==1))return 1;
	if(i==0){
		if(type==1)return t[v.size()];
		else return t[v.size()+vv.size()];
	}
	if((x>>(i-1))&1){
		if(type==1){
			vector<int> v1,v2;
		    for(int j : v){
			    if((j>>(i-1))&1)v1.push_back(j);
			    else v2.push_back(j);
		    }
		    return solve(i-1,2,v1,v2);
		}
		else{
			vector<int> v1,v2,vv1,vv2;
	        for(int j : v){
		    	if((j>>(i-1))&1)v1.push_back(j);
				else v2.push_back(j);
			}
			for(int j : vv){
				if((j>>(i-1))&1)vv1.push_back(j);
				else vv2.push_back(j);
			}
			return (1ll*solve(i-1,2,v1,vv2)*solve(i-1,2,v2,vv1))%p;
		}
	}
	if(type==1){
		vector<int> v1,v2;
		for(int j : v){
			if((j>>(i-1))&1)v1.push_back(j);
			else v2.push_back(j);
		}
		return (0ll+solve(i-1,1,v1,v1)+solve(i-1,1,v2,v2)+p-1)%p;
	}
	vector<int> v1,v2,vv1,vv2;
	for(int j : v){
		if((j>>(i-1))&1)v1.push_back(j);
		else v2.push_back(j);
	}
	for(int j : vv){
		if((j>>(i-1))&1)vv1.push_back(j);
		else vv2.push_back(j);
	}
	return (0ll+solve(i-1,2,v1,vv1)+solve(i-1,2,v2,vv2)+p-1+1ll*((t[v1.size()]+p-1)%p)*((t[v2.size()]+p-1)%p)+1ll*((t[vv1.size()]+p-1)%p)*((t[vv2.size()]+p-1)%p))%p;
}
int main(){
	cin>>n>>x;
	for(int i=1;i<=n;i++)cin>>a[i];
	t[0]=1;
	for(int i=1;i<=n;i++)t[i]=(t[i-1]<<1)%p;
	vector<int> s;
	for(int i=1;i<=n;i++)s.push_back(a[i]);
	cout<<(solve(30,1,s,s)+p-1)%p;
	return 0;
}