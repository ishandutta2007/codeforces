#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int>
#define debug cout<<"hihihihi"<<endl;
using namespace std;
 
typedef long long ll;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
int dp[10007][107],f[10007][107],num[107],sum=0,tot=0;
int cnt=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        int u;
        cin>>u;
        num[u]++;
    }
    for (int i=1;i<=100;++i){
        if (num[i]) cnt++;
    }
    dp[0][0]=1;
    for (int i=1;i<=100;++i){
        memset(f,0,sizeof(f));
        for (int j=0;j<=sum;++j){
            for (int r=0;r<=tot;++r){
                for (int k=0;k<=num[i];++k){
                    f[j+k*i][r+k]+=dp[j][r];
                }
            }
        }
        sum+=i*num[i], tot+=num[i];
        for (int j=0;j<=sum;++j){
            for (int k=0;k<=tot;++k){
                dp[j][k]=f[j][k]>2?2:f[j][k];
            }
        }
    }
    if (cnt==2) {cout<<n<<endl; return 0;}
    int ans=0;
    for (int i=1;i<=100;++i){
        for (int j=1;j<=num[i];++j){
            if (dp[i*j][j]==1) ans=max(ans,j);
        }
    }
    cout<<ans<<endl;
    return 0;
}