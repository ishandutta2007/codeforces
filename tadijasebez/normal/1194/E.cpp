#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=5050;
const int M=2*N;
int xl[N],xr[N],yl[N],yr[N];
int sum[M];
void Set(int i,int f){for(;i<M;i+=i&-i)sum[i]+=f;}
int Get(int i){int ans=0;for(;i;i-=i&-i)ans+=sum[i];return ans;}
vector<int> Us[M];
int main(){
	int n;
	scanf("%i",&n);
	vector<int> hor,ver;
	for(int i=1;i<=n;i++){
		scanf("%i %i %i %i",&xl[i],&yl[i],&xr[i],&yr[i]);
		if(xl[i]>xr[i])swap(xl[i],xr[i]);
		if(yl[i]>yr[i])swap(yl[i],yr[i]);
		xl[i]+=5001;xr[i]+=5001;yl[i]+=5001;yr[i]+=5001;
		if(xl[i]==xr[i])ver.pb(i);
		else hor.pb(i),Us[xr[i]].pb(i);
	}
	sort(ver.begin(),ver.end(),[&](int i,int j){return xl[i]<xl[j];});
	sort(hor.begin(),hor.end(),[&](int i,int j){return xr[i]<xr[j];});
	ll ans=0;
	for(int i=0;i+1<ver.size();i++){
		for(int j=1;j<M;j++)sum[j]=0;
		for(int j:hor)if(xl[j]<=xl[ver[i]] && xr[j]>=xl[ver[i+1]])Set(yl[j],1);
		for(int j=i+1,k=0;j<ver.size();j++){
			while(k<hor.size() && xr[hor[k]]<xl[ver[j]]){
				if(xl[hor[k]]<=xl[ver[i]] && xr[hor[k]]>=xl[ver[i+1]])Set(yl[hor[k]],-1);
				k++;
			}
			int L=max(yl[ver[i]],yl[ver[j]]);
			int R=min(yr[ver[i]],yr[ver[j]]);
			if(L<=R){
				int cnt=Get(R)-Get(L-1);
				ans+=(ll)cnt*(cnt-1)/2;
				//printf("%i %i %i %i %i\n",ver[i],ver[j],L,R,cnt);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}