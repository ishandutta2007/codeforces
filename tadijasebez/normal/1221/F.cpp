#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
struct CPR{
	vector<int> all;
	void add(int x){all.pb(x);}
	void Build(){sort(all.begin(),all.end());all.erase(unique(all.begin(),all.end()),all.end());}
	int Find(int x){return lower_bound(all.begin(),all.end(),x)-all.begin()+1;}
}CPR;
const int N=1000050;
const int M=2*N;
int ls[M],rs[M],tsz,root;
pair<ll,int> mx[M];
ll lzy[M];
pair<ll,int> operator +(pair<ll,int> a,ll b){a.first+=b;return a;}
void Build(int &c,int ss,int se){
	c=++tsz;mx[c]={0,ss};
	if(ss==se)return;
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
}
void Add(int c,int ss,int se,int qs,int qe,int f){
	if(qs>qe || qs>se || ss>qe)return;
	if(qs<=ss && qe>=se){lzy[c]+=f;mx[c].first+=f;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mx[c]=max(mx[ls[c]],mx[rs[c]])+lzy[c];
}
pair<ll,int> Get(int c,int ss,int se,int qs,int qe){
	//printf("%i %i %i\n",c,ss,se);
	if(qs<=ss && qe>=se)return mx[c];
	int mid=ss+se>>1;
	if(qe<=mid)return Get(ls[c],ss,mid,qs,qe)+lzy[c];
	if(qs>mid)return Get(rs[c],mid+1,se,qs,qe)+lzy[c];
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe))+lzy[c];
}
vector<pair<int,pair<int,int>>> pts;
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1,x,y,c;i<=n;i++){
		scanf("%i %i %i",&x,&y,&c);
		int l=min(x,y),r=max(x,y);
		CPR.add(l);
		CPR.add(r);
		pts.pb({r,{l,c}});
	}
	CPR.Build();
	sort(pts.begin(),pts.end());
	int m=CPR.all.size();
	Build(root,1,m);
	for(int i=1;i<=m;i++)Add(root,1,m,i,i,CPR.all[i-1]);
	ll ans=0;
	int L=1e9+7,R=1e9+7;
	for(int i=0;i<pts.size();i++){
		auto p=pts[i];
		//printf("(%i %i) %i\n",p.first,p.second.first,p.second.second);
		Add(root,1,m,1,CPR.Find(p.second.first),p.second.second);
		//printf("%i:D\n",CPR.Find(p.first));
		if(i+1==pts.size() || p.first!=pts[i+1].first){
			pair<ll,int> A=Get(root,1,m,1,CPR.Find(p.first));
			A.first-=p.first;
			if(ans<A.first){
				ans=A.first;
				L=CPR.all[A.second-1];
				R=p.first;
			}
			//ans=max(ans,Get(root,1,m,1,CPR.Find(p.first))-p.first);
			//printf("%lld\n",Get(root,1,m,1,CPR.Find(p.first))-p.first);
		}
	}
	printf("%lld\n",ans);
	printf("%i %i %i %i\n",L,L,R,R);
	return 0;
}