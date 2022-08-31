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
int wow[(1<<9)+10][912];
int haha[123456];
vector<vi> facto(123456);
int addelem(int val){
	int i;
	haha[val]++;
	int lol=val>>8;
	rep(i,facto[val].size()){
		if(wow[lol][facto[val][i]])
			wow[lol][facto[val][i]]=min(val,wow[lol][facto[val][i]]);
		else
			wow[lol][facto[val][i]]=val;
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    int q;
    cin>>q;
    int i,j;
    f(i,1,910){
    	for(j=i;j<123456;j+=i){
    		facto[j].pb(i);
    	}
    }
    int val,t,x,k,s,ans,maxi,low,high;
    rep(i,q){
    	cin>>t;
    	if(t==1){
    		cin>>val;
    		addelem(val);
    	}
    	else{
    		cin>>x>>k>>s;
    		if(x%k!=0){
    			cout<<-1<<endl;
    			continue;
    		}
    		ans=-1;
    		maxi=-2;
    		if(k>=900){
    			val=k;
    			while(val+x<=s){
    				if(haha[val]){
    					if(maxi<(x^val)){
    						maxi=x^val;
    						ans=val;
    					}
    				}
    				val+=k;
    			}
    			cout<<ans<<endl;	
    		}
    		else{
    			int found=0;
    			fd(j,(1<<9)-1,0){
    				val=(j^(x>>8));
    				if(wow[val][k]){
    					if(wow[val][k]+x<=s){
    						found=1;
    						break;
    					}
    				}
    			}
    			if(!found){
    				cout<<-1<<endl;
    				continue;
    			}
    			j=val;
    			//cout<<wow[j][k]<<endl;
    			low=j*(1<<8);
    			high=(j+1)*(1<<8);
    			low+=(k-low%k)%k;
    			//cout<<low<<endl;
    			maxi=-2;
    			ans=-1;
    			while(low<high && low+x<=s){
    				if(haha[low]){
    					//cout<<low<<"dasds"<<endl;
    					//cout<<maxi<<endl;
    					if(maxi<(x^low)){
    						//cout<<x^
    						maxi=x^low;
    						ans=low;
    					}
    				}
    				low+=k;
    			}
    			cout<<ans<<endl;
    		}
    	}
    }
    return 0;  
    
}