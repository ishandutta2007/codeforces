#include <bits/stdc++.h>

#define lsort(a) sort(a.begin(), a.end())
#define gsort(a) sort(a.rbegin(), a.rend())
#define mp(a, b) make_pair(a, b)

//#define TEST

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<int> index(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        index[p[i]] = i;
    }

    vector<pair<int, int>> ans;
    for(int i = 1; i <= n; i++){
        if(index[i] == i){
            continue;
        }
        else if(abs(index[i] - i) >= n / 2){
            ans.push_back(mp(index[i], i));
        }
        else if(abs(index[i] - 1) >= n / 2 && abs(i - 1) >= n / 2){
            ans.push_back(mp(index[i], 1));
            ans.push_back(mp(1, i));
            ans.push_back(mp(1, index[i]));
        }
        else if(abs(index[i] - 1) >= n / 2 && abs(i - n) >= n / 2){
            ans.push_back(mp(index[i], 1));
            ans.push_back(mp(1, n));
            ans.push_back(mp(i, n));
            ans.push_back(mp(1, n));
            ans.push_back(mp(1, index[i]));
        }
        else if(abs(index[i] - n) >= n / 2 && abs(i - 1) >= n / 2){
            ans.push_back(mp(index[i], n));
            ans.push_back(mp(1, n));
            ans.push_back(mp(i, 1));
            ans.push_back(mp(1, n));
            ans.push_back(mp(n, index[i]));
        }
        else if(abs(index[i] - n) >= n / 2 && abs(i - n) >= n / 2){
            ans.push_back(mp(index[i], n));
            ans.push_back(mp(n, i));
            ans.push_back(mp(n, index[i]));
        }
        //cerr << i << " " << p[index[i]] << " " << p[i] << "\n";
        int t = p[i];
        swap(p[index[i]], p[i]);
        index[t] = index[i];
        index[i] = i;

        /*for(int j = 1; j <= n; j++){
            cerr << p[j] << " ";
        }
        cerr << "\n";*/
    }

    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
    
    return 0;
}