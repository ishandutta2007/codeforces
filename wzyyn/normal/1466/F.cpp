#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=500005;
int n,m,fa[N];
vector<int> vec;
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m+1) fa[i]=i;
	int ans=1;
	For(i,1,n){
		int tp,x,y;
		scanf("%d%d",&tp,&x);
		if (tp==1) y=m+1;
		else scanf("%d",&y);
		if (get(x)!=get(y)){
			vec.PB(i);
			fa[get(x)]=get(y);
			ans=2ll*ans%1000000007;
		}
	} 
	printf("%d %d\n",ans,vec.size());
	for (auto i:vec) printf("%d ",i);
}