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
vector<vi> inx(312345),outx(312345),iny(312345),outy(312345);
int x1[212345],yone[212345],x2[212345],y2[212345];
map<int,int> mapx;
map<int,int> mapy,invx,invy;
int remx[212345],remy[212345];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,j;
    rep(i,n){
    	remx[i]=-inf;
    	remy[i]=-inf;
    	cin>>x1[i]>>yone[i]>>x2[i]>>y2[i];
    	mapx[x1[i]]=1;
    	mapy[yone[i]]=1;
    	mapx[x2[i]]=1;
    	mapy[y2[i]]=1;
    }
    int counter=0;
    map<int,int>::iterator it;
    for(it=mapx.begin();it!=mapx.end();it++){
    	it->ss=counter++;
    	invx[it->ss]=it->ff;
    }
    int counterx,countery;
    counterx=counter;
    counter=0;
    for(it=mapy.begin();it!=mapy.end();it++){
    	it->ss=counter++;
    	invy[it->ss]=it->ff;
    }
    countery=counter;
    set<int> seti;
    rep(i,n){
    	x1[i]=mapx[x1[i]];
    	yone[i]=mapy[yone[i]];
    	x2[i]=mapx[x2[i]];
    	y2[i]=mapy[y2[i]];
    	inx[x1[i]].pb(i);
    	outx[x2[i]+1].pb(i);
    	iny[yone[i]].pb(i);
    	outy[y2[i]+1].pb(i);
    	seti.insert(i);
    }
    int cnt=0;
    int flagx=0,flagy=0,foundx=0,foundy=0;
    rep(i,counterx){
    	rep(j,outx[i].size()){
    		seti.insert(outx[i][j]);
    		cnt--;
    	}
    	rep(j,inx[i].size()){
    		seti.erase(inx[i][j]);
    		cnt++;
    	}
    	if(cnt==n){
    		foundx=invx[i];
    		flagx=1;
    		break;
    	}
    	else if(cnt==n-1){

    		remx[*(seti.begin())]=invx[i];
    	}
    	//cout<<invx[i]<<" "<<cnt<<endl;
    }
    seti.clear();
    cnt=0;
    rep(i,n){
    	seti.insert(i);
    }
    rep(i,countery){
    	rep(j,outy[i].size()){
    		seti.insert(outy[i][j]);
    		cnt--;
    	}
    	rep(j,iny[i].size()){
    		seti.erase(iny[i][j]);
    		cnt++;
    	}
    	if(cnt==n){
    		foundy=invy[i];
    		flagy=1;
    		break;
    	}
    	else if(cnt==n-1){
    		remy[*(seti.begin())]=invy[i];
    	}
    }

    if(flagx==1){
    	cout<<foundx<<" ";
    	if(flagy==1){
    		cout<<foundy<<endl;
    	}
    	else{
    		rep(i,n){
    			if(remy[i]!=-inf){
    				cout<<remy[i]<<endl;
    				break;
    			}
    		}
    	}
    	return 0;

    }

    //cout<<flagy<<endl;
    if(flagy==1){
    	
    	
    		rep(i,n){
    			if(remx[i]!=-inf){
    				cout<<remx[i]<<" ";
    				break;
    			}
    		}
    	
    	cout<<foundy<<endl;
    	return 0;

    }
    //cout<<"Das"<<endl;
    rep(i,n){
    	if(remx[i]!=-inf && remy[i]!=-inf){
    		cout<<remx[i]<<" "<<remy[i]<<endl;
    		return 0;
    	}
    }



    return 0;   
}