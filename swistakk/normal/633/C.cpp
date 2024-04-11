//SohiebMohamed's code
// Trying to figure out what happened there

#include <bits/stdc++.h>
#include <ext/numeric>
using namespace std;
using namespace __gnu_cxx;

#define all(x)          x.begin(),x.end()
#define rall(x)         x.rbegin(),x.rend()
#define sz(x)           (int)x.size()
#define ll                      long long
#define ld                      long long double
#define popCnt(x)   __builtin_popcount(x)
#define oo                      1e9
#define OO                      1e18
#define EPS                     1e-7
#define f                       first
#define s                       second
#define pi                      acos(-1.0)

int n,m;
string str;
string arr[100100];
unordered_map<int,int> hashVal;
int mod=1e9+9;
const int base = (srand(time(0)), 128 + rand() % 200);

pair<int,int> dp[10100];

pair<int,int> solve(int cur){
        if(cur==sz(str))return {1,0};
        if(cur>sz(str))return {0,0};
        pair<int,int> &ret=dp[cur];
        if(ret.first!=-1)return ret;
        ret={0,0};
        long long int h=0;
        pair<int,int> res;
        for(int i=0;i<1000&&i+cur<sz(str);i++){
                h=(h*base+str[cur+i])%mod;
                if(hashVal.count(h)==0)continue;
                res=solve(cur+i+1);
                if(res.first==1)return ret={1,hashVal[h]};
        }
        return ret;
}

int main() {
  cerr<<base<<endl;
        scanf("%d",&n);
        cin.ignore();
        getline(cin,str);
        scanf("%d",&m);
        cin.ignore();
        for(int i=1;i<=m;i++){
                getline(cin,arr[i]);
                reverse(all(arr[i]));
                long long int v=0;
                for(int j=0;j<sz(arr[i]);j++)
                        v=(v*base+tolower(arr[i][j]))%mod;
                hashVal[v]=i;
        }
        memset(dp,-1,sizeof dp);
        pair<int,int> ans=solve(0);
        int cur=0;
        while(ans.first>0){
                string tmp=arr[ans.s];
                reverse(all(tmp));
                cout<<tmp<<" ";
                cur+=sz(tmp);
                ans=dp[cur];
        }
}