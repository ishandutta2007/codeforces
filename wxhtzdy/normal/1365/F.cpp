#include <bits/stdc++.h>
using namespace std;

const int N=505;
int n,a[N],b[N];

void Solve(){
        scanf("%i",&n);
        for(int i=1;i<=n;i++)scanf("%i",&a[i]);
        for(int i=1;i<=n;i++)scanf("%i",&b[i]);
        bool ok=true;
        if(n%2==1&&a[n/2+1]!=b[n/2+1])ok=false;
        map<pair<int,int>,int> cnt;
        for(int i=1;i<=n/2;i++)cnt[{min(a[i],a[n-i+1]),max(a[i],a[n-i+1])}]++;
        for(int i=1;i<=n/2;i++){
                int mn=min(b[i],b[n-i+1]);
                int mx=max(b[i],b[n-i+1]);
                if(cnt[{mn,mx}]==0)ok=false;
                cnt[{mn,mx}]--;
        }
        puts(ok?"Yes":"No");
}

int main(){
        int t;scanf("%i",&t);
        while(t--)Solve();
}