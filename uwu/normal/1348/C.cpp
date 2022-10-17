#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,k; cin >> n >> k;
        string uwu; cin >> uwu;
        map<char,int> m;
        for (int i=0;i<n;++i){
            m[uwu[i]]++;
        }
        vector<pair<char,int>> arr;
        for (auto x:m){
            while (x.s>k){
                arr.push_back({x.f,k});
                x.s-=k;
            }
            arr.push_back(x);
            
        }

        if (arr[0].s<k){
            int temp=k,index=0;
            while (temp>arr[index].s){
                temp-=arr[index].s; index++;
            }
            cout << arr[index].f << '\n';
            continue;
        }
        if (m.size()==1||(m.size()==2&&m[arr[0].f]==k)){
            for (auto x:arr){
                cout << x.f;
            }
            cout << '\n';
            continue;
        }
        else{
            cout << arr[0].f;
            for (int i=1;i<arr.size();++i){
                for (int k=1;k<=arr[i].s;++k){
                    cout << arr[i].f;
                }
            }
            cout << '\n';
            continue;
        }

    }    
}