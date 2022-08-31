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
int face[10][10],side[10][10];
int a[100],b[100];

int applyfor(int i){
	int j;
	int prev1=b[side[i][0]];
	int prev2=b[side[i][1]];
	int val;
	rep(j,3){
       val=j+1;
       b[side[i][2*j]]=b[side[i][2*val]];
       b[side[i][2*j+1]]=b[side[i][2*val+1]];
	}
	b[side[i][6]]=prev1;
	b[side[i][7]]=prev2;
	return 0;

}
int applyback(int i){
	int j;
	int prev1=b[side[i][6]];
	int prev2=b[side[i][7]];
	int val;
	fd(j,3,1){
       val=j-1;
       b[side[i][2*j]]=b[side[i][2*val]];
       b[side[i][2*j+1]]=b[side[i][2*val+1]];
	}
	b[side[i][0]]=prev1;
	b[side[i][1]]=prev2;

    return 0;
}


int main(){
    std::ios::sync_with_stdio(false);
    int i;
    f(i,1,25){
    	cin>>a[i];
    }
    face[0][0]=1;
    face[0][1]=2;
    face[0][2]=3;
    face[0][3]=4;

    face[1][0]=5;
    face[1][1]=6;
    face[1][2]=7;
    face[1][3]=8;

    face[2][0]=9;
    face[2][1]=10;
    face[2][2]=11;
    face[2][3]=12;

    face[3][0]=13;
    face[3][1]=14;
    face[3][2]=15;
    face[3][3]=16;

    face[4][0]=17;
    face[4][1]=18;
    face[4][2]=19;
    face[4][3]=20;

    face[5][0]=21;
    face[5][1]=22;
    face[5][2]=23;
    face[5][3]=24;


    side[0][0]=3;
    side[0][1]=4;
    side[0][2]=17;
    side[0][3]=19;
    side[0][4]=10;
    side[0][5]=9;
    side[0][6]=16;
    side[0][7]=14;


    side[1][0]=13;
    side[1][1]=14;
    side[1][2]=5;
    side[1][3]=6;
    side[1][4]=17;
    side[1][5]=18;
    side[1][6]=21;
    side[1][7]=22;


    side[2][0]=2;
    side[2][1]=4;
    side[2][2]=6;
    side[2][3]=8;
    side[2][4]=10;
    side[2][5]=12;
    side[2][6]=21;
    side[2][7]=23;
 
    int j,k,flag;
 	rep(j,3){
 		rep(i,25){
 			b[i]=a[i];
 		}
 		applyfor(j);
 		flag=0;
 		rep(i,6){
 			int val=b[face[i][0]];
 			rep(k,4){
              if(b[face[i][k]]!=val)
              	 flag=1;
 			}
 		}

 		if(flag==0)
 		{
 			cout<<"YES"<<endl;
 			return 0;
 		}


 	}

 	rep(j,3){
 		rep(i,25){
 			b[i]=a[i];
 		}
 		applyback(j);
 		flag=0;
 		rep(i,6){
 			int val=b[face[i][0]];
 			rep(k,4){
              if(b[face[i][k]]!=val)
              	 flag=1;
 			}
 		}

 		if(flag==0)
 		{
 			cout<<"YES"<<endl;
 			return 0;
 		}


 	}
 	cout<<"NO"<<endl;




    return 0;  
    
}