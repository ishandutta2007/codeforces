#include<bits/stdc++.h>

using namespace std;

const int N=1000005;
int n;
long long a[N],ans;
int b[N],tg[65];
int bic(long long x){
	int s=0;
	for (;x;x-=x&(-x)) ++s;
	return s;
}
int mnp[N],mxp[N];
void solve(int l,int r){
	if (l==r){
		++ans;
		return;
	}
	int mid=(l+r)/2;
	solve(l,mid);
	solve(mid+1,r);
	mnp[mid]=mxp[mid]=mid;
	mnp[mid+1]=mxp[mid+1]=mid+1;
	//cout<<l<<' '<<r<<' '<<ans<<endl;
	for (int i=mid-1;i>=l;i--){
		mnp[i]=(a[i]<=a[mnp[i+1]]?i:mnp[i+1]);
		mxp[i]=(a[i]>=a[mxp[i+1]]?i:mxp[i+1]);
	}
	for (int i=mid+2;i<=r;i++){
		mnp[i]=(a[i]<a[mnp[i-1]]?i:mnp[i-1]);
		mxp[i]=(a[i]>a[mxp[i-1]]?i:mxp[i-1]);
	}
	int p1=mid+1,p2=mid+1;
	for (int i=mid;i>=l;i--){
		for (;p1<=r&&a[mnp[p1]]>=a[mnp[i]];++p1) ++tg[b[mxp[p1]]];
		for (;p2<=r&&a[mxp[p2]]<=a[mxp[i]];++p2) --tg[b[mxp[p2]]];
		if (b[mnp[i]]==b[mxp[i]]) ans+=min(p1,p2)-(mid+1);//LL
		//if (l==1&&r==2) cout<<p1<<' '<<p2<<' '<<mnp[i]<<' '<<mnp[p1]<<' '<<a[mnp[p1]]<<' '<<a[mnp[i]]<<endl;
		if (p1>p2) ans+=tg[b[mnp[i]]];//LR;
	}
	for (int i=0;i<=60;i++) tg[i]=0;
	p1=mid; p2=mid;
	for (int i=mid+1;i<=r;i++){
		for (;p1>=l&&a[mnp[p1]]>a[mnp[i]];--p1) ++tg[b[mxp[p1]]];
		for (;p2>=l&&a[mxp[p2]]<a[mxp[i]];--p2) --tg[b[mxp[p2]]];
		if (b[mnp[i]]==b[mxp[i]]) ans+=mid-max(p1,p2); //RR
		if (p1<p2) ans+=tg[b[mnp[i]]];//RL; 
	}
	for (int i=0;i<=60;i++) tg[i]=0;
	//cout<<l<<' '<<r<<' '<<ans<<endl;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=bic(a[i]);
	}
	solve(1,n);
	cout<<ans<<endl;
}
/*


, 
*/