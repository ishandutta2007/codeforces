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
int n,m;
int foo[123],hero[123],stren[132],a[123];
int getansl(int i){
	int maxi=0;
	int chosen2=-1,chosen=-1;
	int j;
	rep(j,i){
		if(hero[j]){
			//maxi=max(maxi,stren[j]);
			if(maxi<stren[j]){
				maxi=stren[j];
				chosen=j;
			}
		}
		else{
			if(chosen!=-1)
				maxi+=a[j];
		}	
	}
	if(chosen==-1)
		return 0;
	cout<<foo[chosen]<<" ";
	hero[chosen]=0;
	f(j,chosen,i+1){
		a[j]=0;
	}
	getansl(i);
}

int getansr(int i){
	int maxi=0;
	int chosen2=-1,chosen=-1;
	int j;
	fd(j,n-1,i+1){
		if(hero[j]){
			//maxi=max(maxi,stren[j]);
			if(maxi<stren[j]){
				maxi=stren[j];
				chosen=j;
			}
		}
		else{
			if(chosen!=-1)
				maxi+=a[j];
		}	
	}
	if(chosen==-1)
		return 0;
	cout<<foo[chosen]<<" ";
	hero[chosen]=0;
	f(j,i,chosen+1){
		a[j]=0;
	}
	getansr(i);
	return 0;
}
int getans(int i){
	cout<<i+1<<endl;
	if(a[i]>=0){
		if(hero[i]){
			hero[i]=0;
			cout<<foo[i]<<" ";
		}
		getansl(i);
		getansr(i);
	}
	int maxi=0;
	int chosen2=-1,chosen=-1;
	int j;
	rep(j,i){
		if(hero[j]){
			//maxi=max(maxi,stren[j]);
			if(maxi<stren[j]){
				maxi=stren[j];
				chosen=j;
			}
		}
		else{
			if(chosen!=-1)
				maxi+=a[j];
		}	
	}
	
	int gg=maxi;
	maxi=0;
	fd(j,n-1,i+1){
		if(hero[j]){
			if(maxi<stren[j]){
				maxi=stren[j];
				chosen2=j;
			}
		}
		else{
			if(chosen2!=-1)
				maxi+=a[j];
		}
	}
	if(gg<=maxi && chosen2!=-1){
		cout<<foo[chosen2]<<" "; 
		hero[chosen2]=0;
		f(j,i,chosen2+1){
			a[j]=0;
		}
	}
	else if(chosen!=-1){
		cout<<foo[chosen]<<" ";
		hero[chosen]=0;
		f(j,chosen,i+1){
			a[j]=0;
		}
	}
	getansr(i);
	getansl(i);

}
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin>>n>>m;
    int i;
    int val;
    int flag=0;
    rep(i,m){
    	cin>>val;
    	val--;
    	foo[val]=i+1;
    	hero[val]=1;
    	cin>>stren[val];
    }
    rep(i,n){
    	cin>>a[i];
    }
    int maxi,j,chosen,gg;
    rep(i,n){
    	//cout<<i<<endl;
    	maxi=0;
    	flag=0;
    	chosen=-1;
    	rep(j,i){
    		if(hero[j]){
    			maxi=max(maxi,stren[j]);
    			chosen=1;
    		}
    		else{
    			if(chosen!=-1)
    				maxi+=a[j];
    		}
    		if(maxi<0){
    			flag=1;
    			break;
    		}
    	}

    	if(flag)
    		continue;
    	gg=maxi;
    	maxi=0;
    	chosen=-1;
    	fd(j,n-1,i+1){
    		if(hero[j]){
    			maxi=max(maxi,stren[j]);
    			chosen=1;
    		}
    		else{
    			if(chosen!=-1)
    				maxi+=a[j];
    		}
    		if(maxi<0){
    			flag=1;
    			break;
    		}
    	}
    	
    	if(flag)
    		continue;
    	// cout<<flag<<endl;
    	// exit(0);
    	maxi=max(maxi,gg);
    	maxi+=a[i];

    	if(maxi<0)
    		continue;

    	getans(i);
    	return 0;

    }
    cout<<-1<<endl;
    return 0;   
}