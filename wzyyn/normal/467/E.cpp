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
const int N=500005;
int n,a[N],fa[N],ans[N];
map<int,int> mat,fir;
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) fa[i]=i;
	int k=1;
	for (;k<=n;){
		//cout<<k<<endl;
		int p=k;
		for (;k<=n;++k)
			if (mat[a[k]]){
				ans[++*ans]=mat[a[k]];
				ans[++*ans]=a[k];
				break;
			}
			else if (fir[a[k]])
				for (int p=get(fir[a[k]]+1);p<k;p=get(p))
					mat[a[p]]=a[k],fa[p]=p+1;
			else fir[a[k]]=k;
		if (k>n) break;
		For(i,p,k) mat[a[i]]=fir[a[i]]=0;
		k++;
	}
	printf("%d\n",2**ans);
	For(i,1,(*ans)/2) printf("%d %d %d %d ",ans[2*i-1],ans[2*i],ans[2*i-1],ans[2*i]);
}