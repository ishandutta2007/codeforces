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
int n;
int a[212345],b[212345],haha[212345],lol[212345];
int bit[212345];

int update(int pos,int val){
	//cout<<pos<<" "<<val<<endl;
	//return 0;
	while(pos<n+10){
		bit[pos]+=val;
		pos+=pos&(-pos);
	}
	return 0;
}
int query(int pos){
	//cout<<pos<<endl;
	//cout<<bit[2]<<endl;
	int ans=0;
	while(pos>0){
		//cout<<"DAs"<<bit[pos]<<endl;
		ans+=bit[pos];
		pos-=pos&(-pos);
		
	}

	return ans;
}
int getelem(int val){
	int low=1;
	int high=n;
	int mid,ans,rem;
	while(low<=high){
		mid=(low+high)/2;
		ans=query(mid-1);
		if(ans>val){
			high=mid-1;
		}
		else{
			//cout<<mid<<" ds  "<<ans<<endl;
			rem=mid;
			low=mid+1;
		}
	}
//	cout<<rem<<"DASs"<<query(rem)<<endl;
	update(rem,-1);
	return rem;
}
int main(){
    //std::ios::sync_with_stdio(false);
    
    cin>>n;
    int i,j;
    f(i,1,n+1){
    	update(i,1);
    }
   
    rep(i,n){
    	
    	scanf("%d",&a[i]);
    //	cout<<" "<<a[i]<<endl;
    	a[i]++;
    	haha[i]=query(a[i]-1);
    	update(a[i],-1);
    	
    }
     
    //return 0;
    f(i,1,n+1){
    	update(i,1);
    }
    rep(i,n){
    	scanf("%d",&b[i]);
    	b[i]++;
    	lol[i]=query(b[i]-1);
    	//cout<<haha[i]<<endl;
    	update(b[i],-1);
    }
    //return 0;
    fd(i,n-1,0){
    	haha[i]+=lol[i];
    	//cout<<haha[i]<<" "<<lol[i]<<endl;
    	if(haha[i]>n-1-i){
    		if(i)
    			haha[i-1]++;
    		haha[i]-=(n-i);
    	}

    }
    
    f(i,1,n+1){
    	update(i,1);
    }
    
   // return 0; 
    rep(i,n){
    	//cout<<haha[i]<<endl;
    	printf("%d ",getelem(haha[i])-1);
    }


    return 0;      

}