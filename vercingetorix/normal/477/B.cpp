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
    cout<<k*(6*n-1)<<endl;
    for(int i=0; i<n; i++){
        cout<<(6*i+1)*k<<" "<<(6*i+2)*k<<" "<<(6*i+3)*k<<" "<<(6*i+5)*k<<endl;
    }
    
}