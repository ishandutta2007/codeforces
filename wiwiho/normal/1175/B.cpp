#include <bits/stdc++.h>

#define iter(a) a.begin(), a.end()
#define lsort(a) sort(cont(a))
#define gsort(a) sort(cont(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

//#define TEST

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

#define MAX 4294967295

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int l;
    cin >> l;

    int x = 0;
    stack<pair<ll, ll>> fortimes; //times, xadd
    fortimes.push(mp(1, 0));
    bool ans = true;
    for(int i = 0; i < l; i++){
        string str;
        cin >> str;
        if(str == "add"){
            fortimes.top().second++;
        }
        else if(str == "for"){
            int n;
            cin >> n;
            fortimes.push(mp(n, 0));
        }
        else{
            pair<ll, ll> t = fortimes.top();
            fortimes.pop();
            fortimes.top().second += t.first * t.second;
        }
        if(fortimes.top().second > MAX){
            ans = false;
            break;
        }
    }

    if(!ans){
        cout << "OVERFLOW!!!\n";
    }
    else{
        cout << fortimes.top().second << "\n";
    }
    
    return 0;
}