#include<cstdio>
#include<iostream>
#include<set>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<long long,long long> P;
typedef pair<P,int> PP;

const long long inf=3e18;

PP pps[400400];

long long isl_l[200200],isl_r[200200];
long long ls[200200],rs[200200];
long long a[200200];
int N,M;

multiset<P> se;

int ans[200200];

int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++) cin>>isl_l[i]>>isl_r[i];
	for(int i=0;i<M;i++) cin>>a[i];
	for(int i=0;i+1<N;i++){
		ls[i]=isl_l[i+1]-isl_r[i];
		rs[i]=isl_r[i+1]-isl_l[i];
		P p=P(ls[i],rs[i]);
		PP pp=PP(p,i);
		pps[i]=pp;
	}
	for(int i=0;i<M;i++){
		P p=P(a[i],inf);
		PP pp=PP(p,i);
		pps[i+N-1]=pp;
	}
	sort(pps,pps+N+M-1);
	for(int i=0;i<N+M-1;i++){
		PP pp=pps[i];
		P p=pp.first;
		if(p.second==inf){
			P tmp=P(p.first,-inf);
			multiset<P>::iterator it=se.lower_bound(tmp);
			if(it!=se.end()){
				P isl=(*it);
				se.erase(it);
				ans[isl.second]=pp.second;
			}
		}else{
			P tmp=P(p.second,pp.second);
			se.insert(tmp);
		}
	}
	if(se.size()>0){
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	for(int i=0;i+1<N;i++){
		cout<<ans[i]+1;
		if(i+1+1==N) cout<<"\n";
		else cout<<" ";
	}
	return 0;
}