#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <deque>
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
ll ml=1000000000000000000;
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define fo(a, b, c) for(int a = b; a < c; a++)

#define pb push_back
#define mp make_pair

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    ll n,k;
    cin>>n>>k;
    //for(int i=0; i<n; i++) 
    vll f(52);
    f[0]=1;
    f[1]=1;
    fo(i, 2, 52) {
        f[i]=f[i-1]+f[i-2];
    }
    int curpos=1;
    while(curpos<n) {
        if(k<=f[n-curpos]) {
            cout<<curpos<<' ';
            curpos++;
        }
        else {
            cout<<curpos+1<<' '<<curpos<<' ';
            k-=f[n-curpos];
            curpos+=2;
        }
    }
    if(curpos == n) cout<<n;


}