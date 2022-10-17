#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n],b[n];
        int plus=0,minus=0;
        for (int i=0;i<n;++i){
            cin >> a[i];
            if (a[i]==1) plus++;
            if (a[i]==-1) minus++;
        }
        for (int i=0;i<n;++i){
            cin >> b[i];
        }
        bool ans=true;
        for (int i=n-1;i>=0;--i){
            if (a[i]==1) plus--;
            if (a[i]==-1) minus--;
            if (a[i]>b[i]&&minus==0){
                ans=false;
            }
            if (a[i]<b[i]&&plus==0){
                ans=false;
            }
            
        }
        if (ans) cout << "YES" << '\n';
        else cout << "NO" << '\n';


    }
}