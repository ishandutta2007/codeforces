#include<bits/stdc++.h>
using namespace std;
 
const int maxn=3007;
const int w=30;
 
int n,m,q,d[maxn][maxn>>4],o[maxn][maxn>>4],sm[maxn]; 
set<pair<int,int> > s;
set<pair<int,int> > valid;
vector<int> val[maxn];
int gd(int n){
	int ans=0;
	while (n){
		ans+=n&1;
		n>>=1;
	}
	return ans;
}
 
int get_ans(int l,int r){
	int ans=((1<<r-l+1)-1)<<l;
	return ans;
}
 
int get_sum(int u){
	int ans=0;
	for (int i=0;i<=m/w;++i){
		ans+=o[u][i];
	}
	return ans;
}
 
bool ck(int i,int j){
//	cout<<i<<" "<<j<<endl;
	for (int k=0;k<=m/w;++k){
		if ((d[i][k]&d[j][k])!=d[i][k]) return 1;
	}
	return 0;
}
 
int get_dig(int i,int j){
	for (int k=0;k<=m/w;++k){
		if ((d[i][k]&d[j][k])!=d[i][k]){
			int t1=d[i][k],t2=d[j][k];
			for (int u=0;u<w;++u){
				if ((t1&1)&&!(t2&1)){
					return u+k*w+1;
				}
				t1>>=1,t2>>=1;
			}
		}
	}
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;++i){
		s.insert({0,i});
	}
	while(q--){
		int i,l,r;
		scanf("%d%d%d",&i,&l,&r);
		l--,r--;
		int lb=l/w,rb=r/w;
		if (lb<rb){
			d[i][lb]=d[i][lb]^get_ans(l%w,w-1);
			o[i][lb]=gd(d[i][lb]);
			d[i][rb]=d[i][rb]^get_ans(0,r%w);
			o[i][rb]=gd(d[i][rb]);
			for (int j=lb+1;j<rb;++j){
				d[i][j]=d[i][j]^get_ans(0,w-1);
				o[i][j]=w-o[i][j];
			}
		}
		else{
			d[i][lb]=d[i][lb]^get_ans(l%w,r%w);
			o[i][lb]=gd(d[i][lb]);
		}
		auto p=s.find({sm[i],i});
		int u=prev(p)->second,v=next(p)->second;
		if (u&&v&&ck(u,v)){
			val[u].push_back(v);
			val[v].push_back(u);
			valid.insert({u,v});
			valid.insert({v,u});
		}
		s.erase(p);
		for (int j=0;j<val[i].size();++j){
			valid.erase({i,val[i][j]});
			valid.erase({val[i][j],i});
		}
		val[i].clear();
		sm[i]=get_sum(i);
		s.insert({sm[i],i});
		p=s.find({sm[i],i});
		u=prev(p)->second,v=next(p)->second;
		if (u&&ck(u,i)){
			val[i].push_back(u);
			val[u].push_back(i);
			valid.insert({i,u});
			valid.insert({u,i}); 
		}
		if (v&&ck(i,v)){
			val[i].push_back(v);
			val[v].push_back(i);
			valid.insert({i,v});
			valid.insert({v,i});
		}
		if (valid.empty()){
			cout<<-1<<endl;
		}
		else{
			auto p=valid.begin();
			int u=next(p)->first, v=next(p)->second;
			int au=get_dig(u,v),av=get_dig(v,u);
			if (u>v) swap(u,v);
			if (au>av) swap(au,av);
//			cout<<u<<" "<<au<<" "<<v<<" "<<av<<endl;
			printf("%d %d %d %d\n",u,au,v,av);
		}
	}
	return 0;
}