#include<bits/stdc++.h>
using namespace std;
int n,x,y,l,r;
struct node { 
	int l,r;
	bool operator < (const node &a) const { 
		return l < a.l;
	} 
};
node seq[100010];
struct st { 
	int l,r;
	bool operator < (const st &a) const { 
		if(r==a.r) return l < a.l;
		return r < a.r;
	} 
};
multiset<st>sth;
int res=0;
const int mod=1000000007;
int main() { 
	cin>>n>>x>>y;
	res=(x-y)/y;
	for(int i=1;i<=n;++i) { 
		scanf("%d%d",&seq[i].l,&seq[i].r);
	} 
	sort(seq+1,seq+n+1);
	for(int i=1;i<=n;++i) { 
		multiset<st>::iterator nw=sth.lower_bound((st){0,seq[i].l});
		if(nw!=sth.begin()) nw--;
		if(sth.empty()||(*nw).r>=seq[i].l||(*nw).r<seq[i].l-1-res) sth.insert((st){seq[i].l,seq[i].r});
		else { 
			st nk=*nw;
			sth.erase(nw);
			sth.insert((st){nk.l,seq[i].r});
		} 
	} 
	long long ans=0,nval=0;
	while(!sth.empty()) { 
		nval=0;
		multiset<st>::iterator nw=sth.begin();
		st nk=*nw;sth.erase(nw);
		nval=1ll*(nk.r-nk.l)*y+x;
		nval%=mod;
		ans+=nval;
	} 
	cout<<ans%mod;
	return 0;
}