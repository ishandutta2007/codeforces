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

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

char data[100][100];

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int ans = 0;
    int n;
    int inte = 0;
    double minus = 0;;
    cin >> n;
    vector<double> a(2*n);
    for(int i=0; i<2*n; i++) {
        cin>>a[i];
        double an = a[i] - floor(a[i]+0.000001);
        if (an<0.00001) inte++;
        minus+=an;
    }
    while (inte > n) {
        inte -= 2;
        n--;
    }
    minus -= (double)n;
    while ((minus < -0.5) && (inte > 0)) {
        minus+=1.;
        inte--;
    }
    printf("%.3f", abs(minus));

}