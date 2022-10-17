#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

int arr[MAXN],n,k;

bool check(int x){
    int cnt=0;
    for (int i=1;i<=n;){
        if (i==n) cnt+=arr[i]<=x, ++i;
        else if (arr[i]<=x) cnt+=2, i+=2;
        else ++i;
    }
    if (cnt>=k) return true;
    cnt=1;
    for (int i=2;i<=n;){
        if (i==n) cnt+=arr[i]<=x, ++i;
        else if (arr[i]<=x) cnt+=2, i+=2;
        else ++i;
    }
    if (cnt>=k) return true;
    return false;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> k;
    for (int i=1;i<=n;++i) cin >> arr[i];
    int high=1e9,low=1,mid;
    while (low<=high){
        mid=(high+low)/2;
        if (check(mid)){
            if (!(check(mid-1))){ cout << mid << '\n'; return 0;}
            else{
                high=mid-1;
            }
        }
        else{
            low=mid+1;
        }
    }
}