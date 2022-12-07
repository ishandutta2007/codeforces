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
const int N=4005;
int n,m,k;
int l[N],r[N];
vector<int> v[N];
struct node{
	int s[N];
	void insert(int l,int r,int v){
		For(i,k,n){
			int pl=max(l,i-k+1);
			int pr=min(r,i);
			if (pl<=pr) s[i]+=v*(pr-pl+1);
		}
	}
	int mx(){
		int v=0;
		For(i,k,n) v=max(v,s[i]);
		return v;
	}
}T1,T2;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,m){
		scanf("%d%d",&l[i],&r[i]);
		v[l[i]+r[i]].PB(i);
		T2.insert(l[i],r[i],1);
	}
	int ans=T1.mx()+T2.mx();
	For(i,1,2*n){
		for (auto j:v[i]){
			T2.insert(l[j],r[j],-1);
			T1.insert(l[j],r[j],1);
		}
		ans=max(ans,T1.mx()+T2.mx());
	}
	cout<<ans<<endl;
}