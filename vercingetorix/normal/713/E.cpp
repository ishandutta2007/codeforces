#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int num,n;
    scanf("%d\n", &num);
    scanf("%d\n", &n);
    vi a(n);
    forn(i,0,n) scanf("%d", &a[i]);
    for(int i = n-1; i>=0; i--) a[i] = a[i]-a[0];
    if(n==num) {
        cout<<0;
        return 0;
    }
    if(n==1) {
        cout<<num-1;
        return 0;
    }
    if(n==2) {
        int x = a[1]-a[0];
        int y = num+a[0]-a[1];
        if(x==1 || y == 1) {
            int gap = x+y-1;
            cout<<gap/2;
        }
        else {
            cout<<min(max(x,y)-1, min(x,y) + (max(x,y))/2);
        }
        return 0;
    }
    int l = 0;
    int r = num;
    while(r-l > 1) {
        int m = (r+l)/2;
        int p = 1;
        int reach = m;
        int bonus = 0;
        if(n>2) {
            if(a[2] <= m+1) bonus = m-a[1];
        }
        
        bool f = false;
        while(p<n) {
            if(a[p] <= reach + 1) {
                reach = a[p] + m;
                p++;
            }
            else {
                int rp = p;
                while(rp < n && a[rp] -reach <= m+1) rp++;
                rp--;
                if(rp < p) {
                    f = false;
                    break;
                }
                else if(rp==p) {
                    reach=a[p];
                    p++;
                }
                else if(rp ==p+1) {
                    if(a[p+1]-a[p]==1) {
                        reach=a[p+1]+m;
                        p+=2;
                    }
                    else {
                        reach=a[p]+m;
                        p+=2;
                    }
                }
                else {
                    reach=a[rp] + m;
                    p = rp+1;
                }
            }
        }
        if(reach >= num-1-bonus) f=true;
        if(f) r= m;
        else {
            
            int reach = m;
            int bonus = m-a[1];
            p = 2;
            while(p<n) {
                if(a[p] <= reach + 1) {
                    reach = a[p] + m;
                    p++;
                }
                else {
                    int rp = p;
                    while(rp < n && a[rp] -reach <= m+1) rp++;
                    rp--;
                    if(rp < p) {
                        f = false;
                        break;
                    }
                    else if(rp==p) {
                        reach=a[p];
                        p++;
                    }
                    else if(rp ==p+1) {
                        if(a[p+1]-a[p]==1) {
                            reach=a[p+1]+m;
                            p+=2;
                        }
                        else {
                            reach=a[p]+m;
                            p+=2;
                        }
                    }
                    else {
                        reach=a[rp] + m;
                        p = rp+1;
                    }
                }
            }
            if(reach >= num-1-bonus) f=true;
            if(f) r= m;
            else l =m;
        }
        
    }
    int ans = r;
    
    
    vi b;
    b.pb(0);
    for(int i = n-1; i>0; i--) b.pb(num-a[i]);
    a=b;
    l = 0;
    r = num;
    while(r-l > 1) {
        int m = (r+l)/2;
        int p = 1;
        int reach = m;
        int bonus = 0;
        if(n>2) {
            if(a[2] <= m+1) bonus = m-a[1];
        }
        bool f = false;
        while(p<n) {
            if(a[p] <= reach + 1) {
                reach = a[p] + m;
                p++;
            }
            else {
                int rp = p;
                while(rp < n && a[rp] -reach <= m+1) rp++;
                rp--;
                if(rp < p) {
                    f = false;
                    break;
                }
                else if(rp==p) {
                    reach=a[p];
                    p++;
                }
                else if(rp ==p+1) {
                    if(a[p+1]-a[p]==1) {
                        reach=a[p+1]+m;
                        p+=2;
                    }
                    else {
                        reach=a[p]+m;
                        p+=2;
                    }
                }
                else {
                    reach=a[rp] + m;
                    p = rp+1;
                }
            }
        }
        if(reach >= num-1-bonus) f=true;
        if(f) r= m;
        else {
            
            int reach = m;
            int bonus = m-a[1];
            p = 2;
            while(p<n) {
                if(a[p] <= reach + 1) {
                    reach = a[p] + m;
                    p++;
                }
                else {
                    int rp = p;
                    while(rp < n && a[rp] -reach <= m+1) rp++;
                    rp--;
                    if(rp < p) {
                        f = false;
                        break;
                    }
                    else if(rp==p) {
                        reach=a[p];
                        p++;
                    }
                    else if(rp ==p+1) {
                        if(a[p+1]-a[p]==1) {
                            reach=a[p+1]+m;
                            p+=2;
                        }
                        else {
                            reach=a[p]+m;
                            p+=2;
                        }
                    }
                    else {
                        reach=a[rp] + m;
                        p = rp+1;
                    }
                }
            }
            if(reach >= num-1-bonus) f=true;
            if(f) r= m;
            else l =m;
        }
    }
    ans = min(ans,r);
    cout<<ans;
    
}