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

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,k;
    cin>>n>>k;
    int odd=0;
    int even=0;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a%2==0) even++;
        else odd++;
    }
    int t=n-k;
    if(t==0) {
        if(odd%2==0) cout<<"Daenerys";
        else cout<<"Stannis";
        return 0;
    }
    if(t%2==0) {
        if((odd>(t/2))&&(even>(t/2))) {
            cout<<"Daenerys";
            return 0;
        }
        if((odd<=t/2)) {
            cout<<"Daenerys";
            return 0;
        }
        if(k%2==0) {
            cout<<"Daenerys";
            return 0;
        }
        else {
            cout<<"Stannis";
            return 0;
        }
    }
    if(t%2==1) {
        if((odd>(t/2))&&(even>(t/2))) {
            cout<<"Stannis";
            return 0;
        }
        if((odd<=t/2)) {
            cout<<"Daenerys";
            return 0;
        }
        if(k%2==0) {
            cout<<"Daenerys";
            return 0;
        }
        else {
            cout<<"Stannis";
            return 0;
        }
    }
}