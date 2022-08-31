#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include <deque>
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
#define fo(a, b, c) for(int a = b; a < c; a++)

#define pb push_back
#define mp make_pair

int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int n,q;
    //cin>>n>>q;
    scanf("%d %d\n", &n, &q);
    //for(int i=0; i<n; i++) 
    map<int, int> dir;
    map<int, int> upb;
    map<int, int> lb;
    set<int> breaks;
    breaks.insert(0);
    breaks.insert(n+1);
    upb[0]=0;
    lb[0]=0;
    fo(i,0,q) {
        int x,y;
        char c;
        //cin>>x>>y>>c;
        scanf("%d %d %c\n", &x, &y, &c);
        auto a=breaks.lower_bound(x);
        if((*a)==x) printf("0\n");
        else {
            int r=*a;
            auto b=a;
            a--;
            int l=*a;
            if(c=='U') printf("%d\n", y-upb[l]);
            else if(c=='L') printf("%d\n", x-lb[l]);
            breaks.insert(x);
            if(c=='U') {
                lb[x]=x;
                upb[x]=upb[l];
            }
            else if(c=='L') {
                upb[x]=upb[l];
                upb[l]=y;
                lb[x]=lb[l];
            }
        }
    }
}