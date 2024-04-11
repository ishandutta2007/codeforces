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
map<string,int> mapi;
map<int,string> inv;
vector<vi> vec(100);
int a[12],haha[12];
int ans[123456];
int main(){
    std::ios::sync_with_stdio(false);
    int i;
    rep(i,6){
        cin>>a[i];
    }

    mapi["S"]=0;
    mapi[ "M"]=1;
    mapi[ "L"]=2;
    mapi[ "XL"]=3;
    mapi[ "XXL"]=4;
    mapi[ "XXXL"]=5;
    int n;
    cin>>n;
    map<string,int>::iterator it;
    for(it=mapi.begin();it!=mapi.end();it++){
        inv[it->ss]=it->ff;
    }
    string s,str;
    int val,j,flag,val1;
    rep(j,n){
        cin>>s;
        val=s.find(',');
        str="";
        f(i,val+1,s.length()){
            str+=s[i];
        }
        val1=mapi[str];
        flag=0;
        str="";
        rep(i,val){
            flag=1;
            str+=s[i];
        }

        if(flag){
            val1=min(val1,mapi[str]);
            haha[val1]++;
            vec[val1].pb(j);
        }
        else{
            if(!a[val1]){
                cout<<"NO"<<endl;
                return 0;
            }
            //cout<<j<<" "<<val1<<endl;
            a[val1]--;
            ans[j]=val1;
        }

    }
    rep(i,5){
        //cout<<i<<" "<<haha[i]<<endl;
        j=0;
        while(haha[i]>0){
            if(a[i]>0){
                ans[vec[i][j]]=i;
                a[i]--;
            }
            else if(a[i+1]){
                ans[vec[i][j]]=i+1;
                a[i+1]--;
            }
            else{
                cout<<"NO"<<endl;
                return 0;
            }
            haha[i]--;
            j++;
        }
    }
    cout<<"YES"<<endl;
    rep(i,n){
        cout<<inv[ans[i]]<<endl;
    }
    return 0;  
    
}