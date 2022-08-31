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
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define int ll
multiset<pll> setl,setr;
multiset<pll>::iterator it1,it2,it;
int l[123456],r[123456];
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    int i;
    rep(i,n){
    	cin>>l[i]>>r[i];
    	if(l[i]>=r[i]){
    		setl.insert(mp(l[i],r[i]));
    	}
    	else{
    		setr.insert(mp(r[i],l[i]));
    	}
    }
    ll ans=0;
    pll wow;
    while(1){
    	if(setl.empty()){
    		for(it=setr.begin();it!=setr.end();it++){
    			ans+=max(it->ff,it->ss);
    		}
    		setr.clear();
    		break;
    	}
    	if(setr.empty()){
    		for(it=setl.begin();it!=setl.end();it++){
    			ans+=max(it->ff,it->ss);
    		}	
    		setl.clear();
    		break;
    	}
    	it1=setl.end();
    	it1--;
    	it2=setr.end();
    	it2--;
    	if(it1->ff>=it2->ff){
    		ans+=it1->ff;
    		if(it1->ss > it2->ff){
    			setl.erase(it1);
    		}
    		else{
    			wow=mp(it2->ss,it1->ss);
    			setl.erase(it1);
    			setr.erase(it2);
    			if(wow.ff>=wow.ss){
    				setl.insert(wow);
    			}
    			else{
    				swap(wow.ff,wow.ss);
    				setr.insert(wow);
    			}

    		}
    	}
    	else{
    		ans+=it2->ff;
    		if(it2->ss > it1->ff){
    			setr.erase(it2);
    		}
    		else{
    			wow=mp(it2->ss,it1->ss);
    			setl.erase(it1);
    			setr.erase(it2);
    			if(wow.ff>=wow.ss){
    				setl.insert(wow);
    			}
    			else{
    				swap(wow.ff,wow.ss);
    				setr.insert(wow);
    			}
    		}
    	}

    }
    cout<<ans+n<<endl;


    return 0;   
}