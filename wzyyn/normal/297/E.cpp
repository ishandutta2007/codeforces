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
const int N=200005;
int n,mat[N],id[N];
int t[N],ans1[N],ans2[N];
ll res;
void change(int k,int v){
	for (;k<=2*n;k+=k&(-k)) t[k]+=v; 
}
int ask(int k){
	int ans=0;
	for (;k;k-=k&(-k)) ans+=t[k];
	return ans;
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d",&n);
	For(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		mat[x]=y; mat[y]=x;
		id[x]=i; id[y]=i;
	}
	For(i,1,2*n) if (mat[i]>i){
		ans1[id[i]]+=ask(mat[i])-ask(i);
		change(mat[i],1); 
	}
	memset(t,0,sizeof(t));
	Rep(i,2*n,1) if (mat[i]<i){
		ans1[id[i]]+=ask(i)-ask(mat[i]);
		change(mat[i],1);
	}
	For(i,1,n) res+=1ll*ans1[i]*(n-1-ans1[i]);
	//For(i,1,n) cout<<ans1[i]<<' '; cout<<endl;
	//cout<<res<<endl;
	res=1ll*n*(n-1)*(n-2)/6-res/2;
	//cout<<res<<endl;
	memset(t,0,sizeof(t));
	For(i,1,2*n) if (mat[i]<i){
		ans2[id[i]]+=ask(2*n)-ask(mat[i]);
		change(mat[i],1);
	}
	//For(i,1,n) cout<<ans1[i]<<' '; cout<<endl;
	//For(i,1,n) cout<<ans2[i]<<' '; cout<<endl;
	For(i,1,n)
		res-=1ll*ans2[i]*(n-1-ans1[i]-ans2[i]);
	printf("%lld\n",res);
}