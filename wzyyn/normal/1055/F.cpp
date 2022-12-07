#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=1000005;
int n,R[N],mat[N];
int ls[N],rs[N];
int lss[N],rss[N];
ll k,ans,v[N];
int main(){
	scanf("%d%lld",&n,&k);
	For(i,2,n){
		int x;
		scanf("%d%lld",&x,&v[i]);
		v[i]^=v[x];
	}
	sort(v+1,v+n+1);
	R[1]=n;
	For(i,1,n) mat[i]=1;
	Rep(i,61,0){
		For(j,1,n) if (R[j]){
			rs[j]=ls[j]=-1;
			rss[j]=lss[j]=0;
			Rep(k,R[j],j)
				if ((v[k]>>i)&1)
					rss[j]++,rs[j]=k;
				else lss[j]++,ls[j]=k;
			if (rs[j]!=-1&&ls[j]!=-1)
				R[rs[j]]=R[j],R[j]=rs[j]-1;
		}
		ll tmp=0;
		For(j,1,n)
			if (mat[j]!=-1){
				int x=mat[j];
				tmp+=((v[j]>>i)&1?rss[x]:lss[x]);
			}
		if (tmp<k){
			ans+=1ll<<i;
			For(j,1,n)
				if (mat[j]!=-1)
					mat[j]=((v[j]>>i)&1?ls[mat[j]]:rs[mat[j]]);
			k-=tmp;
		}
		else{
			For(j,1,n)
				if (mat[j]!=-1)
					mat[j]=((v[j]>>i)&1?rs[mat[j]]:ls[mat[j]]);
		}
		//cout<<k<<' '<<tmp<<endl;
	}
	printf("%lld\n",ans);
}