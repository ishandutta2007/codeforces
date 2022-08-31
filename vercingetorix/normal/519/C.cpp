#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
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

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,m;
    cin>>n>>m;
    if(n>=2*m) cout<<m;
    else if(m>=2*n) cout<<n;
    else cout<<(m+n)/3;

}