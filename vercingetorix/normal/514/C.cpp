#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <stdio.h>
#include <sstream>
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

/*int xmin[2000][500];
int xmax[2000][500];
int num[2000][500];*/
int mindels[2][2001];
string s,p;
ll mod = 100000000000001;
int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,m;
    cin>>n>>m;
    vector<map<ll, int> > hasht (600003);
    string s;
    for(int i=0; i<n; i++) {
        cin>>s;
        int k = s.length();
        ll hash = 0;
        for(int j=0; j<k; j++) {
            hash*=3;
            hash+=s[j]-'a';
            hash=hash%mod;
        }
        hasht[k][hash]++;
    }
    for(int i=0; i<m; i++) {
        cin>>s;
        int k = s.length();
        ll hash = 0;
        for(int j=0; j<k; j++) {
            hash*=3;
            hash+=s[j]-'a';
            hash=hash%mod;
        }
        ll p3 = 1;
        int deg = 0;
        ll newhash;
        bool f=false;
        for(int j=k-1; j>=0; j--) {
            if(f) break;
            for(char c = 'a'; c <= 'c'; c++) {
                if (s[j]!=c) {
                    newhash = (hash + p3*(c-s[j]) + 3*mod) % mod;
                    if (hasht[k][newhash] > 0) f = true;
                }
            }
            deg++;
            p3 = (p3*3)%mod;
        }
        cout << (f? "YES" : "NO") <<endl;
    }

}