#include<bits/stdc++.h>
using namespace std;
int n,m,k,x[1005],y[1005];
bool check(int mi){
	int cf[3005][3005];
	memset(cf,0,sizeof cf);
	vector<int>v;
	vector<int>u;
	u.push_back(n);
	u.push_back(1);
	v.push_back(m);
	v.push_back(1);
	for(int i=1;i<=k;i++){
		int xx=max(1,x[i]-mi);
		int xxx=min(n,x[i]+mi);
		int yy=max(1,y[i]-mi);
		int yyy=min(m,y[i]+mi);
		if(xx!=1)u.push_back(xx-1);
		u.push_back(xx);
		u.push_back(xxx);
		u.push_back(xxx+1);
		if(yy!=1)v.push_back(yy-1);
		v.push_back(yy);
		v.push_back(yyy);
		v.push_back(yyy+1);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	sort(u.begin(),u.end());
	u.erase(unique(u.begin(),u.end()),u.end());
	for(int i=1;i<=k;i++){
		int xx=max(1,x[i]-mi);
		int xxx=min(n,x[i]+mi);
		int yy=max(1,y[i]-mi);
		int yyy=min(m,y[i]+mi);
		xx=lower_bound(u.begin(),u.end(),xx)-u.begin()+1;
		xxx=lower_bound(u.begin(),u.end(),xxx)-u.begin()+1;
		yy=lower_bound(v.begin(),v.end(),yy)-v.begin()+1;
		yyy=lower_bound(v.begin(),v.end(),yyy)-v.begin()+1;
		cf[xx][yy]+=1;
		cf[xx][yyy+1]-=1;
		cf[xxx+1][yy]-=1;
		cf[xxx+1][yyy+1]+=1;
	}
	int mx=lower_bound(u.begin(),u.end(),n)-u.begin()+1,
	my=lower_bound(v.begin(),v.end(),m)-v.begin()+1;
	for(int i=1;i<=mx;i++){
		for(int o=1;o<=my;o++){
			cf[i][o]=cf[i-1][o]+cf[i][o-1]-cf[i-1][o-1]+cf[i][o];
		}
	}
	int anx1=0,anx2=0,any1=0,any2=0;
	for(int i=1;i<=mx;i++){
		for(int o=1;o<=my;o++){
			if(!cf[i][o]){
				anx1=i;
				break;
			}
		}
		if(anx1)break;
	}
	if(!anx1)return 1;
	for(int i=1;i<=my;i++){
		for(int o=1;o<=mx;o++){
			if(!cf[o][i]){
				any1=i;
				break;
			}
		}
		if(any1)break;
	}
	for(int i=mx;i>=1;i--){
		for(int o=my;o>=1;o--){
			if(!cf[i][o]){
				anx2=i;
				break;
			}
		}
		if(anx2)break;
	}
	for(int i=my;i>=1;i--){
		for(int o=mx;o>=1;o--){
			if(!cf[o][i]){
				any2=i;
				break;
			}
		}
		if(any2)break;
	}
	anx1=u[anx1-1];
	anx2=u[anx2-1];
	any1=v[any1-1];
	any2=v[any2-1];
	return anx2-anx1<=mi*2&&any2-any1<=mi*2;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	int l=0,r=1e9,mid,ans;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}
		else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}