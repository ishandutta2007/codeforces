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
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
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
    int n,m,k;
    ll ans = 0;
    string s;
    scanf("%d %d\n", &n, &k);
    vector<char> c(n);
    //scanf("%s", c);
    //gets(c.data());
    getline(cin, s);
    //cin>>s;
    //string s(c);
    //scagets(&s);
    string s2;
    for(int i = 0; i<n; i++) {
        int h = s[i]-'a';
        if (h<=12) {
            if(k>25-h) {
                k-=25-h;
                s2.pb('z');
            }
            else {
                s2.pb(char('a'+h+k));
                k=0;
            }
        }
        else {
            if(k>h) {
                k-=h;
                s2.pb('a');
            }
            else {
                s2.pb(char('a'+(h-k)));
                k=0;
            }
        }
    }
    if(k>0) {
        printf("-1");
        return 0;
    }
    //cout<<s2;
   // printf("%s", s.c_str());
    printf("%s", s2.c_str());
}