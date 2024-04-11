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
int a[123][10],lol[100];  
double haha[10];
int n;
int check(int val){
	int j;
	double aas=val;
	aas*=1.00;
	int papa;
	int ans=0; 
	int baba;
	double lala;
//	cout<<aas<<endl;
	rep(j,5){

		
			if(a[0][j]>=a[1][j] || a[0][j]==0){
				lala=(haha[j]*1.00)/(n+aas);
				lala*=32.00;
				papa=ceil(lala);
				baba=lol[papa];
				//cout<<baba<<" "<<lala<<endl;
				ans+=baba*(a[0][j]-a[1][j]);
			}
			else{
				lala=(haha[j]+aas*1.000)/(n+aas);
				lala*=32.00;
				papa=ceil(lala);
				baba=lol[papa];
				//cout<<baba<<" "<<lala<<endl;
				ans+=baba*(a[0][j]-a[1][j]);
			}
	
		//cout<<ans<<endl;
	}
	//cout<<ans<<endl;
	if(ans>0){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
    std::ios::sync_with_stdio(false); 
    int i,j;
    cin>>n;
    lol[0]=12;
    lol[1]=12;
    lol[2]=10;
    lol[3]=8;
    lol[4]=8;
    f(i,5,9){
    	lol[i]=6;
    }
    f(i,9,17){
    	lol[i]=4;
    }
    f(i,17,33){
    	lol[i]=2;
    }

    rep(i,n){
    	rep(j,5){
    		cin>>a[i][j];
    	}
    }
    rep(i,7){
    	haha[i]=0;
    }
    rep(i,n){
    	rep(j,5){
    		if(a[i][j]!=-1){
    			haha[j]+=1;
    		}
    	}
    }
    rep(i,2){
    	rep(j,5){
    		if(a[i][j]!=-1){
    			
    			a[i][j]=250-a[i][j];
    		}
    		else{
    			a[i][j]=0;
    		}
    	}
    }
    rep(i,123456){
    	if(check(i)){
    		cout<<i<<endl;
    		return 0;
    	}
    }
    cout<<-1<<endl;
    return 0;
   // cout<<ans<<endl;
   // return 0;
}