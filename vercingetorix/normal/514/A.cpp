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
    int ans=0;
    string s;
    cin>>s;
    int n=s.length();
    bool f=false;
    if ((s[0]>='5') && (s[0]<='8')) s[0]='0'+('9'-s[0]);
    for(int i=1; i<n; i++) {
        if (s[i]>='5') s[i]='0'+('9'-s[i]);
    }
    cout<<s;

}