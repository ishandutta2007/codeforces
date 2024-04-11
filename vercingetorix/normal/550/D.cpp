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
    int k;
    cin>>k;
    if(k%2==0) {
        cout<<"NO";
        return 0;
    }
    int l=k/2;
    cout<<"YES"<<endl;
    if(k==1) {
        cout<<"2 1\n"<<"1 2";
        return 0;
    }
    cout<<(2*k+4)<<" "<<(k*(k+2))<<endl;
    for(int i=1; i<=2*l+2; i++) {
        for(int j=i+1; j<=2*l+2; j++) {
            if(((j%2)==0)&&(j<=2*l)&&(j==(i+1))) continue;
            cout<<i<<" "<<j<<endl;
            cout<<2*k+5-i<<" "<<2*k+5-j<<endl;
        }
        if(i>2*l) continue;
        cout<<i<<" "<<k+2<<endl;
        cout<<2*k+5-i<<" "<<k+3<<endl;
    }
    cout<<k+2<<" "<<k+3<<endl;
        
}