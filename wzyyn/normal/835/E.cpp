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
int n,x,y;
int q[1005];
int find(){
	int l=1,r=*q;
	while (l<r){
		int mid=(l+r)/2;
		cout<<"? "<<mid-l+1;
		For(i,l,mid) cout<<' '<<q[i];
		cout<<endl;
		int v;
		cin>>v;
		if (v!=((mid-l)&1?0:x))
			r=mid;
		else l=mid+1;
	}
	return q[l];
}
int main(){
	scanf("%d%d%d",&n,&x,&y);
	int p=0;
	for (;;++p){
		*q=0;
		For(i,1,n) if (i&(1<<p)) q[++*q]=i;
		cout<<"?";
		For(i,0,*q) cout<<' '<<q[i];
		cout<<endl;
		int v;
		cin>>v;
		if (v!=((*q)&1?x:0))
			break;
	}
	*q=0;
	For(i,1,n)
		if (i&(1<<p))
			q[++*q]=i;
	int ans1=find();
	*q=0;
	For(i,1,n){
		int v1=i&((1<<(p+1))-1);
		int v2=ans1&((1<<p)-1);
		if (v1==v2) q[++*q]=i;
	}
	int ans2=find();
	if (ans1>ans2) swap(ans1,ans2);
	cout<<"! "<<ans1<<' '<<ans2;
}