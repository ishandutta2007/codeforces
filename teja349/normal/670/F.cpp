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
int wow(int val){
	int val1=val;
	while(val>0){
		val/=10;
		val1++;
	}
	return val1;
}
string s,str2;
int n;
int check(int mid){
	string haha="";
	int i;
	f(i,mid,n){
		haha+=s[i];
	}
	if(haha>str2){
		return 1;
	}
	return 0;
}
int a[1223];
int main(){
    std::ios::sync_with_stdio(false);
    string str1,poss1,poss2,poss3;
    cin>>str1>>str2;
    if(str1=="01" || str1=="10"){
    	cout<<0<<endl;
    	return 0;
    }
    int i;
    f(i,1,1000000){
    	if(wow(i)==str1.length())
    		break;
    }
    int siz=i;
    rep(i,str1.length()){
    	a[str1[i]]++;
    }
    


    int val=siz;
    while(siz>0){
    	a[siz%10+'0']--;
    	siz/=10;
    }
    rep(i,str2.length()){
    	a[str2[i]]--;
    }

    s="";
    rep(i,1000){
    	val=a[i];
    	while(val){
    		s+=(char)i;
    		val--;
    		//cout<<val<<endl;
    	}
    }
    //return 0;
    if( str2[0]!='0'){
    	poss2=str2+s;
    }
    else{
    	poss2="aaa";
    }
    int flag=0;
    f(i,'1','9'+1){
    	if(a[i]){
    		flag=1;
    		break;
    	}
    }
    //return 0;
    if(flag==0){
    	cout<<poss2<<endl;
    	return 0;
    }
    flag=0;
    s="";
    s+=(char)i;
    a[i]--;
    rep(i,1000){
    	val=a[i];
    	while(val){
    		s+=(char)i;
    		val--;
    	}
    }

    n=s.length();
    int low=1;
    int high=n-1,mid;
    int ans=n;
    while(low<=high){
    	mid=(low+high)/2;
    	if(check(mid)){
    		ans=mid;
    		high=mid-1;
    	}
    	else{
    		low=mid+1;
    	}
    }
    poss1="";
    rep(i,ans){
    	poss1+=s[i];
    }
    poss1+=str2;
    f(i,ans,n){
    	poss1+=s[i];
    }
   // return ans;
    poss3="";
    poss3+=s[0];
    flag=0;
    f(i,1,s.length()){
    	if(flag || s[i]<=str2[0]){
    		poss3+=s[i];
    	}
    	else{
    		poss3+=str2;
    		poss3+=s[i];
    		flag=1;
    	}
    }
    //cout<<poss1<<endl;
    if(!flag)
    	poss3+=str2;
    //cout<<str2<<endl;
    if(poss1>poss3)
    	poss1=poss3;
    if(poss1<poss2){
    	cout<<poss1<<endl;
    }
    else{
    	cout<<poss2<<endl;
    }
   
    return 0;  
    
}