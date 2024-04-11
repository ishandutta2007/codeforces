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
    ll n,m;
   // int ans = 0;
    cin>>n;
    vi a(n);
    map<int, int> num;
    for(int i =0; i<n; i++) {
        cin>>a[i];
        num[a[i]]++;
    }
    map<pi, int> u;
    int  ans = 0;
    for(int i =0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            bool flag = false;
            map<int, int> numU;
            deque<int> au;
            if(i==j) continue;
            int pot = 1;
            vpi done;
            int f = a[i];
            int h = a[j];
            
            if(u[mp(f,h)]>0) continue;
            au.pb(f);
            num[f]--;
            numU[f]++;
            while(num[h]+numU[h]>0) {
                while (num[h]>0){
                    //done.pb(mp(f,h));
                    num[h]--;
                    numU[h]++;
                    au.pb(h);
                    ans = max(ans, (int) au.size());
                    pot++;
                    h=h+f;
                    f=h-f;
                }
                if (numU[h] == 0) break;
                while(au.size()>1) {
                    int c = au[0];
                    if(u[mp(c, au[1])] > 0) {
                        flag = true;
                        break;
                    }
                    u[mp(c, au[1])] = 1;
                    num[c]++;
                    numU[c]--;
                    au.pop_front();
                    if(c==h) break;
                }
                if(au.size()==1) break;
                if (flag) break;
            }
            while(au.size()>1) {
                u[mp(au[0], au[1])] = 1;
                num[au[0]]++;
                au.pop_front();
            }
            num[au[0]]++;
        }
    }
    
    cout<<ans;
}