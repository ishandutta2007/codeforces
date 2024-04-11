#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=200050;
struct BIT{
	int sum[N];
	void init(){for(int i=0;i<N;i++)sum[i]=0;}
	BIT(){init();}
	void Add(int i,int f){for(;i<N;i+=i&-i)sum[i]+=f;}
	int Get(int i){int ans=0;for(;i;i-=i&-i)ans+=sum[i];return ans;}
	int Search(int k){
		int top=N-1,bot=1,mid,ans=0;
		while(top>=bot){
			mid=top+bot>>1;
			int gt=Get(mid);
			if(gt<k)bot=mid+1,ans=mid;
			else top=mid-1;
		}
		return ans+1;
	}
}BT;
int a[N],id[N];
int k[N],p[N],ans[N];
vector<int> Qs[N];
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),id[i]=i;
	sort(id+1,id+1+n,[&](int i,int j){return mp(a[i],-i)>mp(a[j],-j);});
	int q;
	scanf("%i",&q);
	for(int i=1;i<=q;i++)scanf("%i %i",&k[i],&p[i]),Qs[k[i]].pb(i);
	for(int i=1;i<=n;i++){
		BT.Add(id[i],1);
		for(int j:Qs[i])ans[j]=a[BT.Search(p[j])];
	}
	for(int i=1;i<=q;i++)printf("%i\n",ans[i]);
	return 0;
}