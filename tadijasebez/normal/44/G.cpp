#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>

const int N=100050;
const int L=17;

int xl[N],xr[N],yl[N],yr[N],z[N],x[N],y[N],ans[N],ord[N],was[N];
struct Compress{
	vector<int> all;
	Compress(){}
	void Build(){
		sort(all.begin(),all.end());
		all.erase(unique(all.begin(),all.end()),all.end());
	}
	void Add(int x){all.pb(x);}
	int Find(int x){return lower_bound(all.begin(),all.end(),x)-all.begin()+1;}
	int GetL(int x){return Find(x);}
	int GetR(int x){return upper_bound(all.begin(),all.end(),x)-all.begin();}
	int size(){return all.size();}
}CX,CY;

int best;

namespace Seg1D{
	const int M=17*2*N;
	const int H=20000000;
	int ls[M],rs[M],fir[M],tsz;
	int val[H],go[H],lsz;
	void Add(int&c,int ss,int se,int qi,int idx){
		if(!c)c=++tsz;
		go[++lsz]=fir[c];
		val[lsz]=idx;
		fir[c]=lsz;
		if(ss==se)return;
		int mid=ss+se>>1;
		if(qi<=mid)Add(ls[c],ss,mid,qi,idx);
		else Add(rs[c],mid+1,se,qi,idx);
	}
	void Get(int c,int ss,int se,int qs,int qe){
		if(qs>qe||qs>se||ss>qe||!c)return;
		if(qs<=ss&&qe>=se){
			while(fir[c]&&was[val[fir[c]]])fir[c]=go[fir[c]];
			if(fir[c]&&(best==0||best>val[fir[c]]))best=val[fir[c]];
			return;
		}
		int mid=ss+se>>1;
		Get(ls[c],ss,mid,qs,qe);
		Get(rs[c],mid+1,se,qs,qe);
	}
}

namespace Seg2D{
	const int M=2*N;
	int tsz,ls[M],rs[M],rt[M];
	Compress cps[M];
	void Reserve(int&c,int ss,int se,int qi,int y){
		if(!c)c=++tsz;
		cps[c].Add(y);
		if(ss==se)return;
		int mid=ss+se>>1;
		if(qi<=mid)Reserve(ls[c],ss,mid,qi,y);
		else Reserve(rs[c],mid+1,se,qi,y);
	}
	void Build(){
		for(int i=1;i<=tsz;i++){
			cps[i].Build();
		}
	}
	void Add(int&c,int ss,int se,int qi,int y,int idx){
		if(!c)c=++tsz;
		Seg1D::Add(rt[c],1,cps[c].size(),cps[c].Find(y),idx);
		if(ss==se)return;
		int mid=ss+se>>1;
		if(qi<=mid)Add(ls[c],ss,mid,qi,y,idx);
		else Add(rs[c],mid+1,se,qi,y,idx);
	}
	void Get(int c,int ss,int se,int qs,int qe,int yl,int yr){
		if(qs>qe||qs>se||ss>qe||!c)return;
		if(qs<=ss&&qe>=se){
			Seg1D::Get(rt[c],1,cps[c].size(),cps[c].GetL(yl),cps[c].GetR(yr));
			return;
		}
		int mid=ss+se>>1;
		Get(ls[c],ss,mid,qs,qe,yl,yr);
		Get(rs[c],mid+1,se,qs,qe,yl,yr);
	}
}
int root;
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++){
		scanf("%i %i %i %i %i",&xl[i],&xr[i],&yl[i],&yr[i],&z[i]);
		ord[i]=i;
	}
	sort(ord+1,ord+1+n,[&](int i,int j){return z[i]<z[j];});
	int q;
	scanf("%i",&q);
	for(int i=1;i<=q;i++){
		scanf("%i %i",&x[i],&y[i]);
		CX.Add(x[i]);
		CY.Add(y[i]);
	}
	CX.Build();
	CY.Build();
	for(int i=q;i>=1;i--){
		Seg2D::Reserve(root,1,CX.size(),CX.Find(x[i]),CY.Find(y[i]));
	}
	Seg2D::Build();
	for(int i=q;i>=1;i--){
		Seg2D::Add(root,1,CX.size(),CX.Find(x[i]),CY.Find(y[i]),i);
	}
	for(int i=1;i<=n;i++){
		best=0;
		Seg2D::Get(root,1,CX.size(),CX.GetL(xl[ord[i]]),CX.GetR(xr[ord[i]]),CY.GetL(yl[ord[i]]),CY.GetR(yr[ord[i]]));
		if(best){
			ans[best]=ord[i];
			was[best]=true;
		}
	}
	for(int i=1;i<=q;i++)printf("%i\n",ans[i]);
	return 0;
}