#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n,m,p,x[510000],y[510000],c[510000],sa[510000],ra[510000],height[510000],A[510000],B[1100000],N;
int R[510000];
char ch[510000];
void make(){
	for (int i=1;i<=m;i++) c[i]=0;
	for (int i=1;i<=n;i++) c[x[i]]++;
	for (int i=1;i<=m;i++) c[i]+=c[i-1];
	for (int i=1;i<=n;i++){
		sa[c[x[i]]]=i; c[x[i]]--;
	}
	int k=1;
	while (k<n){
		p=0;
		for (int i=n-k+1;i<=n;i++) y[++p]=i;
		for (int i=1;i<=n;i++) if (sa[i]>k) y[++p]=sa[i]-k;
		for (int i=1;i<=m;i++) c[i]=0;
		for (int i=1;i<=n;i++) c[x[y[i]]]++;
		for (int i=1;i<=m;i++) c[i]+=c[i-1];
		for (int i=n;i;i--){
			sa[c[x[y[i]]]]=y[i]; c[x[y[i]]]--;
		}
		memcpy(y,x,sizeof x);
		p=1; x[sa[1]]=1;
		for (int i=2;i<=n;i++){
			if (y[sa[i]]!=y[sa[i-1]]||y[sa[i]+k]!=y[sa[i-1]+k]) p++; x[sa[i]]=p;
		}
		if (p==n) break; m=p; k<<=1;
	}
	for (int i=1;i<=n;i++) ra[sa[i]]=i;
	k=0;
	for (int i=1;i<=n;i++){
		if (ra[i]==1) continue;
		if (k) k--;
		while (ch[i+k]==ch[sa[ra[i]-1]+k]) k++;
		height[ra[i]]=k;
	}
}
void insert(int k1,int k2){
	for (;k1<=N;k1+=k1&(-k1)) B[k1]=min(B[k1],k2);
}
int find(int k1){
	int ans=n+1; for (;k1;k1-=k1&(-k1)) ans=min(ans,B[k1]); return ans;
}
map<int,int>M;
struct atom{
	int where,w,f;
}q[1010000];
int len;
int compare(atom k1,atom k2){
	return k1.where>k2.where;
}
int main(){
	scanf("%d",&n); m=1000; N=n*2+1;
	scanf("%s",ch+1); 
	for (int i=1;i<=n;i++) x[i]=ch[i];
	make();
	A[0]=n+1;
	for (int i=1;i<=n;i++){
		if (ch[i]=='(') A[i]=1; else A[i]=-1;
		A[i]+=A[i-1];
	}
	for (int i=0;i<=N;i++) B[i]=n+1;
	for (int i=n;i;i--){
		insert(A[i],i); R[i]=find(A[i-1]-1)-1;
	}
	for (int i=n;i;i--){
		int k1=height[ra[i]]; int l=i+k1,r=R[i];
	//	cout<<"count "<<i<<" "<<l<<" "<<r<<endl;
		if (l<=r){
			q[++len]=(atom){l,A[i-1],1};
			if (r<n) q[++len]=(atom){r+1,A[i-1],-1};
		}
	}
//	for (int i=1;i<=n;i++) cout<<sa[i]<<" "; cout<<endl;
//	for (int i=1;i<=n;i++) cout<<height[i]<<" "; cout<<endl;
	sort(q+1,q+len+1,compare);
	int now=1; long long ans=0;
	for (int i=n;i;i--){
		M[A[i]]++;
		while (now<=len&&q[now].where==i) ans+=M[q[now].w]*q[now].f,now++;
	}
	cout<<ans<<endl;
	return 0;
}