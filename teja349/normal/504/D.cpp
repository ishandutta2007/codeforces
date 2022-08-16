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
int ans[5000],valid[2000],haha[2000];
bitset<2000> setb,combin,anscom[2000],ansbit[2000];
int checkpresence(int pos){
	int i;
	rep(i,2000){
		combin[i]=0;
	}
	combin[pos]=1;
	rep(i,2000){
		if(valid[i]){
			if(setb[i]==1){
				setb^=ansbit[i];
				combin^=anscom[i];
			}
		}
		else{
			if(setb[i]==1){
				//cout<<i<<" bfbb"<<endl;
				valid[i]=1;
				ansbit[i]=setb;
				anscom[i]=combin;
				cout<<0<<endl;
				return 0;
			}
		}
	}
	combin[pos]=0;
	int cnt=0;
	rep(i,2000){
		if(combin[i])
			cnt++;
	}

	cout<<cnt<<" ";
	rep(i,2000){
		if(combin[i])
			cout<<i<<" ";
	}
	cout<<endl;
	return 0;

}
int bigval=(1<<26);
int bigbits=26;
int convertbin(string s,int pos){
	int len=s.length();
	int i,p;
	rep(i,len){
		ans[i]=s[i]-'0';
	}
	rep(i,2000){
		setb[i]=0;
		haha[i]=0;
	}
	int st=0,st1,previ,j=0;
	while(st!=len){
		//setb[j++]=ans[len-1]%2;
		st1=st;
		st=len;
		previ=0;
		f(i,st1,len){
			previ*=10;
			previ+=ans[i];
			ans[i]=previ/bigval;
			if(ans[i]){
				st=min(st,i);
			}
			previ%=bigval;
		}
		haha[j++]=previ;

	}
	int k=0;
	rep(i,j){
		rep(p,bigbits){
			setb[k++]=haha[i]%2;
			haha[i]/=2;
		}
	}

	checkpresence(pos);
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    int m;
    cin>>m;
    int i;
    string s;
    s="";
    // rep(i,600){
    // 	s+='9';
    // }

    
    rep(i,m){
    	cin>>s;
    	convertbin(s,i);
    }
    return 0;  
    
}