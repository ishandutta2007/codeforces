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
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

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
    ll n, k ;
    cin>>n>>k;
    vi l(10000000, 0);
    vi f(10000000, 0);
    vi s(7,0);
    s[6]=-1;
    int ss = 1;
    int cur = 6;
    for(int i=0; i<10000000;i++) {
        
        s[cur]++;
        while(s[cur]>9) {
            s[cur] = 0;
            cur--;
            ss=max(ss, 7-cur);
            s[cur]++;
        }
        cur=6;
        if(i<10) {
            l[i]=2;
            continue;
        }
        bool flag = true;
        if(s[6]==s[5]) flag=false;
        for(int x = 8-ss; x < 6; x++) {
            if(s[x-1]<=s[x]) if(s[x]<=s[x+1]) flag = false;
            if(s[x-1]>=s[x]) if(s[x]>=s[x+1]) flag = false;
        }
        if (flag) {
            if(s[6]>s[5]) l[i]=1;
            if(s[6]<s[5]) l[i]=-1;
        }
        for(int x = 1; x < min(8-ss, 6); x++) {
            if(s[x-1]<=s[x]) if(s[x]<=s[x+1]) flag = false;
            if(s[x-1]>=s[x]) if(s[x]>=s[x+1]) flag = false;
        }
        if(!flag) continue;
        if(s[1]>s[0]) f[i] = 1;
        else f[i]=-1;
    }
//    
//    for(int i=0; i<10000000;i++) {
//        string fy = to_string(i);
//    }
    if(n>=10000000) {
        ll cnt = 0;
        ll sum = 0;
        while(1) {
            sum+=n;
            if(sum>1e14) break;
            ll yo = sum/10000000;
            ll lo = sum%(10000000);
            if(!f[lo]) continue;
            if(!l[yo]) continue;
        
            
            if ((f[lo]==l[yo])||(l[yo]==2)){
                //if(l[curl]==2){if (curl%10 != res/1000000) cnt++;}
                if (f[lo]==1) {if (yo%10 > lo/1000000) cnt++;}
                else if (f[lo]==-1) {if (yo%10 < lo/1000000) cnt++;}
            }
            if(f[lo]==2) cnt++;

            if(cnt==k) {
                cout<<sum;
                return 0;
            }
        }
        cout<<-1;
        return 0;
        
    }
    
        vector<vector<unsigned int>> num(2, vector<unsigned int>(10000000, 0));
    for(ll i= 10000000-n; i< 10000000; i++) num[0][i] = ((f[i]==-1)? 1 : 0);
    for(ll i = 9999999-n; i>=0; i--) num[0][i] = num[0][i+n] +((f[i]==-1)? 1 : 0);
    for(ll i= 10000000-n; i< 10000000; i++) num[1][i] = ((f[i]==1)? 1 : 0);
    for(ll i = 9999999-n; i>=0; i--) num[1][i] = num[1][i+n] +((f[i]==1)? 1 : 0);
    ll res = 0;
    ll cnt = 0;
    ll p10 = 10000000;
    
    while(1) {
        res+=n;
        if(res>=p10) {
            break;
        }
        if(l[res]) {cnt++; }
        if(cnt==k) {
            cout<<res;
            return 0;
        }
    }
    res-=p10;
    ll curl = 1;

    

    while (curl < p10) {
        ll reswas = res;
        ll cntwas = cnt;
        
        ll step = (p10 - res + n-1)/n;
        ll last = curl % 10;
        ll step2 =  (last*1000000 - res +n-1)/n;
        ll step3 = ((last+1)*1000000 - res +n-1)/n;
        if(res>=last*1000000) step2=0;
        if(res>=(last+1)*1000000) step3=0;
        ll per = res+n*step2;
        ll per2 = res+n*step3;
        if(!l[curl]) {
            curl++;
            res = (res + step*n) % p10;
            continue;
        }
        if(l[curl] == 2) {
            if(per2<p10) cnt+=num[0][per2];
            cnt+=num[1][res];
            if(per<p10) cnt-=num[1][per];
        }
        else if(l[curl]==-1) {
            if(per2<p10) cnt+=num[0][per2];
        }
        else if(l[curl]==1) {
            cnt+=num[1][res];
            if(per<p10) cnt-=num[1][per];
        }
        
        if(cnt>=k) {
            cnt=cntwas;
            res=reswas;
            if ((f[res]==l[curl])||(l[curl]==2)){
                if(f[res]){
                    //if(l[curl]==2) {if (curl%10 != res/1000000) {cnt++;cout<<curl*p10+res<<endl;}}
                    if (f[res]==1) {if (curl%10 > res/1000000) cnt++;}
                    else if (f[res]==-1) {if (curl%10 < res/1000000) {cnt++;}}
                }
            }
            while(1) {

                if(cnt==k) {
                    cout<<curl*p10+res;
                    return 0;
                }
                res+=n;
                if(res>=p10) {
                    res-=p10;
                    curl++;
                }
                if(!f[res]) continue;
                if(!l[curl]) continue;
                
                if ((f[res]==l[curl])||(l[curl]==2)){
                     //if(l[curl]==2){if (curl%10 != res/1000000) cnt++;}
                     if (f[res]==1) {if (curl%10 > res/1000000) cnt++;}
                     else if (f[res]==-1) {if (curl%10 < res/1000000) cnt++;}
                }
                
            }
            return 0;
            
        }
        
        curl++;
        res = (res + step*n) % p10;
    }
    cout<<-1;
}