#include <bits/stdc++.h>
using namespace std;

int main() {
    int N,K;
    string s;
    cin >> N >> K >> s;
    vector<int> P(26,0);
    for(int i =0; i < N; i++) P[s[i]-'A']++;
    long long ans =0;
    sort(P.begin(),P.end());
    for(int i =25; i >= 0; i--) {
        ans +=1LL*min(K,P[i])*min(K,P[i]);
        K -=min(K,P[i]);}
    cout << ans << "\n";}