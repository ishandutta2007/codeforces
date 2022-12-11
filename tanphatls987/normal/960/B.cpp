#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,m1,m2;
int a[2][N];
void prepare(){
        cin>>n>>m1>>m2;
        for(int i=0;i<=1;i++)
                for(int j=1;j<=n;j++) cin>>a[i][j];
        for(int i=1;i<=n;i++) a[0][i]=abs(a[0][i]-a[1][i]);
        
}
long long check(int mid){
        long long sum=0;
        for(int i=1;i<=n;i++) sum+=max(0,a[0][i]-mid);
        return sum;
}
long long solve(){
        long long sum=0;
        for(int i=1;i<=n;i++) sum+=a[0][i];
        if (sum<m1+m2){
                int rem=m1+m2-sum;
                return rem%2;
        }
        int L=0,R=10000000;
        while (L<=R){
                int mid=(L+R)/2;
                if (check(mid)<=m1+m2) R=mid-1;
                else L=mid+1;
        }
        int rem=m1+m2-check(L);
        long long ans=0;
        for(int i=1;i<=n;i++){
                if (a[0][i]<L) ans+=1LL*a[0][i]*a[0][i];
                else {
                        int use=(rem>0);
                        ans+=1LL*(L-use)*(L-use);
                        rem-=use;
                }
        }
        return ans;
}
int main(){
        prepare();
        cout<<solve();
}