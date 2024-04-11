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
int a[104][104],row[105],col[105];
int main(){
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i,j;
    rep(i,n){
    	rep(j,m){
    		cin>>a[i][j];
    	}
    }
    int k;
    int mini=inf,sumi,flag;
    int remem=-1;
    rep(k,502){
    	flag=0;
    	sumi=0;
    	col[0]=k;
    	rep(i,n){
    		row[i]=a[i][0]-col[0];
    	}
    	rep(i,m){
    		col[i]=a[0][i]-row[0];
    	}
    	rep(i,n){
    		if(row[i]<0){
    			flag=1;
    		}
    		sumi+=row[i];
    	}
    	rep(j,m){
    		if(col[j]<0){
    			flag=1;
    		}
    		sumi+=col[j];
    	}
    	if(flag)
    		continue;

    	rep(i,n){
    		rep(j,m){
    			if(a[i][j]!=row[i]+col[j]){
    				flag=1;
    				break;
    			}
    			
    		}
    		if(flag){
    			break;
    		}
    	}
    	if(flag)
    		continue;
    	if(mini>sumi){
    		mini=sumi;
    		remem=k;
    	}
    	//cout<<<<endl;

    }
    if(mini==inf){
    	cout<<-1<<endl;
    	return 0;
    }
    	sumi=0;
    	col[0]=remem;
    	rep(i,n){
    		row[i]=a[i][0]-col[0];
    	}
    	rep(i,m){
    		col[i]=a[0][i]-row[0];
    	}
    	rep(i,n){
    		
    		sumi+=row[i];
    	}
    	rep(j,m){
    		
    		sumi+=col[j];
    	}
    	cout<<sumi<<endl;
    	rep(i,n){
    		rep(j,row[i]){
    			cout<<"row "<<i+1<<endl;
    		}
    	}
    	rep(i,m){
    		rep(j,col[i]){
    			cout<<"col "<<i+1<<endl;
    		}
    	}
    	return 0;
}