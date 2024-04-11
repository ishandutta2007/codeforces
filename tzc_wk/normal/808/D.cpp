#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100005],s[100005],sum;
inline bool find(int l,int r,int x){
	int L=l,R=r;
	while(L<=R){
		int mid=(L+R)>>1;
		if(s[mid]==x)	return 1;
		if(s[mid]>x)	R=mid-1;
		else			L=mid+1;
	}
	return 0;
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)	s[i]=s[i-1]+a[i],sum+=a[i];
	if(sum%2ll)	return puts("NO"),0;
	for(int i=1;i<=n;i++){
		if(find(1,i-1,sum/2-a[i])||find(i+1,n,sum/2+a[i]))
			return puts("YES"),0;
	}
	puts("NO");
	return 0;
}