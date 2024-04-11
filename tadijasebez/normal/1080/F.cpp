#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int H=100050;
const int K=300050;
const int N=K*2;
struct Compress{
	vector<int> all;
	void Add(int x){all.pb(x);}
	void Build(){sort(all.begin(),all.end());all.erase(unique(all.begin(),all.end()),all.end());}
	int Find(int x){return lower_bound(all.begin(),all.end(),x)-all.begin()+1;}
	int GetL(int x){return lower_bound(all.begin(),all.end(),x)-all.begin()+1;}
	int GetR(int x){return upper_bound(all.begin(),all.end(),x)-all.begin();}
}CPR;
const int M=38000000;
int ls[M],rs[M],tsz,mn[M],root[N];//,sum[M];
void cpy(int &c,int p){assert(tsz<M-1);c=++tsz;ls[c]=ls[p];rs[c]=rs[p];mn[c]=mn[p];}//sum[c]=sum[p];}
void Set(int &c,int ss,int se,int qi,int f){
	cpy(c,c);
	if(ss==se){mn[c]=f;return;}
	int mid=ss+se>>1;
	if(qi<=mid)Set(ls[c],ss,mid,qi,f);
	else Set(rs[c],mid+1,se,qi,f);
	mn[c]=min(mn[ls[c]],mn[rs[c]]);
}
int Get(int c,int ss,int se,int qs,int qe){
	if(qs<=ss && qe>=se)return mn[c];
	int mid=ss+se>>1;
	if(qe<=mid)return Get(ls[c],ss,mid,qs,qe);
	if(qs>mid)return Get(rs[c],mid+1,se,qs,qe);
	return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
/*void Add(int &c,int ss,int se,int qi,int f){
	cpy(c,c);sum[c]+=f;
	if(ss==se)return;
	int mid=ss+se>>1;
	if(qi<=mid)Add(ls[c],ss,mid,qi,f);
	else Add(rs[c],mid+1,se,qi,f);
}
int Get(int c,int ss,int se,int qs,int qe){
	if(qs<=ss && qe>=se)return sum[c];
	int mid=ss+se>>1;
	if(qe<=mid)return Get(ls[c],ss,mid,qs,qe);
	if(qs>mid)return Get(rs[c],mid+1,se,qs,qe);
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}*/
int sz,n;
/*vector<int> root[N],tme[N];
void Add(int x,int y,int f,int t){
	for(int i=x;i;i-=i&-i)root[i].pb(root[i].back()),Add(root[i].back(),1,n,y,f),tme[i].pb(t);
}
int Get(int x,int qs,int qe,int t){
	int ans=0;
	for(int i=x;i<=sz;i+=i&-i){
		int j=upper_bound(tme[i].begin(),tme[i].end(),t)-tme[i].begin();
		ans+=Get(root[i][j],1,n,qs,qe);
	}
	return ans;
}*/
int l[K],r[K],p[K],las[H];
vector<int> Us[N];
int main(){
	int m,k;
	scanf("%i %i %i",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%i %i %i",&l[i],&r[i],&p[i]);
		CPR.Add(l[i]);
		CPR.Add(r[i]);
	}
	CPR.Build();
	for(int i=1;i<=k;i++){
		l[i]=CPR.Find(l[i]);
		r[i]=CPR.Find(r[i]);
		Us[r[i]].pb(i);
	}
	sz=CPR.all.size();
	//for(int i=1;i<=sz;i++)root[i].pb(0);
	for(int i=1;i<=sz;i++){
		root[i]=root[i-1];
		for(int j:Us[i]){
			if(las[p[j]]<l[j]){
				//if(las[p[j]])Add(las[p[j]],p[j],-1,i);
				Set(root[i],1,n,p[j],l[j]);
				//Add(l[j],p[j],1,i);
				las[p[j]]=l[j];
			}
		}
	}
	while(m--){
		int a,b,x,y;
		scanf("%i %i %i %i",&a,&b,&x,&y);
		x=CPR.GetL(x);
		y=CPR.GetR(y);
		int mn=Get(root[y],1,n,a,b);
		if(mn>=x)printf("yes\n");
		else printf("no\n");
		//int cnt=Get(x,a,b,y)-Get(y+1,a,b,y);
		//if(cnt==b-a+1)printf("yes\n");
		//else printf("no\n");
		fflush(stdout);
	}
	return 0;
}