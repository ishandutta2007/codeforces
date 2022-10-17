#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353
#define abs llabs
ll i,j,k,n,m,t,sb,it;
ll f[200500][2],mx,tmp;
ll lx,ly,rx,ry;

map<ll,set<pair<ll,ll> > >mp;

int main() {
	memset(f,1,sizeof(f));
	f[0][0]=f[0][1]=0;
	cin.tie(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>j>>k;
		mp[max(j,k)].insert({j,-k});
	}
	for(auto [i,s]:mp){
		it++;
		auto [lx1,ly1]=*s.begin();
		auto it2=s.end();
		it2--;
		auto [rx1,ry1]=*it2;
		ly1=-ly1;ry1=-ry1;
		//printf("nmsl%d %d %d %d\n",lx1,ly1,rx1,ry1);
		//
		tmp=abs(lx-i)+abs(i-rx1)+abs(ly-ry1)+abs(ly1-ry1)+abs(lx1-rx1);
		f[it][0]=min(f[it][0],f[it-1][0]+tmp);
		
		tmp=abs(ly-i)+abs(lx-rx1)+abs(i-ry1)+abs(ly1-ry1)+abs(lx1-rx1);
		f[it][0]=min(f[it][0],f[it-1][0]+tmp);
		
		tmp=abs(rx-i)+abs(i-rx1)+abs(ry-ry1)+abs(ly1-ry1)+abs(lx1-rx1);
		f[it][0]=min(f[it][0],f[it-1][1]+tmp);
		
		tmp=abs(ry-i)+abs(rx-rx1)+abs(i-ry1)+abs(ly1-ry1)+abs(lx1-rx1);
		f[it][0]=min(f[it][0],f[it-1][1]+tmp);
		
		//
		tmp=abs(lx-i)+abs(i-lx1)+abs(ly-ly1)+abs(ly1-ry1)+abs(lx1-rx1);
		f[it][1]=min(f[it][1],f[it-1][0]+tmp);
		
		tmp=abs(ly-i)+abs(lx-lx1)+abs(i-ly1)+abs(ly1-ry1)+abs(lx1-rx1);
		f[it][1]=min(f[it][1],f[it-1][0]+tmp);
		
		tmp=abs(rx-i)+abs(i-lx1)+abs(ry-ly1)+abs(ly1-ry1)+abs(lx1-rx1);
		f[it][1]=min(f[it][1],f[it-1][1]+tmp);
		
		tmp=abs(ry-i)+abs(rx-lx1)+abs(i-ly1)+abs(ly1-ry1)+abs(lx1-rx1);
		f[it][1]=min(f[it][1],f[it-1][1]+tmp);
		
		lx=lx1;rx=rx1;
		ly=ly1;ry=ry1;
	}
	cout<<min(f[it][0],f[it][1]);
}