#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n,s1,s2;
int a[N][2],p[N];

bool comp(int x,int y){
        return a[x][0]-a[x][1]>a[y][0]-a[y][1];
}

long long solve(){
        if (s2==0){
                long long sum=0;
                for(int i=1;i<=n;i++) sum+=a[i][1];
                return sum;
        }
        long long sum=0,ans=0;
        for(int i=1;i<=n;i++){
                if (i<=s2) sum+=max(a[p[i]][0],a[p[i]][1]);
                else sum+=a[p[i]][1];
        }
        ans=sum;
        for(int i=1;i<=n;i++){
                long long cur=sum;
                if (i<=s2) cur-=max(a[p[i]][0],a[p[i]][1]);
                else {
                        cur-=a[p[i]][1];
                        cur+=a[p[s2]][1]-max(a[p[s2]][0],a[p[s2]][1]);
                }
                cur+=a[p[i]][0]*(1LL<<s1);
                ans=max(ans,cur);
        }
        return ans;
}
int main(){
        cin>>n>>s1>>s2;
        s2=min(s2,n);
        for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1];
                
        for(int i=1;i<=n;i++) p[i]=i;
        sort(p+1,p+n+1,comp);
        cout<<solve();
}