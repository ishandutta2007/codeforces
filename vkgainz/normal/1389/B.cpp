#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k,z;
        cin >> n >> k >> z;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int pref[n];
        pref[0] = a[0];
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1]+a[i];
        }
        int ret = a[0];
        multiset<int, greater<int>> m;
        for(int r=1;r<=k;r++){
            //end at a[r];
            m.insert(a[r]+a[r-1]);
            int temp = pref[r];
            int numLeft = min((k-r)/2,z);
                       
            auto it = m.begin();
            int add = numLeft*(*it);
            if((z>0) && (k-r-1)>=0){
                add = max(add,a[r-1]+min((k-r-1)/2,z-1)*(*it));
            }
            ret = max(ret,temp+add);
        }
        cout << ret << endl;
    }
}