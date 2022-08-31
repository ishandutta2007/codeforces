#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int numOfFl(int n) {
    if (n > 6) {
        if(n%4==0) return 1+numOfFl(n/2);
        else return 0;
    }
    if (n==1) return 0;
    if (n==3) return 0;
    if (n==4) return 1;
    if (n==6) return 1;
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    string s;
    ll ans = 0;
    scanf("%d %d", &n,&k);
    vi a(n);
    //forn(i,1,21) cout<<i<<" "<<numOfFl(i)<<endl;
    forn(i,0,n) {
        scanf("%d", &a[i]);
    }
    if(k%2==0) {
        int win1=0;
        int bodd=0;
        int beven=0;
        forn(i,0,n) {
            if(a[i]%2==0) win1++;
            else if(a[i]==1) win1++;
            else continue;
            if(a[i]==2) beven++;
            else bodd++;
        }
        bodd=bodd%2;
        beven=beven%2;
        if((bodd+beven) == 0) cout<<"Nicky";
        else cout<<"Kevin";
        //if(win1%2==0) cout<<"Nicky";
        //else cout<<"Kevin";
        return 0;
    }
    int win1 = 0;
    vi b;
    int bodd=0;
    int beven=0;
    forn(i,0,n) {
        if(a[i]==1) win1++;
        else if(a[i]==3) win1++;
        else if((a[i]>2) && (a[i]%2==0)) win1++;
        else continue;
        b.pb(1 + numOfFl(a[i]));
        if(b.back()%2==0) bodd++;
        else beven++;
    }
    bodd=bodd%2;
    beven=beven%2;
    if((bodd+beven) == 0) cout<<"Nicky";
    else cout<<"Kevin";
    
    //cout<<ans;
}