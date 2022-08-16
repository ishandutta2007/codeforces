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
int pr[1234568];
int main(){
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i,j;
    pr[1]=1;
    for(i=2;i*i<1234567;i++){
    	if(pr[i])
    		continue;
    	for(j=i*i;j<1234567;j+=i){
    		pr[j]=1;
    	}
    }
    i=n-1;
    while(1){
    	if(!pr[i]){
    		break;
    	}
    	i++;
    }
    int tot=i;
    i++;
    while(1){
    	if(!pr[i])
    		break;
    	i++;
    }
    int oth=i;
    cout<<tot<<" "<<tot<<endl;
    rep(i,n-2){
    	cout<<i+1<<" "<<i+2<<" "<<1<<endl;
    	tot--;
    }
    cout<<n-1<<" "<<n<<" "<<tot<<endl;
    m-=(n-1);
    f(i,1,n){
    	f(j,i+2,n+1){
    		if(m==0){
    			return 0;
    		}
    		cout<<i<<" "<<j<<" "<<oth<<endl;
    		m--;
    	}
    }



    return 0;  
    
}