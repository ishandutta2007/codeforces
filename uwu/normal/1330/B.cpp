#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int arr[n+1];
        bool vis1[n]={0};
        bool vis2[n]={0};
        int high1=-1;
        int high2=-1;
        bool no=false;
        for (int i=1,a;i<=n;++i){
            cin >> a;
            if (vis1[a]&&vis2[a]) no = true;
            if (vis1[a]){vis2[a]=true;high2=max(high2,a);}
            vis1[a]=true;
            high1=max(high1,a);
            arr[i]=a;
        }
        for (int i=1;i<high1;++i){
            if (!vis1[i]) no=true;
        }
        for (int i=1;i<high2;++i){
            if (!vis2[i]) no=true;
        }
        bool test1[n]={0}; bool test2[n]={0};
        memset(test1,false,sizeof test1); memset(test2,false,sizeof test2);
        for (int i=1;i<=high1;++i){
            test1[arr[i]]=true;
        }
        for (int i=n-high1+1;i<=n;++i){
            test2[arr[i]]=true;
        }
        vector<pii> ans;
        bool ans1=true;
        for (int i=1;i<=high1;++i){
            if (!test1[i]) ans1=false;
        }
        if (ans1) ans.push_back({high1,high2});
        bool ans2=true;
        for (int i=1;i<=high1;++i){
            if (!test2[i]) ans2=false;
        }
        if (ans2) ans.push_back({high2,high1});
        if (no){
            cout << 0 << '\n';
            continue;
        }
        if (ans.size()==2) if (ans[0]==ans[1]) ans.pop_back();
        cout << ans.size() << '\n';
        for (auto&&x:ans){
            cout << x.first << " " << x.second << '\n';
        }
    }
}