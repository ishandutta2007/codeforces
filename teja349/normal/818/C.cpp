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
int lef[123456],rig[123456],dow[123456],top[123456],visit[123456];
vector< map<int,int> > arr(123456),dee(123456);

int main(){
    std::ios::sync_with_stdio(false);
     
    int d;
    cin>>d;
    int n,m,i,j,x,y;
    map<int,int>::iterator it;
    cin>>n>>m;
    f(i,1,d+1){
    	cin>>x>>y;
    	arr[x][y]=i;
    	dee[y][x]=i;
    	cin>>x>>y;

    	arr[x][y]=i;
    	dee[y][x]=i;
    }
    f(i,1,d+1){
    	visit[i]=0;
    }
    //return 0;
    int ans=0,newans=0;
    rep(i,n+1){
    	ans=newans;
    	for(it=arr[i].begin();it!=arr[i].end();it++){
    		if(i!=1 && arr[i-1].find(it->ff)!=arr[i-1].end() && arr[i-1][it->ff]==it->ss){
    			//lef[it->ss]--;
    			//newans--;
    			lef[it->ss]=ans-1;
    		}
    		else{
    			if(!visit[it->ss])
    				newans++;
    			visit[it->ss]=1;
    			//newans++;
    			lef[it->ss]=ans;
    			//cout<<i<<"     "<<ans<<endl;
    		}
    		
    		
    	}

    }

    f(i,1,d+1){
    	visit[i]=0;
    }
    //cout<<ans<<endl;
    ans=0;
    newans=0;
     fd(i,n,0){
     	ans=newans;
    	for(it=arr[i].begin();it!=arr[i].end();it++){
    		if(i!=n && arr[i+1].find(it->ff)!=arr[i+1].end() &&arr[i+1][it->ff]==it->ss){
    			rig[it->ss]=ans-1;
    		}
    		else{
    			if(!visit[it->ss])
    				newans++;
    			visit[it->ss]=1;
    		rig[it->ss]=ans;
    		//cout<<i<<"  dsd   "<<ans<<endl;
    		}
    	}

    }
    f(i,1,d+1){
    	visit[i]=0;
    }
    //cout<<ans<<endl;
   // return 0;
    ans=0;
    newans=0;
    rep(i,m+1){
    	ans=newans;
    	for(it=dee[i].begin();it!=dee[i].end();it++){
    		if(i!=1 && dee[i-1].find(it->ff)!=dee[i-1].end() && dee[i-1][it->ff]==it->ss){
    			top[it->ss]=ans-1;
    		}
    		else{
    			if(!visit[it->ss])
    				newans++;
    			visit[it->ss]=1;
    			//newans++;
    			top[it->ss]=ans;
    		}
    	}

    }
    f(i,1,d+1){
    	visit[i]=0;
    }
    ans=0;
    newans=0;
     fd(i,m,0){
     	ans=newans;
    	for(it=dee[i].begin();it!=dee[i].end();it++){
    		if(i!=m && dee[i+1].find(it->ff)!=dee[i+1].end() && dee[i+1][it->ff]==it->ss){
    			dow[it->ss]=ans-1;
    		}
    		else{
    			if(!visit[it->ss])
    				newans++;
    			visit[it->ss]=1;
    			//newans++;
    		dow[it->ss]=ans;
    		//cout<<i<<" "<<ans<<endl;
    		}
    		
    	}

    }
    int cl,cr,cb,ct;
    cin>>cl>>cr>>ct>>cb;
    ans=0;
    f(i,1,d+1){
    	//cout<<lef[i]<<" "<<rig[i]<<" "<<top[i]<<" "<<dow[i]<<endl;
    	if(lef[i]==cl && rig[i]==cr && top[i]==ct && dow[i]==cb){
    		cout<<i<<endl;
    		return 0;
    	}
    }
    cout<<-1<<endl;

}