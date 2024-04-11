//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

//std::ios::sync_with_stdio(false);  
int odda[212345],oddb[212345],evenb[212345],evena[212345],ques[212345];
string s;
int m,n; 
int check(int pos){
    int sumi=0;
    if(pos%2){
        sumi+=odda[pos+m-1]-odda[pos-1];
        sumi+=evenb[pos+m-1]-evenb[pos];
    }
    else{
        sumi+=evena[pos+m-1];
        if(pos!=0){
            sumi-=evena[pos-1];
        }
        sumi+=oddb[pos+m-1]-oddb[pos];
    }
    //cout<<evena[pos+m-1]<<" "<<pos+m-1<<endl;
    if(sumi!=m){
        return -1;
    }
    else{
        sumi=ques[pos+m-1];
        if(pos!=0){
            sumi-=ques[pos-1];
        }
        return sumi;
    }
}
pii dp[212345];
int visit[212345];
pii compute(int pos){
    pii papa;
    if(visit[pos]==1){
        return dp[pos];
    }
    visit[pos]=1;
    if(pos+m>n){
       // visit[pos]=1;
        papa=mp(0,0);
        return papa;
    }

    dp[pos]=compute(pos+1);
    int val=check(pos);
    if(check(pos)==-1){
        return dp[pos];
    }
    else{
        papa=compute(pos+m);
        papa.ff++;
        papa.ss-=val;
        dp[pos]=max(dp[pos],papa);
        return dp[pos];
    }

}
int main(){
    std::ios::sync_with_stdio(false);
    cin>>n;
    cin>>s;
    int i;
    rep(i,s.length()){
        if(i%2){
            if(s[i]=='?'){
                ques[i]++;
                odda[i]++;
                oddb[i]++;
            }
            else if(s[i]=='a'){
                odda[i]++;
            }
            else{
                oddb[i]++;
            }
        }
        else{
            if(s[i]=='?'){
                ques[i]++;
                evena[i]++;
                evenb[i]++;
            }
            else if(s[i]=='a'){
                evena[i]++;
            }
            else{
                evenb[i]++;
            }
        }
    }
    f(i,1,n){
        ques[i]+=ques[i-1];
        oddb[i]+=oddb[i-1];
        odda[i]+=odda[i-1];
        evenb[i]+=evenb[i-1];
        evena[i]+=evena[i-1];
        //cout<<evena[i]<<" "<<i<<endl;
    }
    cin>>m;
    //cout<<check(4)<<endl;
    //return 0;
    pii papa=compute(0);
    //cout<<papa.ff<<endl;
    cout<<-1*papa.ss<<endl;
    return 0;  
    
}