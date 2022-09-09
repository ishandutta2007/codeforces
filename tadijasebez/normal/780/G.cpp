#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N=100050;
struct CMPR{
	vector<int> all;
	void Add(int x){all.pb(x);}
	void Build(){sort(all.begin(),all.end());all.erase(unique(all.begin(),all.end()),all.end());}
	int Find(int x){return lower_bound(all.begin(),all.end(),x)-all.begin()+1;}
	int GetR(int x){return upper_bound(all.begin(),all.end(),x)-all.begin();}
}CPR;
const int M=N*3;
const int mod=1e9+7;
int X[M],Y[M],sz[M],tsz;
struct cmp{bool operator()(int i,int j){return X[i]<X[j]||(X[i]==X[j]&&i<j);}};
set<int,cmp> pts[N];
void Set(int idx){for(int i=Y[idx];i<N;i+=i&-i)pts[i].insert(idx);}
int Get(int y,int l,int r){
	int ans=0;
	for(int i=CPR.GetR(y);i;i-=i&-i){
		X[tsz+1]=l-1;
		X[tsz+2]=r;
		for(auto it=pts[i].upper_bound(tsz+1);it!=pts[i].upper_bound(tsz+2);pts[i].erase(it++)){
			int idx=*it;
			ans+=sz[idx];sz[idx]=0;
			if(ans>=mod)ans-=mod;
		}
	}
	return ans;
}
void Add(int x,int y,int s){
	tsz++;X[tsz]=x;Y[tsz]=y;sz[tsz]=s;
	Set(tsz);
}
int u[N],l[N],r[N],s[N],y[N],ord[N];
int main(){
	int h,w,n;
	scanf("%i %i %i",&h,&w,&n);
	CPR.Add(h+1);
	for(int i=1;i<=n;i++){
		scanf("%i %i %i %i",&u[i],&l[i],&r[i],&s[i]);
		CPR.Add(u[i]);ord[i]=i;
	}
	CPR.Build();
	for(int i=1;i<=n;i++)y[i]=CPR.Find(u[i]);
	sort(ord+1,ord+1+n,[&](int i,int j){return y[i]>y[j];});
	for(int i=1;i<=w;i++){
		tsz++;X[tsz]=i;Y[tsz]=CPR.Find(h+1);sz[tsz]=1;
		Set(tsz);
	}
	for(int j=1,i;i=ord[j],j<=n;j++){
		int tmp=Get(u[i]+s[i],l[i],r[i]);
		if(l[i]==1)Add(r[i]+1,y[i],tmp*2%mod);
		else if(r[i]==w)Add(l[i]-1,y[i],tmp*2%mod);
		else Add(l[i]-1,y[i],tmp),Add(r[i]+1,y[i],tmp);
	}
	int ans=0;
	for(int i=1;i<=tsz;i++){
		ans+=sz[i];
		if(ans>=mod)ans-=mod;
	}
	printf("%i\n",ans);
	return 0;
}