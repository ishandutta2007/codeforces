#include"bits/stdc++.h"
typedef long long ll;
using namespace std;
const int N=100005;

int a[2*N],b[N],n,k,sa[N*2];
ll ans,sum;

int main(){
	scanf("%d%d",&n,&k);int i,j;
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);a[i+n]=a[i];
		sa[i]=sa[i-1]+a[i];
	}
	for(i=1;i<=k;i++){
		scanf("%d",&b[i]);
		sum+=a[b[i]];
	}
	sort(b+1,b+k+1);
	for(i=j=1;i<n;i++){
		if(i==b[j]){
			ans+=(ll)(sa[n]-sa[i])*a[i];
			sum-=a[b[j++]];
		} else{
			if(i+1==b[j]){
				ans+=(ll)sum*a[i];
			} else {
				ans+=(ll)(sum+a[i+1])*a[i];
			}
		}
	}
	if(b[k]!=n&&b[1]!=1)ans+=(ll)a[1]*a[n];
	cout<<ans<<endl;
	return 0;
}