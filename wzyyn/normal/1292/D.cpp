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
const int MM=5005;
int fl[MM],a[MM],mn[MM],n,x;
int S[MM],LL[MM],L[MM],LV[MM];
ll ans;
void init(){
	memset(mn,0,sizeof(mn));
	For(i,2,MM-1) For(j,2,(MM-1)/i) fl[i*j]=1;
	For(i,2,MM-1) For(j,1,(MM-1)/i)
		mn[i*j]=min(mn[i*j],i);
}
void build_tr(){
	ll top=0;
	For(i,2,MM-1){
		int x=i;
		For(j,2,x) if (!fl[j]&&x%j==0)
			for (;x%j==0;x/=j,++S[j]);
		For(j,LV[i],MM-1) LL[i]+=S[j];
		For(j,1,MM-1) L[i]+=S[j];
		x=i;
		for (;x%LV[i]==0;x/=LV[i],LL[i]--);
	}
	//cout<<LL[4096]<<' '<<L[4096]<<endl;
	//For(i,1,4) cout<<L[i]<<' '<<LL[i]<<' '<<LV[i]<<endl;
}
void getans(){
	ans=1ll<<60;
	For(i,1,MM-1){
		ll sum=0;
		int v=1<<30;
		For(j,i+1,MM-1){
			v=min(v,LL[j]);
			sum+=1ll*a[j]*(L[i]+L[j]-2*v);
			//if (i<=4&&j<=4) cout<<"INF "<<i<<' '<<j<<' '<<sum<<endl; 
		}
		v=1<<30;
		Rep(j,i-1,1){
			v=min(v,LL[j+1]);
			sum+=1ll*a[j]*(L[i]+L[j]-2*v);
		}
		ans=min(ans,sum);
		//if (i<=4) cout<<sum<<endl;
	}
	For(i,2,MM-1){
		ll sum=0;
		int v=LL[i];
		For(j,i,MM-1){
			v=min(v,LL[j]);
			sum+=1ll*a[j]*(LL[i]+L[j]-2*v);
		}
		v=LL[i];
		Rep(j,i-1,1){
			v=min(v,LL[j+1]);
			sum+=1ll*a[j]*(LL[i]+L[j]-2*v);
		}
		ans=min(ans,sum);
	}
}
int main(){
	init();
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&x),++a[max(x,1)];
	For(i,2,MM-1) if (!fl[i]) For(j,1,(MM-1)/i) LV[i*j]=i;
	//For(i,1,4) cout<<LV[i]<<endl;
	build_tr(); getans();
	cout<<ans<<endl;
}