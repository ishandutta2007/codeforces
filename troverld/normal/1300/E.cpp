#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lit list<pair<int,int> >::iterator
int n,sum[1001000];
list<pair<int,int> >ls;
bool che(lit i,lit j){
	return (sum[(i->second)]-sum[(i->first)-1])*((j->second)-(j->first)+1)>=(sum[(j->second)]-sum[(j->first)-1])*((i->second)-(i->first)+1);
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&sum[i]),sum[i]+=sum[i-1],ls.push_back(make_pair(i,i));
	for(lit i=ls.begin(),j;i!=ls.end();){
		j=i;j++;
		if(j==ls.end())break;
		if(!che(i,j)){i++;continue;}
		i->second=j->second;
		ls.erase(j);
		if(i==ls.begin())continue;
		j=i;j--;
		while(che(j,i)){
			int tt=(j->first);
			i=ls.erase(j);
			i->first=tt;
			if(i==ls.begin())break;
			j=i;j--;
		}
	}
	for(lit i=ls.begin();i!=ls.end();i++){
		double tt=1.0*(sum[i->second]-sum[(i->first)-1])/((i->second)-(i->first)+1);
		for(int j=(i->first);j<=(i->second);j++)printf("%.9lf\n",tt);
	}
	return 0;
}