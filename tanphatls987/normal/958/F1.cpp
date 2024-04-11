#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n,m;
int a[N],need[N];
int h[N];
string solve(){
        int sum=0;
        for(int i=1;i<=m;i++) sum+=need[i];
        for(int i=1;i<=n;i++){
                h[a[i]]++;
                if (i>=sum){
                        bool okay=1;
                        for(int j=1;j<=m;j++) okay&=h[j]==need[j];
                        if (okay) return "YES";
                        h[a[i-sum+1]]--;
                }
        }
        return "NO";
}
int main(){
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=m;i++)   cin>>need[i];

        cout<<solve();
}