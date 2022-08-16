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
struct total{
	//string str;
	string en;
	string st;
	int haha[300];
	//int leng;
};
total rem[300];
vector< vector< set<int> > > seti(300,vector< set<int> >(16));
int posi;
int merge(int a,int b){
	string la,lub,wubb;

	la=rem[a].st+rem[b].st;
	lub=rem[a].en+rem[b].en;
	wubb=rem[a].en+rem[b].st;
	set<int>::iterator it;
	int j,haha,i;
	rep(j,min((int)la.length(),15)){
		rem[posi].st+=la[j];
	}
	int val=lub.length()-1;
	fd(j,min((int)lub.length()-1,14),0){
		rem[posi].en+=lub[val-j];
	}
	//cout<<la<<"  "<<lub<<"  "<<wubb<<endl; 
	int k,t;
	rep(j,wubb.length()){
		f(k,1,15){

			haha=0;
			rep(t,k){
				
				haha*=2;
				haha+=wubb[j+t]-'0';
				//cout<<j+t<<" d "<<wubb[j+t]<<endl;
			}
			seti[posi][k].insert(haha);
			
			
			if(j+k==wubb.length()){
				break;
			}
		}
		
	}
	//cout<<seti[posi][1].size()<<endl;
	rep(i,15){
		for(it=seti[a][i].begin();it!=seti[a][i].end();it++){
			seti[posi][i].insert(*it);
		}
		for(it=seti[b][i].begin();it!=seti[b][i].end();it++){
			seti[posi][i].insert(*it);
		}
	}
	
	f(i,1,15){
		if(seti[posi][i].size()!=(1<<i)){
			cout<<i-1<<endl;
			return 0;
		}
	}
	cout<<14<<endl;
	return 0;
	return 0;

}
string s[123];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,j,k,t,haha=0;
    rep(i,n){
    	cin>>s[i];
    	
    	rep(j,s[i].length()){
    		f(k,1,15){

    			haha=0;
    			rep(t,k){
    				
    				haha*=2;
    				haha+=s[i][j+t]-'0';
    			}
    			
    			seti[i][k].insert(haha);
    			if(j+k==s[i].length()){
    				break;
    			}
    		}
    		
    	}
    	rem[i].st="";
    	rep(j,min((int)s[i].length(),15)){
    		rem[i].st+=s[i][j];
    	}
    	rem[i].en="";
    	int val=s[i].length()-1;
    	fd(j,min((int)s[i].length()-1,14),0){
    		rem[i].en+=s[i][val-j];
    	}
    	// rep(j,300){
    	// 	rem[i].haha[j]=0;
    	// }
    	// rem[i].haha[i]=1;
    	//rem[i].leng=
    }
    int m;
    posi=n;
    cin>>m;
    int a,b;
   //cout<<seti[4][1].size()<<"daads"<<endl;
    while(m--){
    	cin>>a>>b;
    	a--;
    	b--;
    	merge(a,b);
    	//cout<<m<<endl;
    	posi++;
    }

    

    return 0;  
    
}