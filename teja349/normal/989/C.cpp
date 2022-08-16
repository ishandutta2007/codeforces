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
string arr[100][100];
int main(){
    std::ios::sync_with_stdio(false);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    a--;
    int i,j,k;
    i=0;
    j=0;
    while(i<50){
    	j=0;
    	while(j<50){
    		if(b!=0 && j%2==0){
    			b--;
    			arr[i][j]="B";
    		}
    		else{
    			arr[i][j]="A";
    		}
    		j++;

    	}
    	i++;
    	rep(j,50){
    		arr[i][j]="A";
    	}
    	i++;
    	if(b==0)
    		break;
    }
    b=c;
    while(i<50){
    	j=0;
    	while(j<50){
    		if(b!=0 && j%2==0){
    			b--;
    			arr[i][j]="C";
    		}
    		else{
    			arr[i][j]="A";
    		}
    		j++;
    	}
    	i++;
    	rep(j,50){
    		arr[i][j]="A";
    	}
    	i++;
    	if(b==0)
    		break;
    	
    }
    if(a==0){
    	b=d;
    	while(i<50){
	    	j=0;
	    	while(j<50){
	    		if(b!=0 && j%2==0){
	    			b--;
	    			arr[i][j]="D";
	    		}
	    		else{
	    			arr[i][j]="A";
	    		}
	    		j++;
	    	}
	    	i++;
	    	rep(j,50){
	    		arr[i][j]="A";
	    	}
	    	i++;
	    	if(b==0)
	    		break;
	    	
	    }
	    f(k,i,50){
	    	rep(j,50){
	    		arr[k][j]="A";
	    	}
	    }
    }
    else{
    	d--;
    	b=d;
    	while(i<50){
	    	j=0;
	    	while(j<50){
	    		if(b!=0 && j%2==0){
	    			b--;
	    			arr[i][j]="D";
	    		}
	    		else{
	    			arr[i][j]="A";
	    		}
	    		j++;
	    	}
	    	i++;
	    	rep(j,50){
	    		arr[i][j]="A";
	    	}
	    	i++;
	    	
	    	if(b==0)
	    		break;
	    	
	    }
	    rep(j,50){
	    		arr[i][j]="D";
	    	}
	    	i++;
	    b=a;
	    
    	while(i<50){
	    	j=0;
	    	while(j<50){
	    		if(b!=0 && j%2==0){
	    			b--;
	    			arr[i][j]="A";
	    		}
	    		else{
	    			arr[i][j]="D";
	    		}
	    		j++;
	    	}
	    	i++;
	    	rep(j,50){
	    		arr[i][j]="D";
	    	}
	    	i++;
	    	if(b==0)
	    		break;
	    	
	    }
	    f(k,i,50){
	    	rep(j,50){
	    		arr[k][j]="D";
	    	}
	    }
    }
    cout<<50<<" "<<50<<endl;
    rep(i,50){
    	rep(j,50){
    		cout<<arr[i][j];
    	}
    	cout<<endl;
    }

    return 0;
    

}