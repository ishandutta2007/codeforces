#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,tmp,ans=1,cur=2;
signed main(){
	cin>>n;
	tmp=n;
	while(tmp>1){
		if(cur*cur>n){
		 	ans*=tmp;
			break;
		}
		bool flag=false;
		while(tmp%cur==0)	tmp/=cur,flag=true;
		if(flag)		ans*=cur;
		cur++;
	}
	cout<<ans<<endl;
}