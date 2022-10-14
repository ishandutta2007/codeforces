#include<bits/stdc++.h>

using namespace std;

#define ii pair<long long,long long>

bool cmp(pair<ii,long long> a, pair<ii,long long> b)
{
    if(a.first.first == b.first.first)
            return a.first.second < b.first.second;
    else
            return a.first.first > b.first.first;
}
int main() {
    long long n;
    cin >> n;
    long long a[n];
    vector<pair<ii,long long> > v;
    for(long long i = 0; i < n; i++)
    {
        cin>>a[i];
        long long tr = a[i];
        long long ans1 = 0 ,ans2 = 0;
        while(tr % 3 == 0) {
            ans1++;
            tr /= 3;
        }
        while(tr % 2 == 0) {
            ans2++;
            tr /= 2;
        }
        v.push_back({{ans1,ans2},a[i]});
    }
    sort(v.begin(), v.end(), cmp);
    for(long long i = 0;i < n; i++)
        cout << v[i].second << " ";
}