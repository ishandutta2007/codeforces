#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=53;

vector<int> arr(53), nxt(53);

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];

    bool right=n%2==0; // right-even, left-odd
    bool sad;
    if (n%2==0) sad=arr[n]==1;
    else sad=arr[1]==1; 
    cout << (sad?n-1:n) << '\n';
    for (int x=1;x<=n;++x){
        if (x==1&&sad){ right^=1; continue; }
        int p;
        for (int j=1;j<=n;++j) if (arr[j]==x) p=j;
        vector<int> curr;
        if (right){
            for (int i=1;i<x;++i) curr.push_back(1);
            curr.push_back(p-(x-1));
            if (p!=n) curr.push_back(n-p);
        }
        else{
            if (p!=1) curr.push_back(p-1);
            curr.push_back(n-x+2-p);
            for (int i=1;i<x;++i) curr.push_back(1);
        }
        cout << curr.size() << " ";
        for (int x:curr) cout << x << " ";
        cout << '\n';
        p=n+1; int p1=1;
        for (int x:curr){
            p-=x;
            for (int i=p;i<p+x;++i) nxt[i]=arr[p1++];
        }
        swap(nxt,arr); right^=1;
    }
}