#include<bits/stdc++.h>
using namespace std;
int n,m;
struct edge{
	int u,v,w;
};
vector<int>pri,rk;
int getp(int a){
	return a==pri[a]?a:pri[a]=getp(pri[a]);
}
bool calc(int a,int b){
	a=getp(a),b=getp(b);
	if(a==b)return 0;
	if(rk[a]<rk[b])swap(a,b);
	rk[a]+=rk[b];
	pri[b]=a;
	return 1;
}
int main(){
	vector<long long>kk;
	vector<int>cnt;
	scanf("%d%d",&n,&m);
	pri.resize(n);
	rk.resize(n);
	vector<edge>ed(m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&ed[i].v,&ed[i].u,&ed[i].w);
		ed[i].v--,ed[i].u--;
		ed[i].w*=2;
	}
	vector<int>tim(1,0);
	for(int i=0;i<m;i++){
		for(int j=0;j<i+1;j++){
			tim.push_back((ed[i].w+ed[j].w)/2);
		}
	}
	stable_sort(tim.begin(),tim.end());
	tim.resize(unique(tim.begin(),tim.end())-tim.begin());
	for(int x:tim){
		stable_sort(ed.begin(),ed.end(),[&x](const edge &a,const edge &b){int k2=abs(a.w-x);int k1=abs(b.w-x);if(k2!=k1)return k2<k1;return a.w>b.w;});
		for(int i=0;i<n;i++)pri[i]=i,rk[i]=1;
		long long kp=0;
		int ccnt=0;
		for(const auto &e:ed)if(calc(e.v,e.u)){
			kp+=abs(e.w-x);
			ccnt+=x<e.w;
		}
		kk.push_back(kp);
		cnt.push_back(ccnt);
	}
	int p,k,a,b,c;
	scanf("%d%d%d%d%d",&p,&k,&a,&b,&c);
	int x=0;
	long long ans=0;
	for(int q=0;q<k;q++){
		if(q<p)scanf("%d",&x);
		else x=(x*1ll*a+b)%c;
		int y=upper_bound(tim.begin(),tim.end(),2*x)-tim.begin()-1;
		ans^=(kk[y]+(n-1-2*cnt[y])*1ll*(2*x-tim[y]))/2;
	}
	printf("%lld\n",ans);
	return 0;
}