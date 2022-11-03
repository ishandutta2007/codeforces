#include<bits/stdc++.h> 
using namespace std;
#define int long long
int n,a[1000000],f[1000000],c,x,y,q,ff[1000000],fk[1000000];
void putit(int x,int y){
	fk[x]+=y;if(fk[x]!=1&&fk[x]!=0){fk[x]-=y;return;}
	for (;x<=n;x+=x&(-x))ff[x]+=y;
	}
int findit(int x){int ans=0;for (;x;x-=x&(-x))ans+=ff[x];return ans;}
signed main(){
	ios::sync_with_stdio(false);
	cin>>n;for (int i=1;i<=n;i++)cin>>a[i],f[a[i]]=i;
	putit(1,1);for (int i=2;i<=n;i++)if (f[i-1]>f[i])putit(i,1);
	cin>>q;while (q--){
		cin>>c>>x>>y;if (c==1){
			if (x>y)swap(x,y);
			cout<<findit(y)-findit(x)+1<<endl;
		}else {
			if (a[x]-1>=1&&f[a[x]-1]>f[a[x]])putit(a[x],-1);
			if (a[x]+1<=n&&f[a[x]]>f[a[x]+1])putit(a[x]+1,-1);
			if (a[y]-1>=1&&f[a[y]-1]>f[a[y]])putit(a[y],-1);
			if (a[y]+1<=n&&f[a[y]]>f[a[y]+1])putit(a[y]+1,-1);
			swap(a[x],a[y]);swap(f[a[x]],f[a[y]]);
			if (a[x]-1>=1&&f[a[x]-1]>f[a[x]])putit(a[x],1);
			if (a[x]+1<=n&&f[a[x]]>f[a[x]+1])putit(a[x]+1,1);
			if (a[y]-1>=1&&f[a[y]-1]>f[a[y]])putit(a[y],1);
			if (a[y]+1<=n&&f[a[y]]>f[a[y]+1])putit(a[y]+1,1);
		}
	} 
}