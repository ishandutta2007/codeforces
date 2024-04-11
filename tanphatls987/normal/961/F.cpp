#include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;
const int BASE[2]={479,47};
const int MOD=1e9+7;

int n;
string s;
long long ha[2][N],pb[2][N];

pair<long long,long long> get(int L,int R){
        long long ans1=ha[0][R]-ha[0][L-1]*pb[0][R-L+1];
        long long ans2=(ha[1][R]-ha[1][L-1]*pb[1][R-L+1]%MOD+MOD)%MOD;
        return make_pair(ans1,ans2);
}

int ans[N];
int main(){
        cin>>n>>s;
        pb[0][0]=1;
        for(int i=1;i<=n;i++) pb[0][i]=pb[0][i-1]*BASE[0];
        for(int i=1;i<=n;i++) ha[0][i]=ha[0][i-1]*BASE[0]+s[i-1];
        pb[1][0]=1;
        for(int i=1;i<=n;i++) pb[1][i]=pb[1][i-1]*BASE[1]%MOD;
        for(int i=1;i<=n;i++) ha[1][i]=(ha[1][i-1]*BASE[1]+s[i-1])%MOD;
        ans[n/2+1]=-1;
        for(int i=n/2;i>=1;i--){
                int L=i,R=n+1-i;
                ans[i]=ans[i+1]+2;
                while (ans[i]!=-1){
                        if (get(L,L+ans[i]-1)==get(R-ans[i]+1,R)) break;
                        ans[i]-=2;
                }
        }

        for(int i=1;i<=(n+1)/2;i++) cout<<ans[i]<<" ";
}