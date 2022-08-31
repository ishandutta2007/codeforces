#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
//#include <unordered_map>
#include <map>
#include <list>
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
    int n;
    scanf("%d\n", &n);
    //cout<<n<<endl;
    string s, t;
    s.resize(n);
    t.resize(n);
    for(int i=0; i<n; i++) scanf("%c",&s[i]);
    scanf("\n");
    for(int i=0; i<n; i++) scanf("%c",&t[i]);
    int k=n-1;
    while(s[k]==t[k]) k--;
    int ans=0;
    int kt=k;
    while((kt>0)&&(s[kt-1]==t[kt])) kt--;
    if(kt==0) ans++;
    else {
        kt--;
        while((kt>=0)&&(s[kt]==t[kt])) kt--;
        if(kt<0) ans++;
    }
    int ks=k;
    while((ks>0)&&(s[ks]==t[ks-1])) ks--;
    if(ks==0) ans++;
    else {
        ks--;
        while((ks>=0)&&(s[ks]==t[ks])) ks--;
        if(ks<0) ans++;
    }
    printf("%d", ans);

    //cout<<endl<<s<<endl<<t<<endl;

}