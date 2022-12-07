#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,a[N];
int mem1[N],mem2[N];
int mem3[N],mem4[N];
int *q1=mem1,*q2=mem2;
int *v1=mem3,*v2=mem4;
long long ans;
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	*q1=0; *q2=0; ans=0;
	for (int i=n;i>=1;i--){
		int x=1,t=0;
		for (;x<=a[i];){
			int y=a[i]/x;
			q1[++t]=y; v1[t]=0;
			x=(a[i]/y)+1;
		}
		*q1=t;
		v1[1]=1;
		int p=1;
		for (int j=1;j<=*q2;j++){
			int num=(a[i]+q2[j]-1)/q2[j];
			ans+=1ll*(num-1)*i*v2[j];
			int val=a[i]/num;
			for (;q1[p]!=val;++p);
			v1[p]+=v2[j];
		}
		ans%=998244353;
		//cout<<"debug "<<i<<' '<<ans<<endl;
		swap(q1,q2); swap(v1,v2);
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}