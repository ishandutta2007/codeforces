#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 10;


map<int, int> a;
int psum[N];

void solve() { 
    for(auto i : a) { 
        psum[i.second]++;        
    }
    for(int i = N - 2; i >= 1; i--) 
        psum[i] += psum[i + 1];

    pair<int, int> ans(0, 0);
    int tot = 0;
    for(int height = 1; height < N; height++) {
        tot += psum[height];
        int width = tot / height;
        
        if (width >= height && ans.first * ans.second < height * width) 
            ans = {height, width};
    }
    vector<pair<int, int>> tmpAns;
    for(auto i : a) tmpAns.push_back({min(i.second, ans.first), i.first});
    sort(tmpAns.begin(), tmpAns.end());
    reverse(tmpAns.begin(), tmpAns.end());

    vector<int> rawAns;
    for(auto i : tmpAns)
        for(int j = 0; j < i.first; j++)
            rawAns.push_back(i.second);

    int height, width; tie(height, width) = ans;


    assert(rawAns.size() >= height * width);
    vector<vector<int>> ansB(height, vector<int>(width, 0));

    for(int st = 0; st < width; st++) {
        for(int i = 0; i < height; i++) {
            ansB[i][(st + i) % width] = rawAns[st * height + i];
        }
    }
    cout << height * width << '\n';
    cout << height << " " << width << '\n';

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) cout << ansB[i][j] << " ";
        cout << '\n';
    }
}
int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    while (n--) { 
        int val;
        cin >> val;
        a[val]++;
    }
    solve();
}