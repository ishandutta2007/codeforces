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
    int n;
    scanf("%d",&n);
    vi a(n);
    int n0=0, n1=0;
    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        if(a[i]==0) n0++;
        else n1++;
    }
    if(a[n-1]==1) {
        cout<<"NO";
        return 0;
    }
    if(n0==1) {
        cout<<"YES\n";
        for(int i=0; i<n-1; i++) cout<<a[i]<<"->";
        cout<<"0";
        return 0;
    }
    if((n0==2)&&(a[n-2]==0)) {
        cout<<"NO";
        return 0;
    }
    int k=0;
    while(a[k]!=0) k++;
    cout<<"YES\n";
    for(int i=0; i<k; i++) cout<<a[i]<<"->";
    cout<<"0->(";
    for(int i=k+1; i<n-2; i++) cout<<a[i]<<"->";
    cout<<a[n-2]<<")->0";

}