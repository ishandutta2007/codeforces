
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
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


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
map<string,int> mapi1;
map<string,vi > mapi;


ll checkpal(string s){
	int i;
	int j=s.length()-1;
	rep(i,s.length()){
		if(s[i]!=s[j])
			return 0;
		j--;
	}
	return 1;
}

ll countnonpal(string s){
	string s1=""; 
	ll sumi=0;
	int i,j;
	fd(i,s.length()-1,0){
		s1+=s[i];
	}
	 i=mapi1[s]-1;
	 j=mapi1[s1]-1;
	while(i>=0 && j>=0){
		if(mapi[s][i]+mapi[s1][j]>0){
			sumi+=mapi[s][i]+mapi[s1][j];
		}
		else{
			break;
		}
		i--;
		j--;
	}
	mapi1[s]=i+1;
	mapi1[s1]=j+1;

	return sumi;
}

ll countpal(string s){
	ll sumi=0;
	int i=mapi1[s]-1;
	int j=mapi1[s]-2;
	while(i>=1){
		if(mapi[s][i]+mapi[s][j]>0){
			sumi+=mapi[s][i]+mapi[s][j];
		}
		else{
			break;
		}
		i-=2;
		j-=2;
	}
	mapi1[s]=i+1;
	//cout<<s<<"  "<<sumi<<endl;
	return sumi;
}


int main(){
	std::ios::sync_with_stdio(false);  
	map<string,vi >::iterator it; 
	ll n,k,i,j,val;
	cin>>n>>k;
	string str;
	rep(i,n){

		cin>>str>>val;
		mapi[str].pb(val);
		mapi1[str]++;
	}
	ll answer=0;
	

	for(it=mapi.begin();it!=mapi.end();it++){
		
		sort((it->ss).begin(),(it->ss).end());
	}
	for(it=mapi.begin();it!=mapi.end();it++){
		
		if(checkpal(it->ff)==0){
			answer+=countnonpal(it->ff);
			//cout<<"hii"<<it->ff<<endl;
			
		}
		else{
			answer+=countpal(it->ff);
		}
	}
	ll maxi=answer;
	for(it=mapi.begin();it!=mapi.end();it++){
		if(checkpal(it->ff)==1){
			//cout<<mapi[it->ff].size()<<endl;
			if(mapi[it->ff].size()==mapi1[it->ff]){
				maxi=max(maxi,answer+mapi[it->ff][mapi1[it->ff]-1]);
				//cout<<it->ff<<"    "<<mapi[it->ff][mapi1[it->ff]-1];
			}
			else{
				
					maxi=max(maxi,answer-mapi[it->ff][mapi1[it->ff]]);
					if(mapi1[it->ff]!=0){
						maxi=max(maxi,answer+mapi[it->ff][mapi1[it->ff]-1]);
					}
				
			}
		}
		
	}
	cout<<maxi<<endl;

}