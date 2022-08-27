#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <deque>
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

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,m;
    cin>>n>>m;
    int curd, curh;
    int maxh;
    cin>>curd>>curh;
    maxh=curh+curd-1;
    for(int i=0; i<m-1; i++){
        int newd, newh;
        cin>>newd>>newh;
        if(abs(newh-curh)>newd-curd) {
            cout<<"IMPOSSIBLE";
            return 0;
        }
        int fd=newd-curd-abs(newh-curh);
        int newmaxh = max(curh, newh) + fd/2;
        if(newmaxh>maxh) maxh=newmaxh;
        curd=newd;
        curh=newh;
    }
    maxh=max(maxh, curh+n-curd);

    cout<<maxh;
}