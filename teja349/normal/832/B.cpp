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
int good[12345];
string s,str;   
int morna(int req){
	//cout<<"DASads";
	int i=0,j=0,k;
	//cout<<req<<endl;
	while(i<s.length()){
		if(s[i]=='*'){
			rep(k,req){
				if(good[str[j]]){
					cout<<"NO"<<endl;
					return 0;
				}
				
				j++;
				//continue;
			}
			j--;
		}
		else if(s[i]=='?'){
			if(good[str[j]]==0){
				cout<<"NO"<<endl;
				return 0;
			}
		}
		else if(str[j]!=s[i]){
			cout<<"NO"<<endl;
			return 0;
		}
		i++;
		j++;

	}
	cout<<"YES"<<endl;
	return 0;
}
int lesse(){
	int i=0,j=0;
	while(i<s.length()){
		if(s[i]=='*'){
			i++;
			continue;
		}
		else if(s[i]=='?'){
			if(good[str[j]]==0){
				cout<<"NO"<<endl;
				return 0;
			}
		}
		else if(str[j]!=s[i]){
			cout<<"NO"<<endl;
			return 0;
		}
		i++;
		j++;

	}
	cout<<"YES"<<endl;
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    //string s;
    int i,j;
    cin>>s;
    rep(i,s.length()){
    	good[s[i]]=1;
    }
    cin>>s;
    int flag=0;
    rep(i,s.length()){
    	if(s[i]=='*'){
    		flag=1;
    		break;
    	}
    }
    int q;
    cin>>q;
    while(q--){
    	cin>>str;
    	//cout<<"Daasd";
    	if(str.length()+1==s.length() && flag){

    		lesse();
    		//cout<<"dasd";
    	}
    	else if(flag && str.length()>=s.length()){

    		//cout<<"dsa";
    		morna(str.length()-s.length()+1);
    	}
    	else if(str.length()==s.length()){
    		morna(1);

    	}
    	else{
    		cout<<"NO"<<endl;

    		//return 0;
    	}

    }
    //return 0;

    return 0;      

}