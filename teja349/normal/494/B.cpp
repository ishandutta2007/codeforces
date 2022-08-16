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
string s1;
int z[323456];

int zfunction(){
	int l=0,r=0,i;
	int n=s1.length();
	//cout<<s1<<endl;
	f(i,1,s1.length()){

		if(i>r){
			l=i;
			r=i;
			while(r<n && s1[r-i]==s1[r]) r++;
			z[i]=r-i;
			r--;
		}
		else{
			if(z[i-l]<r-i+1){
				z[i]=z[i-l];
			}
			else{
				
				
				l=i;
				while(r<n && s1[r-i]==s1[r]) r++;
				z[i]=r-i;
				r--;
			}
		}
		//cout<<i<<"v c "<<z[i]<<endl;
	}
	return 0;
}
int haha[123456],sumi[123456],dp[123456],remem[123456],baba[123456];

int main(){
    std::ios::sync_with_stdio(false);
	string s;
	string t;
	cin>>s>>t;
	s1=t;
	s1+='@';
	s1+=s;    
    zfunction();
    int n=t.length(),i,j=0;
    int tlen=n;
    f(i,n+1,s1.length()){
    	baba[j]=z[i];
    	j++;
    }
    n=s.length();
    haha[n]=1;
    dp[n]=0;
    sumi[n]=1;
    remem[n]=-1;
    fd(i,n-1,0){
    	if(baba[i]==tlen){
    		remem[i]=i;
    	}
    	else{
    		remem[i]=remem[i+1];
    	}
    	//cout<<i<<" "<<remem[i]<<endl;
    }
    fd(i,n-1,0){
    	if(remem[i]==-1){
    		dp[i]=0;    		
    	}
    	else{
    		dp[i]=sumi[remem[i]+tlen];
    	}
    	haha[i]=haha[i+1]+dp[i];
    	if(haha[i]>=mod)
    		haha[i]-=mod;
    	sumi[i]=sumi[i+1]+haha[i];
    	if(sumi[i]>=mod)
    		sumi[i]-=mod;
    	//cout<<remem[i]+tlen<<" dssd "<<haha[i]<<endl;
    }
    //if(haha[0]=0)
    if(haha[0]==0)
    	cout<<mod-1<<endl;
    else
    	cout<<haha[0]-1<<endl;



}