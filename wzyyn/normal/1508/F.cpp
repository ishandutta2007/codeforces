#include<bits/stdc++.h>
using namespace std;

const int B=230;
const int N=25005;
const int M=100005;
int n,Q;
int a[N],p[N],bel[N];
int l[M],r[M],pre[N],nxt[N];
int Sl[N],Sr[N];
vector<int> L[N],R[N];
vector<pair<int,int> > D[N];
vector<pair<int,int> > v[B];
bitset<N*3000> f1,f2; 
int Pl[N],Pr[N],Pd[N],ans;

struct Tree1{
	int nn,t[N*4];
	void build(int n){
		for (nn=1;nn<=n;nn<<=1);
		for (int i=0;i<=2*nn-1;i++) t[i]=1<<30;
	}
	void change(int x,int v){
		for (x+=nn;x;x>>=1)
			t[x]=min(t[x],v);
	}
	int ask(int l,int r){
		int ans=1<<30;
		l+=nn-1; r+=nn+1;
		for (;l^r^1;l>>=1,r>>=1){
			if (!(l&1)) ans=min(ans,t[l^1]);
			if (r&1)	ans=min(ans,t[r^1]);
		}
		return ans;
	}
}T1;

struct Tree2{
	int nn;
	pair<int,int> t[N*4];
	void build(int n){
		for (nn=1;nn<=n;nn<<=1);
		for (int i=0;i<=2*nn-1;i++) t[i]=pair<int,int>(1<<30,0);
	}
	void change(int x){
		pair<int,int> val(1<<30,x);
		if (Pr[x]<R[x].size())
			val.first=R[x][Pr[x]];
		x+=nn; t[x]=val;
		for (x>>=1;x;x>>=1)
			t[x]=min(t[x*2],t[x*2+1]);
	}
	pair<int,int> ask(int l,int r){
		pair<int,int> ans(1<<30,0);
		l+=nn-1; r+=nn+1;
		for (;l^r^1;l>>=1,r>>=1){
			if (!(l&1)) ans=min(ans,t[l^1]);
			if (r&1)	ans=min(ans,t[r^1]);
		}
		return ans;
	}
}T2;


struct Tree3{
	int nn;
	pair<int,int> t[N*4];
	void build(int n){
		for (nn=1;nn<=n;nn<<=1);
		for (int i=0;i<=2*nn-1;i++) t[i]=pair<int,int>(-(1<<30),0);
	}
	void change(int x){
		pair<int,int> val(-(1<<30),x);
		if (Pl[x]>=0)
			val.first=L[x][Pl[x]];
		x+=nn; t[x]=val;
		for (x>>=1;x;x>>=1)
			t[x]=max(t[x*2],t[x*2+1]);
	}
	pair<int,int> ask(int l,int r){
		pair<int,int> ans(-(1<<30),0);
		l+=nn-1; r+=nn+1;
		for (;l^r^1;l>>=1,r>>=1){
			if (!(l&1)) ans=max(ans,t[l^1]);
			if (r&1)	ans=max(ans,t[r^1]);
		}
		return ans;
	}
}T3;

struct Tree4{
	int nn;
	pair<int,int> t[N*4];
	void build(int n){
		for (nn=1;nn<=n;nn<<=1);
		for (int i=0;i<=2*nn-1;i++) t[i]=pair<int,int>(1<<30,0);
	}
	void change(int x){
		pair<int,int> val(1<<30,x);
		if (Pd[x]<D[x].size())
			val.first=D[x][Pd[x]].first;
		x+=nn; t[x]=val;
		for (x>>=1;x;x>>=1)
			t[x]=min(t[x*2],t[x*2+1]);
	}
	pair<int,int> ask(int l,int r){
		pair<int,int> ans(1<<30,0);
		l+=nn-1; r+=nn+1;
		for (;l^r^1;l>>=1,r>>=1){
			if (!(l&1)) ans=min(ans,t[l^1]);
			if (r&1)	ans=min(ans,t[r^1]);
		}
		return ans;
	}
}T4;
int main(){
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),p[a[i]]=i;
	for (int i=1;i<=n;i++)
		bel[i]=(i-1)/B+1;
	for (int i=1;i<=Q;i++){
		scanf("%d%d",&l[i],&r[i]);
		v[bel[l[i]]].push_back(pair<int,int>(r[i],l[i]));
	}
	for (int i=1;i<=bel[n];i++){
		if (!v[i].size()) continue;
		sort(v[i].begin(),v[i].end());
		int la=0,pl=(i-1)*B+1,pr=v[i].back().first;
		memset(pre,0,sizeof(pre));
		memset(nxt,0,sizeof(nxt));
		for (int j=1;j<=n;j++)
			if (p[j]>=pl&&p[j]<=pr){
				pre[p[j]]=la;
				nxt[la]=p[j];
				if (la){
					if (p[j]<la) R[p[j]].push_back(la);
					else L[p[j]].push_back(la);
				}
				la=p[j];
			}
		for (;v[i].size();v[i].pop_back()){
			int nr=v[i].back().first;
			int nl=v[i].back().second;
			for (;pr>nr;){
				int v=pr--;
				pre[nxt[v]]=pre[v];
				nxt[pre[v]]=nxt[v];
				if (pre[v]&&nxt[v]){
					if (pre[v]>nxt[v])
						R[nxt[v]].push_back(pre[v]);
					else
						L[nxt[v]].push_back(pre[v]);
				}
			}
			int x=pl;
			for (;pl<nl;){
				int v=pl++;
				pre[nxt[v]]=pre[v];
				nxt[pre[v]]=nxt[v];
				if (pre[v]&&nxt[v]){
					if (pre[v]>nxt[v])
						R[nxt[v]].push_back(pre[v]);
					else
						L[nxt[v]].push_back(pre[v]);
				}
			}
			for (;pl!=x;){
				int v=--pl;
				pre[nxt[v]]=v;
				nxt[pre[v]]=v;
			}
		}
	}
	for (int i=1;i<=n;i++){
		sort(L[i].begin(),L[i].end());
		sort(R[i].begin(),R[i].end());
		L[i].resize(unique(L[i].begin(),L[i].end())-L[i].begin());
		R[i].resize(unique(R[i].begin(),R[i].end())-R[i].begin());
		//for (auto j:L[i])
		//	printf("MatL %d %d\n",i,j);
		//for (auto j:R[i])
		//	printf("MatR %d %d\n",i,j);
	}
	for (int i=1;i<=n;i++){
		Sl[i]=Sr[i-1]+R[i-1].size();
		Sr[i]=Sl[i  ]+L[i]  .size();
	}
	
	T1.build(n);
	for (int i=n;i>=1;i--){
		for (int j=0;j<L[i].size();j++){
			if (a[L[i][j]]+1==a[i]) continue;
			int p=T1.ask(a[L[i][j]]+1,a[i]-1);
			if (p!=1<<30) D[L[i][j]].push_back(pair<int,int>(p,Sl[i]+j));
		}
		T1.change(a[i],i);
	}
	T1.build(n);
	for (int i=1;i<=n;i++){
		for (int j=0;j<R[i].size();j++){
			if (a[R[i][j]]+1==a[i]) continue;
			int p=T1.ask(a[R[i][j]]+1,a[i]-1);
			if (p!=1<<30) D[-p].push_back(pair<int,int>(R[i][j],Sr[i]+j));
		}
		T1.change(a[i],-i);
	}
	
	//for (int i=1;i<=n;i++)
	//	for (auto j:D[i])
	//		printf("Delete %d %d idx=%d\n",i,j.first,j.second);
	
	T2.build(n);
	T3.build(n);
	T4.build(n);
	for (int i=1;i<=n;i++){
		sort(D[i].begin(),D[i].end());
		Pd[i]=0;
		Pl[i]=L[i].size()-1;
		Pr[i]=0;
		T2.change(i);
		T3.change(i);
		T4.change(i);
	}
	for (int i=1;i<=Q;i++){
		for (;;){
			pair<int,int> v=T2.ask(l[i],r[i]);
			if (v.first>r[i]) break;
			int p=v.second;
			if (Pr[p]!=0){
				if (!f2[Sr[p]+Pr[p]-1]) --ans;
				f1[Sr[p]+Pr[p]-1]=0;
			}
			for (;Pr[p]<R[p].size()&&R[p][Pr[p]]<=r[i];++Pr[p]);
			if (!f2[Sr[p]+Pr[p]-1]) ++ans;
			f1[Sr[p]+Pr[p]-1]=1;
			T2.change(p);
		}
		for (;;){
			pair<int,int> v=T3.ask(l[i],r[i]);
			if (v.first<l[i]) break;
			int p=v.second;
			if (Pl[p]!=L[p].size()-1){
				if (!f2[Sl[p]+Pl[p]+1]) --ans;
				f1[Sl[p]+Pl[p]+1]=0;
			}
			for (;Pl[p]>=0&&L[p][Pl[p]]>=l[i];--Pl[p]);
			if (!f2[Sl[p]+Pl[p]+1]) ++ans;
			f1[Sl[p]+Pl[p]+1]=1;
			T3.change(p);
		}
		for (;;){
			pair<int,int> v=T4.ask(l[i],r[i]);
			if (v.first>r[i]) break;
			int p=v.second;
			for (;Pd[p]<D[p].size()&&D[p][Pd[p]].first<=r[i];++Pd[p]){
				int x=D[p][Pd[p]].second;
				if (!f2[x]){
					f2[x]=1;
					if (f1[x]) --ans;
				}
			}
			T4.change(p);
		}
		printf("%d\n",ans);
	}
}