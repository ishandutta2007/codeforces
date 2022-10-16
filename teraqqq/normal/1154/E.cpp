#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using pii = pair<int, int>;

const int N = 2e5+7;

int n, k, a[N], team[N];
vector<pii> leaders;
set<int> people;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k;
    for(int i =  0; i < n; ++i) {
        cin >> a[i];
        leaders.push_back({a[i], i});
        people.insert(i);
    }
    
    sort(leaders.begin(), leaders.end(), greater<pii>());
    
    auto cur_lead = leaders.begin();
    int cur_team = 1;
    while(!people.empty()) {
        while(team[cur_lead->S] != 0) if(++cur_lead == leaders.end()) break;
        int lead = cur_lead->S; vector<int> writed(1, lead);
        auto lit = people.find(lead), rit = people.find(lead); team[lead] = cur_team;
        for(int i = 0; i < k && ++rit != people.end();   ++i) writed.push_back(*rit), team[*rit] = cur_team;
        for(int i = 0; i < k && lit-- != people.begin(); ++i) writed.push_back(*lit), team[*lit] = cur_team;
        for(int x : writed) people.erase(x);
        cur_team = 3 - cur_team;
    }
    
    for(int i = 0; i < n; ++i) 
        cout << team[i];
    cout << endl;
}