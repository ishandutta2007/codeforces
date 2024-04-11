#include <bits/stdc++.h>

using namespace std;

//#define TEST

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    map<int, int> count;
    multiset<pair<int, int>> pairs;
    map<int, vector<int>> amount;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        count[a]++;
        count[b]++;
        pairs.insert(make_pair(min(a, b), max(a, b)));
    }

    for(auto it = count.begin(); it != count.end(); it++){
        amount[it->second].push_back(it->first);
    }

    bool ans = false;

    for(auto it = count.begin(); it != count.end(); it++){

        int a = it->first;

        auto bit = amount.lower_bound(m - it->second);
        for(; bit != amount.end(); bit++){

            for(auto bbit = bit->second.begin(); bbit != bit->second.end(); bbit++){
                if(*bbit == it->first){
                    continue;
                }
                if(count[*bbit] + it->second - pairs.count(make_pair(min(*bbit, it->first), max(*bbit, it->first))) == m){
                    ans = true;
                    //cerr << *bbit << " " << it->first << " " << pairs.count(make_pair(min(*bbit, it->second), max(*bbit, it->second))) << " "
                    //        << min(*bbit, it->first) << " " << max(*bbit, it->first) << "\n";
                    goto outside;
                }
            }

        }

    }

    outside:

    cout << (ans ? "YES" : "NO") << "\n";
    
    return 0;
}