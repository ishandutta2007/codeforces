#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int arr[n+1]={0},f[27][n+1]={0},b[27][n+2]={0},count=0;
        memset(f,0,sizeof f); memset(b,0,sizeof b);
        for (int i=1;i<=n;++i) cin >> arr[i];
        for (int num=1;num<=26;++num){
            count=0;
            for (int i=1;i<=n;++i){
                if (arr[i]==num) count++;
                f[num][i]=max(f[num][i-1],count);
            }
            count=0;
            for (int i=n;i>0;--i){
                if (arr[i]==num) count++;
                b[num][i]=max(b[num][i+1],count);
            }
        }
        
        int ans=0;
        for (int num=1;num<=26;++num){
            vector<int> a;
            for (int i=1;i<=n;++i){
                if (arr[i]==num) a.push_back(i);
            }
            for (int i=0;i<a.size();++i){
                for (int k=i;k<a.size();++k){
                    
                    for (int j=1;j<=26;++j){
                        //cout << num << " " << a[i] << " " << a[k] << " " << f[a[i]-1] << " " << b[a[k]+1] << '\n';
                        ans=max(ans,k-i+1+(min(f[j][a[i]-1],b[j][a[k]+1])*2));
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}