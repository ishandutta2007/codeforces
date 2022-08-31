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
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
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
    int n, m, k;
//    cin>>n>>m;
    scanf("%d %d\n", &n, &m);
    vi a(n);
    vi b;
    for(int i=0; i<n; i++) {
  //      cin>>a[i];
        scanf("%d",&a[i]);
        if(i>0) if(a[i]!=a[i-1]) b.pb(i);
    }
    b.pb(999999);
    for(int i=0; i<m; i++) {
        int l,r,x;
//        cin>>l>>r>>x;
        scanf("%d %d %d\n", &l,&r,&x);
        l--;
        r--;
        if(a[l]!=x) {
            //cout<<l+1<<endl;
            printf("%d\n", l+1);
            continue;
        }
        else {
            int p = *lower_bound(b.begin(), b.end(), l+1);
            if (p>r) printf("-1\n");//cout<<-1<<endl;
            else printf("%d\n", p+1);//cout<<p+1<<endl;
        }
    }
   // cout<<n+m;
}