#include <bits/stdc++.h>
using namespace std;
const int N=200050;
const int L=18;
struct SparseTable{
	int rmq[N][L],seq[N],lgs[N];
	int cmb(int i,int j){return seq[i]>seq[j]?i:j;}
	void Build(int n,int a[]){
		for(int i=2;i<=n;i++)lgs[i]=lgs[i>>1]+1;
		for(int i=1;i<=n;i++)seq[i]=a[i],rmq[i][0]=i;
		for(int j=1;j<L;j++){
			for(int i=1;i<=n-(1<<j)+1;i++){
				rmq[i][j]=cmb(rmq[i][j-1],rmq[i+(1<<j-1)][j-1]);
			}
		}
	}
	int Get(int l,int r){
		int k=lgs[r-l+1];
		return max(seq[rmq[l][k]],seq[rmq[r-(1<<k)+1][k]]);
	}
	int Search(int l,int r,int v){
		int top=r,bot=l,mid,ans=l-1;
		while(top>=bot){
			mid=top+bot>>1;
			if(Get(l,mid)<=v)ans=mid,bot=mid+1;
			else top=mid-1;
		}
		return ans;
	}
}ST;
int a[N];
pair<int,int> b[N];
int main(){
	int t;
	scanf("%i",&t);
	while(t--){
		int n;
		scanf("%i",&n);
		for(int i=1;i<=n;i++)scanf("%i",&a[i]);
		ST.Build(n,a);
		int m;
		scanf("%i",&m);
		for(int i=1;i<=m;i++)scanf("%i %i",&b[i].first,&b[i].second);
		sort(b+1,b+1+m);
		int t=1;
		for(int i=2;i<=m;i++){
			while(t>0 && b[i].second>=b[t].second)t--;
			b[++t]=b[i];
		}
		m=t;
		int ptr=1,ans=0;
		auto gt=[&](int i){
			if(i>m || i==0)return 0;
			int up=min(n,ptr+b[i].second-1);
			return ST.Search(ptr,up,b[i].first)-ptr+1;
		};
		while(ptr<=n){
			int top=m,bot=1,mid,pos=m+1;
			while(top>=bot){
				mid=top+bot>>1;
				int up=min(n,ptr+b[mid].second-1);
				if(ST.Get(ptr,up)<=b[mid].first)pos=mid,top=mid-1;
				else bot=mid+1;
			}
			int add=max(gt(pos),gt(pos-1));
			if(add==0)break;
			ptr+=add;
			ans++;
		}
		if(ptr>n)printf("%i\n",ans);
		else printf("-1\n");
	}
	return 0;
}