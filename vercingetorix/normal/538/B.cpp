#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
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
    int n,m;
    string s;
    cin >> n;
    vi a;
    while (n>0){
        a.pb(n%10);
      //  cout<<n%10<<endl;
        n/=10;
    }
     m=0;
    int l =a.size();
    //cout<<l<<endl;
    for(int i=0; i<l; i++) {
        if(a[i]>m) m=a[i];
    }
    cout<<m<<endl;
    for(int i=0; i<m; i++) {
        int ans=0;
        int cur=1;
        for(int j=0; j<l; j++){
            if(a[j]>0){
                ans+=cur;
                a[j]--;
            }
            cur*=10;
        }
        cout<<ans<<" ";
    }

}