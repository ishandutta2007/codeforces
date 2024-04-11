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
string s1,s2;
vi vec1,vec2;
int lol[312345];
int main(){
    std::ios::sync_with_stdio(false); 
    cin>>s1>>s2;
    int n=s1.length(),i,j;
    rep(i,n){
    	vec1.pb(s1[i]);
    	vec2.pb(s2[i]);
    }
    sort(vec1.begin(),vec1.end());
    sort(vec2.begin(),vec2.end());
   	int a=0;
   	int b=n-1;

    rep(i,n){
	
		if(vec1[a]<vec2[b]){
			if(i%2==0){
				lol[i]=vec1[a];
				a++;
			}
			else{
				lol[i]=vec2[b];
				b--;
			}
		}
		else{
			
				if(n%2){
					j=i;
					while(j<n){
						lol[j]=vec1[a];
						a++;
						j+=2;
					}
					j=i+1;
					while(j<n){
						lol[j]=vec2[b];
						b--;
						j+=2;
					}


				}
				else{
					j=i+1;
					while(j<n){
						lol[j]=vec1[a];
						a++;
						j+=2;
					}
					j=i;
					while(j<n){
						lol[j]=vec2[b];
						b--;
						j+=2;
					}
				}
			rep(i,n){
				cout<<(char)lol[i];
			}
			cout<<endl;
			return 0;
			
		}
    	
    }
    rep(i,n){
    	cout<<(char)lol[i];
    }
    return 0;

}