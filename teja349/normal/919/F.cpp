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
struct total{
	int a[6];
	
};  
bool operator <(total aa,total bb){
	int i;
	rep(i,5){
		if(aa.a[i]!=bb.a[i])
			return aa.a[i]<bb.a[i];
	}
	return 0;
} 

map<total,int> mapi;
map<int,total> invmap;
int counter=0; 

int hshit(int a,int b,int c,int d,int e){
	total haha;
	haha.a[0]=a;
	haha.a[1]=b;
	haha.a[2]=c;
	haha.a[3]=d;
	haha.a[4]=e;
	mapi[haha]=counter;
	invmap[counter]=haha;
	counter++;
	return 0;
}
set<tri> jojo;
int outdeg[500][500],dp[500][500];
vector<vii> adj(250000);
int compute(int val1,int val2){
	total haha1=invmap[val1];
	total haha2=invmap[val2];
	int c,i,j;
	set<int> seti;
	set<int>::iterator it;
	f(i,1,5){
		f(j,1,5){
			if(haha1.a[i]*haha2.a[j]){
				haha1.a[i]--;
				c=(i+j)%5;
				haha1.a[c]++;
				seti.insert(mapi[haha1]);
				
				haha1.a[c]--;
				haha1.a[i]++;
			
			}

		}
	}

	for(it=seti.begin();it!=seti.end();it++){
		adj[val2*counter+*it].pb(mp(val1,val2));
	}

	outdeg[val1][val2]=seti.size();
	jojo.insert(mp(seti.size(),mp(val1,val2)));
}
int updaterest(int i,int j){
	int k,val=i*counter+j;
	rep(k,adj[val].size()){
		//dp[adj[val][k].ff][adj[val][k].ss]=1;
		if(!dp[adj[val][k].ff][adj[val][k].ss]){
			jojo.erase(mp(outdeg[adj[val][k].ff][adj[val][k].ss],adj[val][k]));
			outdeg[adj[val][k].ff][adj[val][k].ss]--;
			jojo.insert(mp(outdeg[adj[val][k].ff][adj[val][k].ss],adj[val][k]));
		}
	}
	return 0;
}
int propagate(int i,int j){
	int k,val=i*counter+j;
	rep(k,adj[val].size()){
		if(dp[adj[val][k].ff][adj[val][k].ss])
			continue;
		dp[adj[val][k].ff][adj[val][k].ss]=1;
			jojo.erase(mp(outdeg[adj[val][k].ff][adj[val][k].ss],adj[val][k]));
			updaterest(adj[val][k].ff,adj[val][k].ss);
	}

}
int main(){
    std::ios::sync_with_stdio(false);
    int i,j,a,c,b,d,e,left,left2,left1,left3;
    rep(a,9){
    	left=8-a;
    	rep(b,left+1){
    		left1=left-b;
    		rep(c,left1+1){
    			left2=left1-c;
    			rep(d,left2+1){
    				left3=left2-d;
    				e=left3;
    				hshit(a,b,c,d,e);
    				//cout<<a<<b<<c<<d<<e<<endl;
    				//counter++;
    			}
    		}
    	}
    }
    rep(i,counter){
    	rep(j,counter){
    		compute(i,j);
    	}
    }
    total haha,haha1;
    rep(i,counter-1){
    	rep(j,counter){
    		haha=invmap[j];
    		if(haha.a[0]==8){
    			dp[i][j]=-1;
    			jojo.erase(mp(outdeg[i][j],mp(i,j)));
    			//outdeg[i][j]=0;
    			propagate(i,j);
    		}		
    	}	
    }
    tri suso;
    while(!jojo.empty()){
    	//cout<<"dsads"<<endl;
    	suso=*jojo.begin();
    	jojo.erase(suso);
    	if(suso.ff!=0)
    		break;
    	i=suso.ss.ff;
    	j=suso.ss.ss;
    	dp[i][j]=-1;
    	propagate(i,j);
    }

    int q;
    cin>>q;
    int f,boo1,boo2,ans;
    //cout<<"dasd"<<endl;
    //return 0;
    //cout<<mapi.size()<<endl;
    while(q--){
    	//int f;
    	cin>>f;
    	rep(i,5){
    		haha.a[i]=0;
    		haha1.a[i]=0;
    	}
    	rep(i,8){
    		cin>>j;
    		haha.a[j]++;
    	}
    	rep(i,8){
    		cin>>j;
    		haha1.a[j]++;
    	}
    	boo2=mapi[haha1];
    	boo1=mapi[haha];
    	//cout<<boo2<<" "<<boo1<<endl;
    	if(f==0){
    		//cout<<f<<
    		ans=dp[boo1][boo2];
    		if(ans==0){
    			cout<<"Deal"<<endl;
    		}
    		else if(ans==1){
    			cout<<"Alice"<<endl;
    		}
    		else{
    			cout<<"Bob"<<endl;
    		}
    	}
    	else{
    		ans=dp[boo2][boo1];
    		//cout<<ans<<endl;
    		if(ans==0){
    			cout<<"Deal"<<endl;
    		}
    		else if(ans==-1){
    			cout<<"Alice"<<endl;
    		}
    		else{
    			cout<<"Bob"<<endl;
    		}
    	}
    }
    //cout<<counter<<endl;
    return 0;  
    
}