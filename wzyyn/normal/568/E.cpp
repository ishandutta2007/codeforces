#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=100005;
int n,a[N],b[N];
int m,la[N];
multiset<int> S;
pii last[N];
struct node{
	int v,x,y;
	bool operator <(const node &a)const{
		return v<a.v;
	}
}f[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	scanf("%d",&m);
	For(i,1,m){
		scanf("%d",&b[i]);
		S.insert(b[i]);
	}
	a[n+1]=(1<<30)-233;
	For(i,1,n+1) f[i]=(node){1<<30,0,0};
	sort(b+1,b+m+1,greater<int>());
	For(i,1,n+1)
		if (a[i]!=-1){
			la[i]=la[i-1];
			int l=1,r=i-1,ans=0;
			while (l<=r){
				int mid=(l+r)/2;
				if (f[mid].v<a[i])
					ans=mid,l=mid+1;
				else r=mid-1;
			}
			last[i]=pii(f[ans].x,f[ans].y);
			//printf("%d\n",ans);
			f[ans+1]=min(f[ans+1],(node){a[i],i,0});
		}
		else{
			la[i]=i; int p=i-1;
			For(j,1,m){
				for (;f[p].v>=b[j];--p);
				f[p+1]=min(f[p+1],(node){b[j],f[p].x,f[p].y+1});
			}
		}
	for (int i=n+1;i;){
		int t=last[i].se;
		int x=last[i].fi,v=a[i];
		//printf("%d %d %d %d\n",i,t,x,v);
		For(j,1,t){
			i=la[i-1];
			multiset<int>::iterator it;
			it=S.lower_bound(v);
			a[i]=v=*(--it);
			S.erase(it);
		}
		i=x;
	}
	For(i,1,n)
		if (a[i]==-1){
			printf("%d ",*S.begin());
			S.erase(S.begin());
		}
		else
			printf("%d ",a[i]);
}