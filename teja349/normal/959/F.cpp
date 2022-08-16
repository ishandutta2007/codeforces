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
struct foo{
	int l,x,ind;
}  ; 
foo total[123456];
int comp(foo a,foo b){
	return a.l<b.l;
}
ll a[123456];
ll basis[123],cnt=0;
int addit(int val){
	int i=19;
	while(i>=0){
		if(basis[i]){
			if(val&(1<<i))
				val^=basis[i];
		}
		else{
			if(val&(1<<i)){
				basis[i]=val;
				return 0;
			}
		}
		i--;
	}
	cnt++;
}
int check(int val){
	int i=19;
	while(i>=0){
		if(val&(1<<i)){
			if(basis[i]){
				val^=basis[i];
			}
			else
				return 0;
		}
		i--;
	}
	return 1;
}
ll two[123456],wow[123456];
int main(){
    std::ios::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    int i;
    rep(i,n){
    	cin>>a[i];
    }
    ll ans;
    rep(i,q){
    	cin>>total[i].l>>total[i].x;
    	total[i].l--;
    	total[i].ind=i;

    }
    two[0]=1;
    f(i,1,123456){
    	two[i]=two[i-1]*2;
    	two[i]%=mod;
    }
    sort(total,total+q,comp);
    int j=0;
    rep(i,n){
    	addit(a[i]);
    	while(j<q && total[j].l==i){
    		ans=two[cnt];
    		ans*=check(total[j].x);
    		wow[total[j].ind]=ans;
    		j++;
    	}

    }
    rep(i,q){
    	cout<<wow[i]<<endl;
    }
    return 0;  
    
}