#include <bits/stdc++.h>

using namespace std;

int f(int x){
    if (x==1) return 2;
    return 1;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t; cin >> t;
    for (int q=0;q<t;++q){
        int n; cin >> n;
        int ans[n];
        int arr[n];
        for (int i=0;i<n;++i) cin >> arr[i];
        ans[0]=1;
        int m=1;
        bool shift=false;
        int index=-1;
        for (int i=1;i<n;++i){
            if (arr[i]==arr[i-1]){
                ans[i]=ans[i-1];
                shift=true;
                index=i;
                continue;
            }
            m=2;
            ans[i]=f(ans[i-1]);
        }
        if (ans[n-1]==ans[0]&&arr[n-1]!=arr[0]){
            if (shift){
                ans[index]=f(ans[index-1]);
                for (int i=index+1;i<n;++i){
                    if (arr[i]==arr[i-1]){
                        ans[i]=ans[i-1];
                        continue;
                    }
                    ans[i]=f(ans[i-1]);
                }
            }
            else if (arr[n-1]==arr[n-2]){
                ans[n-1]=f(ans[0]);
            }
            else{
                ans[n-1]=3;
                m=3;
            }
        }
        cout << m << '\n';
        for (int i=0;i<n-1;++i){
            cout << ans[i] << " ";
        }
        cout << ans[n-1] << '\n';
    }
}