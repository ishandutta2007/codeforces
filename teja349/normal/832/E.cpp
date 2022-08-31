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
int n,m;
int a[510][510];
int haha[510];
int inv[122]; 
int lol=0;
int where[510];

int dogauss(){
	int i,j;
	int rows,cols,sel,val1;
	rep(i,m){
		where[i]=-1;
	}
	for(rows=0,cols=0;rows<n && cols<m;cols++){
		sel=rows;
		f(i,rows,n){
			if(a[i][cols]){
				sel=i;
				break;
			}
		}

		
		//sel=i;
		if(!a[sel][cols]){
			//rank++;
			continue;
		}
		
	    //cout<<rows<<"======="<<endl;
		//cout<<rows<<"ddasd"<<endl;
		rep(i,m){
			swap(a[sel][i],a[rows][i]);
		}
		int val=inv[a[rows][cols]];
		//cout<<sel<<endl;
		rep(i,m){
			a[rows][i]*=val;
			a[rows][i]%=5;
		}
		f(i,rows+1,n){
			val1=a[i][cols];
			rep(j,m){
				a[i][j]-=val1*a[rows][j];
				a[i][j]%=5;
				if(a[i][j]<0)
					a[i][j]+=5;
			}

		}
		where[cols]=rows;
		rows++;
	}
	rep(i,m){
		if(where[i]==-1)
			lol++;
	}
	lol=m-lol;
	lol=n-lol;
	return 0;
}
int fitguass(){
	int i,val,foo,j;
	rep(i,m){
		if(where[i]==-1 && haha[i]!=0){
			//cout<<i<<endl;
			return 0;
		}
		else if(where[i]==-1){
			continue;
		}

		val=where[i];
		foo=haha[i];
		f(j,i,m){
			haha[j]-=a[val][j]*foo;
			haha[j]%=5;
			if(haha[j]<0)haha[j]+=5;
			//cout<<haha[j]<<endl;
		}
	}
	return 1;
}
int main(){
    std::ios::sync_with_stdio(false);
    

    cin>>n>>m;
    int i,j;
    string str;
    f(i,1,5){
    	inv[i]=i*i*i;
    	inv[i]%=5;
    }
    rep(i,n){
    	cin>>str;
    	rep(j,m){
    		a[i][j]=str[j]-'a';
    	}    	
    }
    dogauss();
    ll ans=1;
    rep(i,lol){
    	ans*=5;
    	ans%=mod;
    }
    int q;
    cin>>q;
    
   //cout<<lol<<endl;
    while(q--){
    	string s;
    	cin>>s;
    	rep(i,m){
    		haha[i]=s[i]-'a';
    	}
    	if(fitguass()){
    		cout<<ans<<endl;
    	}
    	else{
    		cout<<0<<endl;
    	}
    }
    return 0;  
    
}