#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
int arr[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int m;
    cin>>m;
    int mi=INT_MAX;
    int a;
    for(int i=0;i<m;i++){
        cin>>a;
        mi=min(mi,a);
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n,greater<>());
    int mdlen=mi+2;
    int ans=0;
    for(int i=0;i<n;i++){
        if(i%mdlen<mi)ans+=arr[i];
    }
    printf("%d\n",ans);
    return 0;
}