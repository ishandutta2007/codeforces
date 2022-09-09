#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200050;
const int M=2*N;
const int inf=1e9+7;
struct Compress{
	vector<int> all;
	void Add(int x){all.pb(x);}
	void Build(){sort(all.begin(),all.end());all.erase(unique(all.begin(),all.end()),all.end());}
	int Find(int x){return lower_bound(all.begin(),all.end(),x)-all.begin()+1;}
	int GetL(int x){return upper_bound(all.begin(),all.end(),x)-all.begin();}
	int GetR(int x){return lower_bound(all.begin(),all.end(),x)-all.begin()+1;}
}CPR;
//int ls[M],rs[M],tsz,root;
int s[N],f[N],t[N];
int l[N],r[N],b[N],ans[N];
set<pair<int,int>> st[M];
void Ins(int i,int j){for(;i<N;i+=i&-i)st[i].insert({t[j],j});}
void Del(int i,int j){for(;i<N;i+=i&-i)st[i].erase({t[j],j});}
pair<int,int> Get(int i,int j){
	pair<int,int> ans={inf,-1};
	for(;i;i-=i&-i){
		auto it=st[i].lower_bound({b[j],0});
		if(it!=st[i].end())ans=min(ans,*it);
	}
	return ans;
}
/*set<pair<int,int>> st[M];
void Ins(int &c,int ss,int se,int qi,int i){
	if(!c)c=++tsz;
	st[c].insert({t[i],i});
	if(ss==se)return;
	int mid=ss+se>>1;
	if(qi<=mid)Ins(ls[c],ss,mid,qi,i);
	else Ins(rs[c],mid+1,se,qi,i);
}
void Del(int c,int ss,int se,int qi,int i){
	st[c].erase({t[i],i});
	if(ss==se)return;
	int mid=ss+se>>1;
	if(qi<=mid)Del(ls[c],ss,mid,qi,i);
	else Del(rs[c],mid+1,se,qi,i);
}
pair<int,int> Get(int c,int ss,int se,int qs,int qe,int i){
	if(qs>qe || ss>qe || qs>se)return {inf,-1};
	if(qs<=ss && qe>=se){
		auto it=st[c].lower_bound({b[i],0});
		if(it==st[c].end())return {inf,-1};
		return *it;
	}
	int mid=ss+se>>1;
	return min(Get(ls[c],ss,mid,qs,qe,i),Get(rs[c],mid+1,se,qs,qe,i));
}*/
vector<int> ins[N],del[N],Qs[N];
int main(){
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=1;i<=n;i++)scanf("%i %i %i",&s[i],&f[i],&t[i]),CPR.Add(s[i]),CPR.Add(f[i]);
	CPR.Build();
	for(int i=1;i<=n;i++)s[i]=CPR.Find(s[i]),f[i]=CPR.Find(f[i]);
	for(int i=1;i<=n;i++)ins[s[i]].pb(i),del[f[i]].pb(i);
	for(int i=1;i<=m;i++){
		scanf("%i %i %i",&l[i],&r[i],&b[i]);
		l[i]=CPR.GetL(l[i]);
		r[i]=CPR.GetR(r[i]);
		Qs[r[i]].pb(i);
		ans[i]=-1;
	}
	for(int i=1;i<=CPR.all.size();i++){
		for(int j:ins[i])Ins(s[j],j);
		for(int j:Qs[i])ans[j]=Get(l[j],j).second;
		for(int j:del[i])Del(s[j],j);
		//for(int j:ins[i])Ins(root,1,N,s[j],j);
		//for(int j:Qs[i])ans[j]=Get(root,1,N,1,l[j],j).second;
		//for(int j:del[i])Del(root,1,N,s[j],j);
	}
	for(int i=1;i<=m;i++)printf("%i ",ans[i]);
	return 0;
}