#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN=500005;
int Q,n,A[MAXN]; ll s[MAXN];
void solve(){
	if (n==1){printf("%.10lf\n",A[1]);return;}
	int l=1,r=n-1,ans=1;
	while (l<=r){
		int mid=l+r>>1;
		if (A[mid]<1.0*(s[mid]+A[n])/(mid+1)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%.10lf\n",A[n]-1.0*(s[ans]+A[n])/(ans+1));
}
int main(){
	scanf("%d",&Q);
	while (Q--){
		int type;
		scanf("%d",&type);
		if (type==1) scanf("%d",&A[++n]),s[n]=s[n-1]+A[n];
		else if (type==2) solve();
	}
	return 0;
}