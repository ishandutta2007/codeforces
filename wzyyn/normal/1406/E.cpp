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

const int N=100005;
int fl[N],pri[N];
int n,ans=1,q[N];
void init(){
	For(i,2,N-1) if (!fl[i])
		For(j,2,(N-1)/i) fl[i*j]=1;
	For(i,2,N-1) if (!fl[i]) pri[++*pri]=i;
	//cout<<*pri<<endl;
}
void divide(int l,int r){
	if (l>r) return;
	int mid=(l+r)/2,v;
	For(i,l,mid) cout<<"B "<<q[i]<<endl,cin>>v;
	cout<<"A "<<1<<endl; cin>>v;
	int except=1+(r-mid)+(ans!=1);
	if (v==except){
		divide(mid+1,r);
	}
	else{
		For(i,l,mid){
			cout<<"B "<<q[i]<<endl;
			cin>>v;
			if (v){
				ans*=q[i];
				break;
			}
		}
	}
}
int main(){
	init();
	scanf("%d",&n);
	For(i,1,*pri)
		if (1ll*pri[i]*pri[i]<=n){
			int v=pri[i],res;
			cout<<"B "<<v<<endl;
			cin>>res;
			cout<<"A "<<v<<endl;
			cin>>res;
			if (!res) continue;
			ans*=pri[i];
			for (v*=pri[i];v<=n;v*=pri[i]){
				cout<<"A "<<v<<endl;
				cin>>res;
				if (!res) break;
				ans*=pri[i];
			}
		}
	For(i,1,*pri) if (pri[i]<=n/ans)
		if (1ll*pri[i]*pri[i]>n)
			q[++*q]=pri[i];
	if (ans==1)
		divide(1,*q);
	else{
		For(i,1,*q){
			int v;
			cout<<"B "<<q[i]<<endl;
			cin>>v;
			if (v!=1)
				ans*=q[i];
		}
	}
	cout<<"C "<<ans<<endl; 
}