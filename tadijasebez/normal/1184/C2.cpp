#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=300050;
const int M=4*N;
int ls[M],rs[M],root,tsz,lzy[M],mx[M];
void Add(int &c,int ss,int se,int qs,int qe,int f){
	if(qs>qe || qs>se || ss>qe)return;
	if(!c)c=++tsz;
	if(qs<=ss && qe>=se){lzy[c]+=f;mx[c]+=f;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mx[c]=max(mx[ls[c]],mx[rs[c]])+lzy[c];
}
struct Compress{
	vector<int> all;
	void Add(int x){all.pb(x);}
	void Build(){sort(all.begin(),all.end());all.erase(unique(all.begin(),all.end()),all.end());}
	int GetL(int x){return lower_bound(all.begin(),all.end(),x)-all.begin()+1;}
	int GetR(int x){return upper_bound(all.begin(),all.end(),x)-all.begin();}
}CPR;
int x[N],y[N];
int main(){
	int n,r;
	scanf("%i %i",&n,&r);
	for(int i=1;i<=n;i++)scanf("%i %i",&x[i],&y[i]),tie(x[i],y[i])=mp(x[i]+y[i],x[i]-y[i]);
	for(int i=1;i<=n;i++)CPR.Add(y[i]),CPR.Add(y[i]-2*r);
	CPR.Build();
	int sz=CPR.all.size();
	vector<pair<int,pair<int,int>>> events;
	for(int i=1;i<=n;i++){
		events.pb({x[i]-r,{0,i}});
		events.pb({x[i]+r,{1,i}});
	}
	sort(events.begin(),events.end());
	int ans=0;
	for(auto e:events){
		int i=e.second.second;
		if(e.second.first==0){
			Add(root,1,sz,CPR.GetL(y[i]-2*r),CPR.GetR(y[i]),1);
		}else Add(root,1,sz,CPR.GetL(y[i]-2*r),CPR.GetR(y[i]),-1);
		ans=max(ans,mx[root]);
	}
	printf("%i\n",ans);
	return 0;
}