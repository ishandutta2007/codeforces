#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,X,a[N];
int main() {
    int t;
    scanf("%d",&t);
    while (t--){
        scanf("%d%d",&n,&X);
        int ans=0,mx=0,mi=1e9;
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            mx=max(mx,a[i]);
            mi=min(mi,a[i]);
            if(mx-mi>2*X)ans++,mx=a[i],mi=a[i];
        }
        printf("%d\n",ans);
    }
	return 0;
}