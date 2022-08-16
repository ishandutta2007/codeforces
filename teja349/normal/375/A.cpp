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
map<int,int>mapi4;
int main(){
    std::ios::sync_with_stdio(false);
    int a[4]={1,6,8,9};
    int i;
    vi vec;
    int haha;
    //set<int> seti;
    rep(i,4){
    	vec.pb(i);
    }
    do{
    	haha=1;
    	int val=0;
    	rep(i,4){
    		val+=a[vec[i]]*haha;
    		haha*=10;
    		//val%=7;
    	}
    	mapi4[val%7]=val;
    	//cout<<val<<endl;
    	//val%=7;
    	//seti.insert(val);
    }while(next_permutation(all(vec)));
    sort(all(vec));
    	
    string s;
    cin>>s;
    int arr[1234]={0};
    int n=s.length();
    rep(i,n){
    	arr[s[i]]++;
    }
    if(arr['0']==s.length()-4){
    	cout<<mapi4[0];
    	rep(i,arr['0'])
    		cout<<'0';
    }
    else{
    	//cout<<"Dads"<<endl;
    	arr['1']--;
    	arr['6']--;
    	arr['8']--;
    	arr['9']--;
    	int val,lol=1,ans=0;
    	rep(i,1000){
    		val=arr[i];
    		while(val){
    			//cout<<val<<endl;
    			//cout<<(char)i;
    			ans+=(i-'0')*lol;
    			lol*=10;
    			lol%=7;
    			ans%=7;
    			val--;
    		}

    	}
    	fd(i,1000,0){
    		val=arr[i];
    		while(val){
    			//cout<<val<<endl;
    			cout<<(char)i;
    			
    			// ans+=(i-'0')*lol;
    			// lol*=10;
    			// lol%=7;
    			// ans%=7;
    			val--;
    		}
    	}
    	//cout<<ans<<"vsd"<<endl;
    	ans*=10000;
    	ans%=7;
    	//cout<<ans<<endl;
    	ans=7-ans;
    	ans%=7;
    	cout<<mapi4[ans]<<endl;
    }
   // cout<<seti.size()<<endl;
    return 0;  
    
}