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
ll haha[523456];
int solvevon(vl vec,int k){
	haha[0]=1;
	vl vec1;
	int n=vec.size(),i,j;
	//cout<<n<<endl;
    vec1.pb(0);
    f(i,1,n){	
    	if(!vec1.empty() && vec[vec1[vec1.size()-1]]==vec[i]){
    		haha[i]=haha[vec1[vec1.size()-1]]+1;
    		vec1.pb(i);
    	}
    	else{
    		haha[i]=1;
    		vec1.pb(i);
    	}
    	//cout<<haha[i]<<endl;
    	if(haha[i]==k){
    		rep(j,k){
    			vec1.erase(vec1.end()-1);

    		}

    	}


    }
    cout<<vec1.size()<<endl;
    exit(0);
}
int main(){
    std::ios::sync_with_stdio(false);
    ll n,k,m;
    cin>>n>>k>>m;
    ll i,j,gg,val;
    vl vec;
    rep(i,n){
    	cin>>val;
    	vec.pb(val);
    }
    //prev=0;
    vl vec1,vec3;
    haha[0]=1;
    vec1.pb(0);
    f(i,1,n){	
    	if(!vec1.empty() && vec[vec1[vec1.size()-1]]==vec[i]){

    		haha[i]=haha[vec1[vec1.size()-1]]+1;
    		vec1.pb(i);
    	}
    	else{
    		
    		haha[i]=1;
    		vec1.pb(i);
    	}
    	//cout<<haha[i]<<endl;
    	if(haha[i]==k){
    		//cout<<i<<endl;
    		rep(j,k){
    			//cout<<vec[vec1[vec1.size()-1]]<<" ";
    			//cout<<j<<endl;
    			vec1.erase(vec1.end()-1);

    		}

    	}


    }
    rep(i,vec1.size()){
    	vec1[i]=vec[vec1[i]];
    }
    n=vec1.size();
    if(m==1){
    	cout<<n<<endl;
    	return 0;
    }
    //cout<<n<<endl;
    if(n<=k){

    	int flag=0;
    	rep(i,n){
    		if(vec1[i]!=vec1[0])
    			flag=1;
    	}
    	//cout<<
    	ll ans;
    	if(flag==1){
    		ans=n*m;
    	}
    	else{
    		ans=n*m;
    		ans%=k;
    	}
    	cout<<ans<<endl;

    	return 0;
    }
    //cout<<"Das";
    haha[0]=1;
    f(i,1,n){
    	if(vec1[i]==vec1[i-1])
    		haha[i]=haha[i-1]+1;
    	else
    		haha[i]=1;
    }
    i=n-1;
    j=0;
    ll previ,boo=0;
    while(1)
    {

    	ll ans;
    	previ=i-haha[i];
    	//cout<<
    	if(previ<j){
    		ans=i-j+1;
    		ans*=(m-2);
    		ans%=k;
    		//cout<<i<<" "<<j<<endl;
    		//cout<<ans<<endl;
    		rep(gg,i+1){
    			vec3.pb(vec1[gg]);

    		}
    		//cout<<ans<<endl;
    		rep(gg,ans){
    			vec3.pb(vec1[i]);
    		}
    		f(gg,j,n){
    			vec3.pb(vec1[gg]);
    			//cout<<vec1[gg]<<endl;
    		}
    		// rep(i,vec3.size()){
    		// 	cout<<vec3[i]<<" ";
    		// }
    		solvevon(vec3,k);
    	}
    	val=haha[i];

    	ll j1=j;
    	while(val!=k){
    		//cout<<val<<endl;
    		if(val!=k && vec1[j]!=vec1[i]){
    			//cout<<val<<endl;
    			boo=1;
    			break;
    		}
    		j++;
    		val++;
    	}
    	//cout<<val<<endl;
    	if(boo){
    		j=j1;
    		//cout<<i<<" "<<j<<endl;
    		
    		ans=i-j+1;
    		//cout<<ans<<endl;
    		ans*=(m-2);

    		ans+=i+1;
    		ans+=n-j;
    		cout<<ans<<endl;
    		return 0;
    	}
    	i=i-haha[i];

    }

    return 0;  
    
}