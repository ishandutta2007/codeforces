#include<bits/stdc++.h>
using namespace std;

const int maxn=1000007;
int n,cnt;
int a[maxn];
pair<long long,int> st[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout.precision(15);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=1;i<=n;++i){
        st[++cnt]={a[i],1};
        while (cnt>1&&st[cnt].first*st[cnt-1].second<st[cnt-1].first*st[cnt].second){
            st[cnt-1].first+=st[cnt].first;
            st[cnt-1].second+=st[cnt].second;
            cnt--;
        }
    }
    for (int i=1;i<=cnt;++i){
        for (int j=1;j<=st[i].second;++j){
            cout<<(1.0*st[i].first/st[i].second)<<"\n";
        }
    }
    return 0;
}