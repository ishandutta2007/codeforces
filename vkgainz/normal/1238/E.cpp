#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mat[20][20];
int occ[20];
int dp[(1<<20)];
int main(){
    int n; cin >> n;
    int m; cin >> m;
    string s; cin >> s;
    for(int i=0;i<n-1;i++){
        ++mat[(s[i+1]-'a')][s[i]-'a'];
        ++mat[s[i]-'a'][(s[i+1]-'a')];
        if(s[i]!=s[i+1]){
            ++occ[s[i]-'a'];
            ++occ[s[i+1]-'a'];
        }
    }
    for(int i=0;i<1<<m;i++) dp[i] = 1000000000;
    dp[0] = 0;
    for(int j=0;j<1<<m;j++){
        bitset<20> b(j);
        int x =b.count();
        for(int i=0;i<m;i++){
            if(j&(1<<i)){
                int tempSum = -occ[i];
                for(int k=0;k<m;k++){
                    if(k!=i && (j&(1<<k))){
                        tempSum+=2*mat[i][k];
                    }
                }
                dp[j] = min(dp[j],tempSum*(x-1)+dp[j^(1<<i)]);
            }
        }
    }
    cout << dp[(1<<m)-1] << endl;
    
}