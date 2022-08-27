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
    string s;
    cin>>s;
    int l=s.length();
    for(int i=0; i<l; i++) {
        int a=s[i]-'0';
        int n=a;
        if(n%8==0) {
            cout<<"YES\n";
            cout<<n;
            return 0;
        }
        for(int j=i+1; j<l; j++) {
            int a=s[i]-'0';
            int b=s[j]-'0';
            int n=10*a+b;
            if(n%8==0) {
                cout<<"YES\n";
                cout<<n;
                return 0;
            }
            for(int k=j+1; k<l; k++) {
                int a=s[i]-'0';
                int b=s[j]-'0';
                int c=s[k]-'0';
                int n=100*a+10*b+c;
                if(n%8==0) {
                    cout<<"YES\n";
                    cout<<n;
                    return 0;
                }
            }
        }
    }
cout<<"NO";
}