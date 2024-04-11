#include<bits/stdc++.h>
using namespace std;
const int N=20007;
int t,n,s[N],mn,mx,ans;
int main(){
	scanf("%d",&t);
	while(t--){
        scanf("%d",&n);
        mx=-1e9,mn=1e9;
        ans=-1e9;
        for(int i=1;i<=n;i++)scanf("%d",&s[i]);
        for(int i=2;i<=n;i++)mx=max(mx,s[i]);
        for(int i=1;i<n;i++)mn=min(mn,s[i]);
        ans=max(mx-s[1],max(s[n]-mn,s[n]-s[1]));
        for(int i=1;i<n;i++) ans=max(ans,s[i]-s[i+1]);
        printf("%d\n",ans);
    }
	return 0;
}