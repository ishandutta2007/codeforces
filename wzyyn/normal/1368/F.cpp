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
int n,sum,vis[10005],xiba[10005];
int main(){
	scanf("%d",&n);
	if (n<=3){
		cout<<0<<endl;
		exit(0);
	}
	int val=0,p=0;
	For(i,2,n){
		int t=n-n/i-(n%i!=0)-(i-1);
		if (t>val) val=t,p=i;
	}
	For(i,1,n) xiba[i]=(i%p&&i!=n);
	int lim=val;
	for (;sum<lim;){
		cout<<val+p-1-sum;
		For(i,1,n-1) if (xiba[i]&&!vis[i]) vis[i]=1,cout<<' '<<i;
		cout<<endl;
		int len=lim+p-1-sum; sum+=len;
		int p; cin>>p;
		For(j,1,len){
			sum-=vis[p]; vis[p]=0;
			p=p%n+1;
		}
	}
	cout<<0<<endl;
}
/*
00000000000000000
11011011011011010
11000000000000010
11011011011011010
11011000000001010
11011011011011010
11011000000011010
11011011011011010
11011000001011010
*/