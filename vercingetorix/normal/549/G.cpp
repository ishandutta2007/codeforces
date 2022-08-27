#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
char p[120][120];
int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n;
    cin>>n;
    vi a(n);
    for(int i=0; i<n; i++) {
        cin>>a[i];
        a[i]+=i;
    }
    sort(all(a));
    for(int i=0; i<n-1; i++) {
        if(a[i]==a[i+1]) {
            cout<<":(";
            return 0;
        }
    }
    for(int i=0; i<n; i++) {
        cout<<a[i]-i<<" ";
    }

}