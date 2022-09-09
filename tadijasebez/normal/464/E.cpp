#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int mod=1e9+7;
const int N=100050;
const int inf=100007;
const int base=37;
const int M=30000000;
int mul(int x,int y){return (ll)x*y%mod;}
int add(int x,int y){x+=y;return x>=mod?x-mod:x;}
int ls[M],rs[M],tsz,hsh[M],sz[M],lzy[M],po[N],po2[N];
int cpy(int &c,int p){c=++tsz;ls[c]=ls[p];rs[c]=rs[p];sz[c]=sz[p];hsh[c]=hsh[p];lzy[c]=lzy[p];}
void pull(int c,int ss,int se){
	int mid=ss+se>>1;
	hsh[c]=add(mul(hsh[ls[c]],po[se-mid]),hsh[rs[c]]);
	sz[c]=sz[ls[c]]+sz[rs[c]];
}
void upd(int &c){
	cpy(c,c);
	sz[c]=hsh[c]=0;
	lzy[c]=1;
}
void push(int c){
	if(lzy[c])upd(ls[c]),upd(rs[c]);
	lzy[c]=0;
}
void Set_1(int &c,int ss,int se,int qi){
	cpy(c,c);sz[c]++;
	if(ss==se){hsh[c]=base;return;}
	push(c);
	int mid=ss+se>>1;
	if(qi<=mid)Set_1(ls[c],ss,mid,qi);
	else Set_1(rs[c],mid+1,se,qi);
	pull(c,ss,se);
}
void Set_0(int &c,int ss,int se,int qs,int qe){
	if(qs>qe || qs>se || ss>qe)return;
	cpy(c,c);
	if(qs<=ss && qe>=se){hsh[c]=sz[c]=0;lzy[c]=1;return;}
	push(c);
	int mid=ss+se>>1;
	Set_0(ls[c],ss,mid,qs,qe);
	Set_0(rs[c],mid+1,se,qs,qe);
	pull(c,ss,se);
}
int At(int &c,int ss,int se,int qi){
	if(ss==se)return sz[c];
	push(c);
	int mid=ss+se>>1;
	if(qi<=mid)return At(ls[c],ss,mid,qi);
	return At(rs[c],mid+1,se,qi);
}
int Fir(int &a,int &b,int ss,int se){
	if(hsh[a]==hsh[b])return -1;
	if(ss==se)return ss;
	push(a);push(b);
	int mid=ss+se>>1;
	if(hsh[rs[a]]==hsh[rs[b]])return Fir(ls[a],ls[b],ss,mid);
	return Fir(rs[a],rs[b],mid+1,se);
}
int Get_0(int &c,int ss,int se,int qs,int qe){
	if(qs>qe || qs>se || ss>qe)return 0;
	if(qs<=ss && qe>=se)return se-ss+1-sz[c];
	push(c);
	int mid=ss+se>>1;
	return Get_0(ls[c],ss,mid,qs,qe)+Get_0(rs[c],mid+1,se,qs,qe);
}
int Find(int &c,int ss,int se,int k){
	if(ss==se)return ss;
	push(c);
	int mid=ss+se>>1,lsz=mid-ss+1-sz[ls[c]];
	if(lsz<k)return Find(rs[c],mid+1,se,k-lsz);
	return Find(ls[c],ss,mid,k);
}
int val(int a){
	int ans=0;
	for(int i=0,j=1;i<N;i++,j=mul(j,2)){
		if(At(a,0,N-1,i))
			ans=add(ans,j);
	}
	return ans;
}
int num[N],go[N],bit[N];
bool cmp(int &a,int &b){
	if(a==inf)return 0;
	if(b==inf)return 1;
	int idx=Fir(a,b,0,N);
	if(idx==-1)return 0;
	return At(a,0,N,idx)<At(b,0,N,idx);
}
int add_bit(int a,int b){
	int cnt=Get_0(a,0,N,0,b-1);
	int idx=Find(a,0,N,cnt+1);
	//printf("%i %i\n",cnt,idx);
	//printf("%i + %i = ",val(a),1<<b);
	Set_0(a,0,N,b,idx-1);
	Set_1(a,0,N,idx);
	//printf("%i\n",val(a));
	return a;
}
struct DijkstraPQ{
	int a[N],idx[N],val[N],n;
	void init(int _n,int st,int inf){
		n=_n;
		for(int i=1;i<=n;i++)a[i]=i,val[i]=inf;
		swap(a[st],a[1]);
		for(int i=1;i<=n;i++)idx[a[i]]=i;
		val[st]=0;
	}
	int size(){return n;}
	void Change(int x,int f){
		val[x]=f;
		int p=idx[x];
		while(p>1 && cmp(f,val[a[p/2]]))a[p]=a[p/2],idx[a[p]]=p,p/=2;
		a[p]=x;idx[x]=p;
	}
	int top(){return a[1];}
	void pop(){
		int now=1;
		a[1]=a[n];n--;
		idx[a[1]]=1;
		while(now*2<=n){
			int ch=now*2;
			if(ch+1<=n && cmp(val[a[ch+1]],val[a[ch]]))ch++;
			if(!cmp(val[a[ch]],val[a[now]]))break;
			swap(a[now],a[ch]);
			idx[a[now]]=now;
			idx[a[ch]]=ch;
			now=ch;
		}
	}
}pq;
vector<pair<int,int>> E[N];
void pre(){
	po[0]=1;
	for(int i=1;i<N;i++)po[i]=mul(po[i-1],base);
	po2[0]=1;
	for(int i=1;i<N;i++)po2[i]=mul(po2[i-1],2);
}
int main(){
	pre();
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=1,u,v,x;i<=m;i++)scanf("%i %i %i",&u,&v,&x),E[u].pb({v,x}),E[v].pb({u,x});
	int s,t;
	scanf("%i %i",&s,&t);
	for(int i=1;i<=n;i++)num[i]=inf;
	num[s]=0;
	pq.init(n,s,inf);
	while(pq.size()){
		int u=pq.top();
		pq.pop();
		if(num[u]==inf)break;
		for(auto e:E[u]){
			int v,x;tie(v,x)=e;
			int now=add_bit(num[u],x);
			if(cmp(now,num[v])){
				num[v]=now;
				pq.Change(v,num[v]);
				go[v]=u;
				bit[v]=x;
			}
		}
	}
	if(num[t]==inf)return 0*printf("-1\n");
	//printf("%i\n",val(num[t]));
	vector<int> path;
	for(int i=t;i;i=go[i])path.pb(i);
	reverse(path.begin(),path.end());
	int ans=0;
	for(int i=t;i!=s;i=go[i])ans=add(ans,po2[bit[i]]);
	printf("%i\n",ans);
	printf("%i\n",path.size());
	for(int i:path)printf("%i ",i);
	printf("\n");
	return 0;
}