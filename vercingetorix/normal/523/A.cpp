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
    int h,w;
    char c;
    cin>>w>>h;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin>>data[i][j];
        }
    }
    for(int j=0; j<2*w; j++) {
        for(int i=0; i<2*h; i++) {
            cout<<data[i/2][j/2];
        }
        cout<<endl;
    }

}