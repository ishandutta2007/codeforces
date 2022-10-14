#include <bits/stdc++.h>
using namespace std;

int n,k;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k>>s;
    vector<int> cnt(k);
    for (int i=0;i<n;++i)cnt[s[i]-'A']++;
    cout<<*min_element(cnt.begin(),cnt.end())*k;
}