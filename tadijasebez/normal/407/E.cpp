#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
const int M=2*N;
int ls[M],rs[M],tsz,root;
ll mn[M],lzy[M];
void Build(int &c,int ss,int se){
	c=++tsz;
	if(ss==se){mn[c]=ss;return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	mn[c]=min(mn[ls[c]],mn[rs[c]]);
}
void Add(int c,int ss,int se,int qs,int qe,ll f){
	if(qs>qe||qs>se||ss>qe)return;
	if(qs<=ss&&qe>=se){mn[c]+=f;lzy[c]+=f;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mn[c]=min(mn[ls[c]],mn[rs[c]])+lzy[c];
}
ll Get(int c,int ss,int se,int qs,int qe){
	if(qs<=ss&&qe>=se)return mn[c];
	int mid=ss+se>>1;
	if(qe<=mid)return Get(ls[c],ss,mid,qs,qe)+lzy[c];
	if(qs>mid)return Get(rs[c],mid+1,se,qs,qe)+lzy[c];
	return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe))+lzy[c];
}
int a[N],ost[N],num[N];
int main(){
	int n,k,d;
	scanf("%i %i %i",&n,&k,&d);
	if(d==0){
		int mx=0,l,r;
		for(int i=1,j=1;i<=n;i++){
			scanf("%i",&a[i]);
			if(a[i]!=a[i-1])j=i;
			if(mx<i-j+1)mx=i-j+1,l=j,r=i;
		}
		printf("%i %i\n",l,r);
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%i",&a[i]);
		a[i]+=1e9+7;
		num[i]=a[i]/d;
		ost[i]=a[i]%d;
	}
	//for(int i=1;i<=n;i++)printf("%i ",num[i]);printf("\n");
	Build(root,1,n);
	int ans=0,l,r;
	stack<int> mn,mx;mn.push(0);mx.push(0);
	map<int,int> cnt;
	for(int i=1,j=i;i<=n;i++){
		if(ost[i]!=ost[i-1])j=i,cnt.clear();
		cnt[num[i]]++;
		while(cnt[num[i]]>1){
			cnt[num[j]]--;
			j++;
		}
		while(mn.size()>1&&num[mn.top()]>=num[i]){
			int z=mn.top();mn.pop();
			Add(root,1,n,mn.top()+1,z,num[z]);
		}
		Add(root,1,n,mn.top()+1,i,-num[i]);
		mn.push(i);
		while(mx.size()>1&&num[mx.top()]<=num[i]){
			int z=mx.top();mx.pop();
			Add(root,1,n,mx.top()+1,z,-num[z]);
		}
		Add(root,1,n,mx.top()+1,i,num[i]);
		mx.push(i);
		int bot=j,top=i,mid,pos=i;
		while(top>=bot){
			mid=top+bot>>1;
			if(Get(root,1,n,j,mid)<=k+i)pos=mid,top=mid-1;
			else bot=mid+1;
		}
		if(ans<i-pos+1)ans=i-pos+1,l=pos,r=i;
		//for(int z=1;z<=n;z++)printf("%lld ",Get(root,1,n,z,z));printf("\n");
	}
	printf("%i %i\n",l,r);
	return 0;
}