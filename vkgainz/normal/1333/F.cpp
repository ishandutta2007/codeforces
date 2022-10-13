
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int smallest[500005];
    set<int> prime;
    for(int i=2;i<=500000;i++){
        smallest[i] = i;
    }
    for(int i=2;i<=500000;i++){
        if(smallest[i]==i){
            prime.insert(i);
            for(int j=i;j<=500000;j+=i){
                smallest[j] = min(smallest[j],i);
            }
        }
    }
    int x = 1;
    int ans[500005];
    int np = 1;
    for(int i=2;i<=n;i++) np+=(smallest[i]==i);
    for(int i=2;i<=np;i++){
        ans[i] = 1;
    }
    x = 2;
    int cnt = np;
    auto it = prime.begin();
    while(cnt<=n && x<=n){
        it = prime.begin();
        while(it!=prime.end()){
            if(x*(*it)>n || (*it)>smallest[x]){
                break;
            }
            cnt++;
            ans[cnt] = x;
            it++;
        }
        x++;
    }
    for(int i=2;i<=n;i++){
        printf("%d ",ans[i]);
    }
}