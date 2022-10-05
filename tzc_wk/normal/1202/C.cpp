#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD			1000000007
#define FOR(i,l,r)	for(int i=l;i<=r;i++)
#define REP(i,n)	for(int i=1;i<=n;i++)
#define REP0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
#define int long long
int T;
string s;
int sum[200005][2];
struct seg{
	struct node{
		int l,r,mn,mx,lz;
	} s[800005];
	inline void build(int k,int l,int r,int type){
		s[k].l=l;s[k].r=r;
		if(l==r){
			s[k].mn=s[k].mx=sum[l][type];
			return;
		}
		int mid=(l+r)>>1;
		build(k<<1,l,mid,type);
		build(k<<1|1,mid+1,r,type);
		s[k].mn=min(s[k<<1].mn,s[k<<1|1].mn);
		s[k].mx=max(s[k<<1].mx,s[k<<1|1].mx);
	}
	inline void pushdown(int k){
		s[k<<1].mx+=s[k].lz;
		s[k<<1].mn+=s[k].lz;
		s[k<<1].lz+=s[k].lz;
		s[k<<1|1].mx+=s[k].lz;
		s[k<<1|1].mn+=s[k].lz;
		s[k<<1|1].lz+=s[k].lz;
	}
	inline void change(int k,int l,int r,int val){
		if(l>r)	return;
		if(l<=s[k].l&&s[k].r<=r){
			s[k].lz+=val;
			s[k].mx+=val;
			s[k].mn+=val;
			return;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		change(k<<1,l,r,val);
		else if(l>mid)	change(k<<1|1,l,r,val);
		else			change(k<<1,l,mid,val),change(k<<1|1,mid+1,r,val);
		s[k].mn=min(s[k<<1].mn,s[k<<1|1].mn);
		s[k].mx=max(s[k<<1].mx,s[k<<1|1].mx);
	}
	inline int query_mn(){
		return s[1].mn;
	}
	inline int query_mx(){
		return s[1].mx;
	}
} st[2];
int area(){
	return (max(st[0].query_mx(),0ll)-min(st[0].query_mn(),0ll)+1)*(max(st[1].query_mx(),0ll)-min(st[1].query_mn(),0ll)+1);
}
signed main(){
	cin>>T;
	while(T--){
		cin>>s;
		s=" "+s;
		for(int i=0;i<=s.size();i++)	sum[i][0]=sum[i][1]=sum[i][2]=sum[i][3]=0;
		for(int i=1;i<s.size();i++){
			sum[i][0]=sum[i-1][0];
			sum[i][1]=sum[i-1][1];
			if(s[i]=='W')	sum[i][0]++;
			if(s[i]=='A')	sum[i][1]--;
			if(s[i]=='S')	sum[i][0]--;
			if(s[i]=='D')	sum[i][1]++;
		}
		st[0].build(1,1,s.size()-1,0);
		st[1].build(1,1,s.size()-1,1);
		int ans=area();
//		cout<<area()<<endl;
		for(int i=0;i<=s.size();i++){
			st[0].change(1,i,s.size()-1,-1);
			ans=min(ans,(max(st[0].query_mx(),0ll)-min(st[0].query_mn(),min(sum[i-1][0]-1,0ll))+1)*(max(st[1].query_mx(),0ll)-min(st[1].query_mn(),0ll)+1));
			st[0].change(1,i,s.size()-1,1);
			st[0].change(1,i,s.size()-1,1);
			ans=min(ans,(max(st[0].query_mx(),max(sum[i-1][0]+1,0ll))-min(st[0].query_mn(),0ll)+1)*(max(st[1].query_mx(),0ll)-min(st[1].query_mn(),0ll)+1));
			st[0].change(1,i,s.size()-1,-1);
			st[1].change(1,i,s.size()-1,-1);
			ans=min(ans,(max(st[0].query_mx(),0ll)-min(st[0].query_mn(),0ll)+1)*(max(st[1].query_mx(),0ll)-min(st[1].query_mn(),min(sum[i-1][1]-1,0ll))+1));
			st[1].change(1,i,s.size()-1,1);
			st[1].change(1,i,s.size()-1,1);
			ans=min(ans,(max(st[0].query_mx(),0ll)-min(st[0].query_mn(),0ll)+1)*(max(st[1].query_mx(),max(sum[i-1][1]+1,0ll))-min(st[1].query_mn(),0ll)+1));
			st[1].change(1,i,s.size()-1,-1);
		}
		cout<<ans<<endl;
	}
	return 0;
}//