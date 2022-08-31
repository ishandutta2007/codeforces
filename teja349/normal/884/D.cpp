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
#define ll long long int
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
#define pdqueue priority_queue< ll,vl ,greater< ll > >

//std::ios::sync_with_stdio(false);   
ll a[223456],pre[212345];
// ll solve(int i,int j){
// 	//cout<<i<<": "<<j<<endl;
// 	if(i==j) return 0;
// 	ll sumi=0,ans=0,val=pre[j]-pre[i-1];
// 	if(j-i<=2){
// 		return pre[j]-pre[i-1];
// 	}
// 	ans=pre[j]-pre[i-1];
// 	val/=3;
// 	int k;
// 	fd(k,j,i){
// 		sumi+=a[k];
// 		if(sumi>val)
// 			break;
// 	}
// 	if(k!=j)
// 		k++;
// 	ans+=solve(k,j);
// 	k--;
// 	val=pre[k]-pre[i-1];
// 	val/=2;
// 	sumi=0;
// 	fd(j,k,i){
// 		sumi+=a[j];
// 		if(sumi>val)
// 			break;
// 	}
// 	if(j!=k)
// 	j++;
// 	ans+=solve(j,k);
// 	ans+=solve(i,j-1);
// 	return ans;

// }
pdqueue pq;
int main(){
    std::ios::sync_with_stdio(false);
    ll i, n;
    cin>>n;
    //ll sumi=0,ans=0;

   	f(i,1,n+1){
    	cin>>a[i];
    	//sumi+=a[i];
    	pq.push(a[i]);
    }
    int j=1,haha=1;
    if(n%2==0)
    	pq.push(0);
   
    ll val1,val2,val3,previ=-1,ans=0;
    while(pq.size()!=1){
    	val1=pq.top();
    	pq.pop();
    	val2=pq.top();
    	pq.pop();
    	ans+=val1+val2;
    	
    	val3=pq.top();
    	pq.pop();
    	
    	ans+=val3;
    	val1+=val2+val3;
    	//cout<<val1<<endl;
    	pq.push(val1);
    }
    cout<<ans<<endl;
    //sort(a,a+n);
   	
    
}