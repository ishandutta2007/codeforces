#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=51;
long double dp[51][51][51];
int arr[MAXN];
long double ways[51];
long double fact[51];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)dp[i][0][0]=1;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        for(int j=0;j<n;j++){
            if(i!=j) {
                for (int k = n-1; k >=1; k--) {
                    for (int l=0;l<=50;l++){
                        if(l-arr[i]>=0)dp[j][k][l]+=dp[j][k-1][l-arr[i]];
                    }
                }
            }
        }
    }
    int p;
    cin>>p;
    if(sum<=p){
        printf("%d\n",n);
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=max(0,p-arr[i]+1);k<=p;k++){
                ways[j]+=dp[i][j][k];
            }
        }
    }
    fact[0]=1;
    for(int i=1;i<=50;i++){
        fact[i]=fact[i-1]*(long double)i;
    }
    long double ans=0;
    for(int i=0;i<n;i++){
        ans+=ways[i]*fact[i]*fact[n-i-1]*(long double)i/fact[n];
    }
    printf("%.7Lf\n",ans);
    return 0;
}