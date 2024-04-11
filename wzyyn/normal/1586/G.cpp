#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N=200005;
const int mo=1000000007;

int n,Q,a[N],b[N],spe[N*2];
int pre[N*2],t[N*2],f[N*2];
void change(int x,int v){
	for (;x;x-=x&(-x))
		t[x]=(t[x]+v)%mo;
}
int ask(int x){
	int s=0;
	for (;x<=2*n;x+=x&(-x)) s=(s+t[x])%mo;
	return s;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		pre[b[i]]=a[i];
	}
	for (int i=1;i<=2*n;i++)
		if (pre[i]){
			f[i]=(ask(pre[i])+1)%mo;
			change(pre[i],f[i]);
		}
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++){
		int x;
		scanf("%d",&x);
		spe[b[x]]=1;
	}
	int ans=0,p=1;
	for (int i=2*n;i>=1;i--)
		if (pre[i]){
			change(pre[i],mo-f[i]);
			if (spe[i]&&pre[i]>=p){
				ans=(ans+1+ask(p))%mo;
				p=pre[i];
			}
		}
	cout<<ans<<endl;
}