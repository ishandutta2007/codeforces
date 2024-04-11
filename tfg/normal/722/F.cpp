#include <bits/stdc++.h>
#define fr(a,b,c) for(int a=b;a<c;a++)
#define X first
#define Y second
#define pb push_back
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
	if(a<b)swap(a,b);
	while(b){
		ll t=b;b=a%b;a=t;
	}
	return a;
}
ll mul(ll a,ll b,ll m){
	ll q=(long double)a*(long double)b/(long double)m;
	ll r=a*b-q*m;
	return (r+5*m)%m;
}
ll extendedEuclides(ll a,ll b,ll &x,ll &y){
	ll xx=y=0;
	ll yy=x=1;
	while(b){
		ll q=a/b;
		ll t=b;
		b=a%b;
		a=t;
		t=xx;
		xx=x-q*xx;
		x=t;
		t=yy;
		yy=y-q*yy;
		y=t;
	}
	return a;
}
pair<ll,ll> chineseRemainder(ll x,ll y,ll a,ll b){
		if(a==-1||b==-1||x==-1||y==-1)return make_pair(0,-1);
		ll s,t;
		ll d=extendedEuclides(x,y,s,t);
		if(a%d!=b%d)return make_pair(0,-1);
		ll MOD = x*(y/d);
		return make_pair(((a + mul(mul(x, s, MOD), (b - a)/d, MOD)) + MOD) % MOD, MOD);
}
pair<ll,ll> seg[801000];
pair<ll,ll> arr[100100];
void build(int l,int r,int pos){
	if(l==r){
		seg[pos]=arr[l];
		return;
	}
	int m=(l+r)/2;
	build(l,m,2*pos+1);
	build(1+m,r,2*pos+2);
	//cout<<seg[2*pos+1].Y<<","<<seg[2*pos+2].Y<<","<<seg[2*pos+1].X<<","<<seg[2*pos+2].X<<endl;
	seg[pos]=chineseRemainder(seg[2*pos+1].Y,seg[2*pos+2].Y,seg[2*pos+1].X,seg[2*pos+2].X);
	//cout<<seg[pos].X<<","<<seg[pos].Y<<endl;
}
pair<ll,ll> qry(int l,int r,int pos,int ql,int qr){
	if(qr>=r&&ql<=l)return seg[pos];
	if(qr<l||ql>r)return make_pair(0,1);
	pair<ll,ll> pr,pl;
	pl=qry(l,(l+r)/2,2*pos+1,ql,qr);
	pr=qry((l+r)/2+1,r,2*pos+2,ql,qr);
	return chineseRemainder(pl.Y,pr.Y,pl.X,pr.X);
}
vector<pair<ll,ll> > arrs[100100];
int ans[100100];
int kss[100100];
int solve(int k){
	build(0,k-1,0);
	int l=0,r=0,mxm=1;
	while(l<k&&r<k){
		if(qry(0,k-1,0,l,r).Y!=-1)mxm=max(mxm,r-l+1);
		if(r==k-1)l++;
		else if(qry(0,k-1,0,l,r).Y!=-1)r++;
		else l++;
		if(qry(0,k-1,0,l,r).Y!=-1)mxm=max(mxm,r-l+1);
	}r=k-1;
	while(l<k){
		if(qry(0,k-1,0,l,r).Y!=-1)mxm=max(mxm,r-l+1);
		l++;
	}
	return mxm;
}
int main(){
	int n,m;
	cin>>n>>m;
	fr(i,0,n){
		cin>>kss[i];
		fr(j,0,kss[i]){
			int a;
			cin>>a;
			arrs[a].pb(make_pair(j,i));
		}
	}
	int i=1;
	while(i<=m){
		if(arrs[i].size()==0){cout<<0<<endl;i++;continue;}
		pair<int,int> last=arrs[i][0];
		int j=0,h=1;
		arr[0]=make_pair(arrs[i][0].X,kss[arrs[i][0].Y]);		
		while(j<arrs[i].size()){
			j++;
			if(j==arrs[i].size()||arrs[i][j].Y!=arrs[i][j-1].Y+1){
				ans[i]=max(ans[i],solve(h));
				h=0;
				if(j!=arrs[i].size())arr[h++]=make_pair(arrs[i][j].X,kss[arrs[i][j].Y]);
			}else{
				arr[h++]=make_pair(arrs[i][j].X,kss[arrs[i][j].Y]);
			}
		}
		cout<<ans[i]<<endl;
		i++;		
	}

}