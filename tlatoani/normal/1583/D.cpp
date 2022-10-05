// 3

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include "bits/stdc++.h"
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
//#define mp make_pair
#define forstl(i,v) for(auto &i: v)
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define print(x) cout<<x<<endl
 
#define testcase(t) int t;cin>>t;while(t--)
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> p64;
typedef pair<int, int> p32;
typedef pair<int, p32> p96;
typedef vector<ll> vll;
typedef vector<int> v32;
typedef vector<v32> vv32;
typedef vector<vll> vvll;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int, int> m32;
 
const ll LIM = 2e5 + 5, MOD = 1e9 + 7;
const ld EPS = 1e-9;
 
void bandev() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void printArr(vll nw) {
    for (ll i = 0; i < nw.size(); i++){
        cout << nw[i]<<" ";
    }
    cout << endl;
}

void printMat(vvll mat) {
    for (ll i = 0 ; i < mat.size() ; i++) {
        for (ll j = 0; j < mat[i].size() ; j++) {
            printf("%d ", int(mat[i][j]));
        }
        printf("\n");
    }
}

bool sortNames(const p64 a, const p64 b){
    if(b.first!=a.first) return b.first>a.first;
    return b.second>a.second;
}
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool sortNamesFir(const p64 a, const p64 b){
    if(b.first!=a.first) return b.first>a.first;
    return b.second>a.second;
}

vll nw;

ll retAns(vll& ad){
    map<ll, bool> mp;
    for(ll i=nw.size()-1; i>=0; i--){
       // cout<<nw[i]+ad[i]<<" ";
        if(mp.find(nw[i]+ad[i])!=mp.end()) return i+1;
        mp[nw[i]+ad[i]] = true;
    }
    return 0;
}
ll askQuery(vll& ad) {
    cout << "? ";
    printArr(ad);
    ll inp;
    cin>>inp;
   return inp;
   // return retAns(ad);
}
void finalQuery(vll& k) {
    cout << "! ";
    printArr(k);
}

void run_case(ll t){
    ll n;
    cin>>n;
    vll ans(n, 0), vec(n, 0);
    //nw = vec;
    //for(ll i=0; i<n; i++){
      //  cin>>nw[i];
    //}
    vll mw(n, 1);
    for(mw[n-1] = n; mw[n-1] > 1; mw[n-1]--){
        if(askQuery(mw)!=0){
            ans[n-1] =n+1-mw[n-1];
            break;
        }
    }
    if(ans[n-1]==0){
        ans[n-1] = n;
    }
    for(ll i=1; i<=n; i++){
        for(ll j=0; j<n-1; j++){
            mw[j] = i;
        }
        ll retVal = askQuery(mw);
        ans[retVal-1] = n+1-i;
    }
    finalQuery(ans);
}

// void run_case(ll t){
//     ll n;
//     cin>>n;
//     vll vec(n, 0), ans(n, 1);
//     nw = vec;
//     for(ll i=0; i<n; i++){
//         cin>>nw[i];
//     }
//     vll mw(n, 1);
//     // ll zInd = 0;
//     // for(ll i=0; i<n; i++){
//     //     mw[i]=1;
//     //     ll retVal = askQuery(mw);
//     //     if(retVal == 0){
//     //         zInd = i;
//     //         break;
//     //     }
//     //     mw[i]=2;
//     //     // cout<<retVal<<" arr: ";
//     //     // printArr(ans);
//     // }
//     // print(zInd);
//     // for(ll i=0; i<n; i++){

//     // }
//     ll num = 0;
//     for(ll i=0; i<n; i++){
//         ans[i]+=num;
//         mw[i]+=1;
//         ll retVal = askQuery(mw);
//         if(retVal == 0){}
//         else if(retVal-1!=i){
//             ans[retVal-1] = ans[i]+1;
//         }
//         else{
//             num--;
//         }
//         mw[i]-=1;
//         cout<<retVal<<" arr: ";
//         printArr(ans);
//     }
//     for(ll i=0; i<n; i++){
//         mw[i] = 2;
//     }
//     num = 0;
//     for(ll i=0; i<n; i++){
//         ans[i]+=num;
//         mw[i]-=1;
//         ll retVal = askQuery(mw);
//         if(retVal == 0){}
//         else if(retVal-1!=i){
//             ans[i]= ans[retVal-1]+1;
//         }
//         else{
//             num--;
//         }
//         mw[i]+=1;
//         cout<<retVal<<" arr: ";
//         printArr(ans);
//     }
//     ll mn = INT_MAX;
//     for(ll i=0; i<n; i++){
//         mn = min(mn, ans[i]);
//     }
//     for(ll i=0; i<n; i++){
//         ans[i]-=mn;
//         ans[i]++;
//     }
//     printArr(ans);
//     // vll mww(n, 2);
//     // for(ll i=0; i<n; i++){
//     //     mww[i]-=1;
//     //     ll retVal = askQuery(mww);
//     //     if(retVal > 0 && retVal-1!=i){
//     //         ans[i] = ans[retVal-1] + 1;
//     //     }
//     //     mww[i]+=1;
//     //     cout<<retVal<<" arr: ";
//     //     printArr(ans);
//     // }
// }
int main(){
    ll t=1;
    //cin>>t;
    for(ll i=0; i<t; i++){
        run_case(i+1);
    }
    return 0;
}