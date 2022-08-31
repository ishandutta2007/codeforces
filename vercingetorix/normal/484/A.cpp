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
    int n;
    cin>>n;
    long long l,r;
    for(int i=0; i<n; i++){
        cin>>l>>r;
        int m;
        for(m=0; m<=60; m++){
            if((((r+1)>>m)<<m)<=l) break;
        }
        m--;
        long long h=r;
        if(m>=0) h= (((r+1)>>m)<<m)-1;
        /*int ans=0;
        while (h>0){
            if(h%2) ans++;
            h=h>>1;
        }*/
        cout<<h<<endl;
    }

}