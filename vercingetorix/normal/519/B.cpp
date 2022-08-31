#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    ll n;
    int newn=0;
    cin>>n;
    ll x;
    ll sum=0;
    ll sum2=0;
    ll sum3=0;
    for(int i=0; i<n; i++) {
        cin>>x;
        sum+=x;
    }
    for(int i=1; i<n; i++) {
        cin>>x;
        sum2+=x;
    }
    for(int i=2; i<n; i++) {
        cin>>x;
        sum3+=x;
    }
    cout<<sum-sum2<<endl<<sum2-sum3;


}