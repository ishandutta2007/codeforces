#include <bits/stdc++.h>

using namespace std;

const int N=31;
int n;
long long m;
long long a[N];
int main(){
        cin>>n>>m;
        for(int i=0;i<N;i++) a[i]=(1LL<<62)-1;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=1;i<N;i++) a[i]=min(a[i],2*a[i-1]);

        long long ans=(1LL<<62)-1;
        long long sum=0;
        int cur=0;
        for(int i=N-1;i>=0;i--) {
                if (cur+(1LL<<i)>=m) ans=min(ans,sum+a[i]);
                if ((m>>i)&1) sum+=a[i],cur+=1<<i;
        }
        cout<<ans;
}