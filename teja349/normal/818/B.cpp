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
int l[1234];
set<int> seti,newq;
set<int>::iterator it;
int a[1234];
int main(){
    std::ios::sync_with_stdio(false);
     int n,m;
     cin>>n>>m;
     int i;
     rep(i,m){
     	cin>>l[i];
     }
     rep(i,m-1){
     	if(!a[l[i]])
     		a[l[i]]=l[i+1]-l[i];
     	else{
     		if(a[l[i]]!=l[i+1]-l[i] && a[l[i]]!=l[i+1]-l[i]+n){
     			cout<<-1<<endl;
     			return 0;
     		}
     	}
     	if(a[l[i]]<=0) 
     		a[l[i]]+=n;
     }
     f(i,1,n+1){
     	if(a[i]){
     		if(seti.find(a[i])==seti.end())
     			seti.insert(a[i]);
     		else{
     			cout<<-1<<endl;
     			return 0;
     		}
     	}
     	newq.insert(i);


     }
     for(it=seti.begin();it!=seti.end();it++){
     	newq.erase(*it);
     }
     f(i,1,n+1){
     	if(!a[i]){
     		a[i]=*newq.begin();
     		it=newq.begin();
     		newq.erase(it);
     	}
     	cout<<a[i]<<" ";
     }
     return 0;
    
}