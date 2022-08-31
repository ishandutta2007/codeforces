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
int p[12345],inv[12345],haha[12345],lol[12345];
int seti[12345];
int foo(int i,int j){
	//cout<<"? "<<i<<" "<<j<<endl;
	printf("? %d %d\n",i,j);
	fflush(stdout);
	scanf("%d",&i);
	return i;
}
int main(){
    //std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,val;
    rep(i,n){
    	val=foo(i,i);
    	haha[i]=val;
    }
    rep(i,n){
    	val=foo((i+1)%n,i);
    	lol[i]=val;
    }
    int cnt=0,j,rem;
    int maxi=-2;
    int flag;
    rep(j,n){
    	//seti.clear();
    	maxi=-2;
    	flag=0;
    	p[0]=j;
    	inv[0]=haha[0]^p[0];
    	f(i,1,n){
    		p[i]=lol[i-1]^inv[i-1];
    		inv[i]=haha[i]^p[i];
    		
    	}
    	rep(i,n){
    		//maxi=max(maxi,p[i]);
    		if(p[i]>=n || inv[p[i]]!=i){
    			flag=1;
    			break;
    		}
    		//seti[p[i]]=1;
    		//seti.insert(p[i]);
    	}
    	
    	if(flag)
    		continue;
    	cnt++;
    	rem=j;
    }
    cout<<"!"<<endl;
    cout<<cnt<<endl;
    j=rem;
    p[0]=j;

	inv[0]=haha[0]^p[0];
	f(i,1,n){
		p[i]=lol[i-1]^inv[i-1];
		inv[i]=haha[i]^p[i];
	}
	rep(i,n){
		cout<<p[i]<<" ";
	}
    return 0;  
    
}