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
int n,cnt[1<<15],id[1<<15];
ll v[15];
int main(){
	scanf("%d",&n);
	For(i,0,(1<<13)-1) cnt[i]=cnt[i/2]+(i&1);
	For(i,0,(1<<13)-1) if (cnt[i]==6) id[++*id]=i;
	For(i,0,12){
		static int q[1005]; *q=0;
		For(j,1,n) if (id[j]&(1<<i)) q[++*q]=j;
		if (!*q) continue;
		cout<<"?";
		For(j,0,*q) cout<<' '<<q[j];
		cout<<endl;
		cin>>v[i];
	}
	cout<<"!";
	For(i,1,n){
		ll val=0;
		For(j,0,12) if (!(id[i]&(1<<j))) val|=v[j];
		cout<<' '<<val;
	}
}