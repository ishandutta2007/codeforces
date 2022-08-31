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
vii vec1,vec2;
int n,m;
int check(int j,int k){
	int wow=1;
	int i;
	set<int> seti;
	rep(i,n){
		
		if(vec1[i].ff==vec2[j].ff && vec1[i].ss!=vec2[j].ss){
    			seti.insert(vec1[i].ff);
    			
    	}
		if(vec1[i].ff==vec2[j].ss && vec1[i].ss!=vec2[j].ff){
			seti.insert(vec1[i].ff);
		}
		if(vec1[i].ss==vec2[j].ff && vec1[i].ff!=vec2[j].ss){
			seti.insert(vec1[i].ss);
		}
		if(vec1[i].ss==vec2[j].ss && vec1[i].ff!=vec2[j].ff){
			seti.insert(vec1[i].ss);
		}
	}
	if(seti.size()==1){
		wow=1;
	}
	else{
		wow=0;
	}
	return wow;
}  

int main(){
    std::ios::sync_with_stdio(false);
    //int n,m;
    cin>>n>>m;
    int i,j,u,v;
    rep(i,n){
    	cin>>u>>v;
    	vec1.pb(mp(u,v));
    }
    rep(i,m){
    	cin>>u>>v;
    	vec2.pb(mp(u,v));
    }
    int answ=-1;
    int poss=0;
    set<int> haha;
    int val;
    rep(i,n){
    	poss=0;
    	set<int> seti;
    	rep(j,m){
    		val=-1;
    		if(vec1[i].ff==vec2[j].ff && vec1[i].ss!=vec2[j].ss){
    			poss++;
    			val=vec1[i].ff;

    			if(!check(j,i)){
    				cout<<-1<<endl;
    				return 0;
    			}
    		}
    		if(vec1[i].ff==vec2[j].ss && vec1[i].ss!=vec2[j].ff){
    			poss++;
    			val=vec1[i].ff;
    			if(!check(j,i)){
    				cout<<-1<<endl;
    				return 0;
    			}
    		}
    		if(vec1[i].ss==vec2[j].ff && vec1[i].ff!=vec2[j].ss){
    			val=vec1[i].ss;
    			poss++;
    			if(!check(j,i)){
    				cout<<-1<<endl;
    				return 0;
    			}
    		}
    		if(vec1[i].ss==vec2[j].ss && vec1[i].ff!=vec2[j].ff){
    			val=vec1[i].ss;
    			poss++;
    			if(!check(j,i)){
    				cout<<-1<<endl;
    				return 0;
    			}
    		}
    		if(val!=-1){
    			seti.insert(val);
    		}


    	}
    	if(seti.size()>1){
    		cout<<-1<<endl;
    		return 0;
    	}
    	if(seti.size()==1){
    		haha.insert(*(seti.begin()));
    	}
    }
    if(haha.size()!=1){
    	cout<<0<<endl;
    	return 0;
    }
    cout<<*(haha.begin())<<endl;
    return 0;  
    
}