#include"bits/stdc++.h"
#define mp make_pair
using namespace std;

typedef long long LL;
const int N=100005;
const LL inf=(LL)1e15;
map<LL,int> f;
int n,k,a[N];
LL s[N],ans;

int main(){
	cin>>n>>k;
	f.insert(mp(0ll,1));
	map<LL,int>::iterator d;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		if(k>1||k<-1){
			for(LL p=1;p<=inf;p*=k){
				d=f.find(s[i]-p);
				if(d!=f.end())ans+=d->second;
			}
		}else if(k==1){
			d=f.find(s[i]-1);
			if(d!=f.end())ans+=d->second;
		}else if(k==-1){
			d=f.find(s[i]-1);
			if(d!=f.end())ans+=d->second;
			d=f.find(s[i]+1);
			if(d!=f.end())ans+=d->second;
		}
		d=f.find(s[i]);
		if(d!=f.end())d->second++;
		else f.insert(mp(s[i],1));
	}
	cout<<ans<<endl;
	return 0;
}