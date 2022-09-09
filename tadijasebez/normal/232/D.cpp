#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200050;
const int L=23;
struct SuffixArray{
	int s[N],n,id[N],sa[N],lcp[N],rmq[N][L],lgs[N],tmp[N],cnt[N],td[N];
	SuffixArray(){}
	void Add(int x){s[++n]=x;}
	void BuildSA(){
		int mx=0;
		for(int i=1;i<=n;i++)id[i]=s[i],sa[i]=i,mx=max(mx,id[i]);
		sort(sa+1,sa+1+n,[&](int i,int j){return id[i]<id[j];});
		for(int j=1;;j*=2){
			for(int i=1;i<=mx;i++)cnt[i]=0;
			for(int i=1;i<=n;i++)cnt[id[i]]++;
			for(int i=1,sum=0;i<=mx;i++)sum+=cnt[i],cnt[i]=sum-cnt[i];
			for(int i=1;i<=n;i++){
				int k=sa[i];
				if(k>j)tmp[++cnt[id[k-j]]]=k-j;
				td[i]=i+j<=n?id[i+j]:0;
			}
			for(int i=n-j+1;i<=n;i++)tmp[++cnt[id[i]]]=i;
			for(int i=1;i<=n;i++)sa[i]=tmp[i];
			int c=0;
			for(int i=1;i<=n;i++){
				tmp[sa[i]]=c+1;
				c+=i==n||id[sa[i]]!=id[sa[i+1]]||td[sa[i]]!=td[sa[i+1]];
				id[sa[i]]=tmp[sa[i]];
			}
			mx=c;
			if(c==n)break;
		}
	}
	void BuildLCP(){
		for(int i=1,k=0;i<=n;i++){
			if(id[i]!=n){
				int j=sa[id[i]+1];
				while(s[i+k]==s[j+k])k++;
				lcp[id[i]]=k;
				if(k)k--;
			}
		}
	}
	void BuildST(){
		for(int i=2;i<=n;i++)lgs[i]=lgs[i>>1]+1;
		for(int i=1;i<=n;i++)rmq[i][0]=lcp[i];
		for(int j=1;j<L;j++)
			for(int i=1;i<=n-(1<<j)+1;i++)
				rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<j-1)][j-1]);
	}
	int LCP(int i,int j){
		i=id[i];j=id[j];if(i>j)swap(i,j);
		if(i==j)return n-sa[i]+1;
		j--;int k=lgs[j-i+1];
		return min(rmq[i][k],rmq[j-(1<<k)+1][k]);
	}
	pair<int,int> GetRng(int pos,int len){
		pos=id[pos];
		int top=n,bot=pos+1,mid,R=pos,L=pos;
		while(top>=bot){
			mid=top+bot>>1;
			if(LCP(sa[pos],sa[mid])>=len)R=mid,bot=mid+1;
			else top=mid-1;
		}
		top=pos-1,bot=1;
		while(top>=bot){
			mid=top+bot>>1;
			if(LCP(sa[pos],sa[mid])>=len)L=mid,top=mid-1;
			else bot=mid+1;
		}
		return {L,R};
	}
}SA;
struct Compress{
	vector<int> all;
	void Add(int x){all.pb(x);}
	void Build(){sort(all.begin(),all.end());all.erase(unique(all.begin(),all.end()),all.end());}
	int Find(int x){return lower_bound(all.begin(),all.end(),x)-all.begin()+1;}
	int Lo(int x){return upper_bound(all.begin(),all.end(),x)-all.begin();}
	int Val(int x){return all[x-1];}
}CPR;
const int M=20*N;
int ls[M],rs[M],root[N],tsz,sum[M];
void Set(int p,int &c,int ss,int se,int qi){
	c=++tsz;ls[c]=ls[p];rs[c]=rs[p];sum[c]=sum[p]+1;
	if(ss==se)return;
	int mid=ss+se>>1;
	if(qi<=mid)Set(ls[p],ls[c],ss,mid,qi);
	else Set(rs[p],rs[c],mid+1,se,qi);
}
int Get(int p,int c,int ss,int se,int qs,int qe){
	if(qs>qe||qs>se||ss>qe)return 0;
	if(qs<=ss&&qe>=se)return sum[c]-sum[p];
	int mid=ss+se>>1;
	return Get(ls[p],ls[c],ss,mid,qs,qe)+Get(rs[p],rs[c],mid+1,se,qs,qe);
}
int dif[N],h[N];
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&h[i]);
	for(int i=1;i<n;i++)dif[i]=h[i+1]-h[i],dif[n+i]=-dif[i],CPR.Add(dif[i]),CPR.Add(dif[i+n]);
	CPR.Build();
	for(int i=1;i<n;i++)dif[i]=CPR.Find(dif[i]),dif[n+i]=CPR.Find(dif[n+i]);
	dif[n]=CPR.all.size()+1;dif[2*n]=dif[n]+1;
	for(int i=1;i<=2*n;i++)SA.Add(dif[i]);
	SA.BuildSA();
	SA.BuildLCP();
	SA.BuildST();
	for(int i=1;i<=2*n;i++)Set(root[i-1],root[i],1,2*n,SA.sa[i]);
	int q;scanf("%i",&q);
	while(q--){
		int l,r;
		scanf("%i %i",&l,&r);
		if(l==r)printf("%i\n",n-1);
		else{
			int len=r-l;
			int L,R;tie(L,R)=SA.GetRng(l+n,r-l);
			int ans=Get(root[L-1],root[R],1,2*n,1,l-len-1)+Get(root[L-1],root[R],1,2*n,r+1,n-1);
			printf("%i\n",ans);
		}
	}
	return 0;
}