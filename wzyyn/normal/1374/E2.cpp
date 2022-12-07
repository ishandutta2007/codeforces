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
#define all(v) v.begin(),v.end()
using namespace std;
const int N=200005;
int n,m,k;
vector<pii> vec[4];
ll sum[4][N];
int find(int x,int y){
	return lower_bound(vec[x].begin(),vec[x].end(),pii(y,1<<30))-vec[x].begin();
}
void Construct(int &p1,int &p2,int &p3,int &p4){
	if (p1+p2+p3+p4>m) return;
	int l=0,r=10000,ans=0;
	while (l<=r){
		int mid=(l+r)/2;
		int v=max(p1,find(0,mid));
		v+=max(p2,find(1,mid));
		v+=max(p3,find(2,mid));
		v+=max(p4,find(3,mid));
		if (v<=m) ans=mid,l=mid+1;
		else r=mid-1;
	}
	//cout<<ans<<' '<<p1+p2+p3+p4<<' '<<p1<<' '<<p2<<' '<<p3<< '<<p4<<endl;
	p1=max(p1,find(0,ans));
	p2=max(p2,find(1,ans));
	p3=max(p3,find(2,ans));
	p4=max(p4,find(3,ans));
	if (find(0,ans+1)>p1) p1+=min(find(0,ans+1)-p1,m-p1-p2-p3-p4);
	if (find(1,ans+1)>p2) p2+=min(find(1,ans+1)-p2,m-p1-p2-p3-p4);
	if (find(2,ans+1)>p3) p3+=min(find(2,ans+1)-p3,m-p1-p2-p3-p4);
	if (find(3,ans+1)>p4) p4+=min(find(3,ans+1)-p4,m-p1-p2-p3-p4);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,n){
		int x,a,b;
		scanf("%d%d%d",&x,&a,&b);
		vec[a*2+b].PB(pii(x,i));
	}
	For(i,0,3)
		sort(vec[i].begin(),vec[i].end());
	ll ans=1ll<<60;
	int p0,p1,p2,p3;
	For(i,0,3)
		For(j,1,n){
			sum[i][j]=sum[i][j-1];
			if (j<=vec[i].size())
				sum[i][j]+=vec[i][j-1].fi;
		}
	For(i,0,vec[3].size()) if (i<=k){
		int pp1,pp2,pp3,pp4;
		pp1=0; pp2=pp3=k-i; pp4=i;
		Construct(pp1,pp2,pp3,pp4);
		if (pp2>vec[1].size()||pp3>vec[2].size()||pp4>vec[3].size()) continue;
		if (pp1+pp2+pp3+pp4>m) continue;
		//cout<<i<<' '<<pp1<<' '<<pp2<<' '<<pp3<<' '<<pp4<<endl;
		if (sum[0][pp1]+sum[1][pp2]+sum[2][pp3]+sum[3][pp4]<ans){
			ans=sum[0][pp1]+sum[1][pp2]+sum[2][pp3]+sum[3][pp4];
			p0=pp1; p1=pp2; p2=pp3; p3=pp4;
		}
	}
	//cout<<p0<<' '<<p1<<' '<<p2<<' '<<p3<<endl;
	if (ans==1ll<<60) puts("-1");
	else{
		printf("%lld\n",ans);
		For(i,0,p0-1) printf("%d ",vec[0][i].se);
		For(i,0,p1-1) printf("%d ",vec[1][i].se);
		For(i,0,p2-1) printf("%d ",vec[2][i].se);
		For(i,0,p3-1) printf("%d ",vec[3][i].se);
	}
}
/*
12345
14235
21435
*/