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
int l[123456],r[123456],par[123456],dig[123456],val[123456],op[123456],subtree[123456];
int maxi[123456][120],mini[123456][120],flag[123456];
int typ;
int poo[212];
int dfs(int cur){
	subtree[cur]=0;
	if(dig[cur]==1){
		// f(i,1,poo[typ]+2){
		// 	maxi[cur][i]=inf;
		// 	mini[cur][i]=inf;
		// }
		maxi[cur][0]=val[cur];
		mini[cur][0]=val[cur];
		return 0;
	}
	//cout<<op[cur]<<endl;
	dfs(l[cur]);
	dfs(r[cur]);
	int i,j;
	subtree[cur]=subtree[l[cur]]+subtree[r[cur]];
	if(op[cur]==3)
		subtree[cur]++;
	rep(i,min(subtree[cur]+1,poo[typ])+3){
		maxi[cur][i]=-inf;
		mini[cur][i]=inf;
	}
	if(op[cur]==1){
		
		rep(i,min(subtree[l[cur]],poo[typ])+1){
			for(j=0;j<min(subtree[r[cur]],poo[typ])+1 && i+j<=poo[typ];j++){
				
				maxi[cur][i+j]=max(maxi[cur][i+j],maxi[l[cur]][i]+maxi[r[cur]][j]);
				mini[cur][i+j]=min(mini[cur][i+j],mini[l[cur]][i]+mini[r[cur]][j]);
			}
			
		}
	}
	else if(op[cur]==2){
		rep(i,min(subtree[l[cur]],poo[typ])+1){
			for(j=0;j<min(subtree[r[cur]],poo[typ])+1 && i+j<=poo[typ];j++){
				
				maxi[cur][i+j]=max(maxi[cur][i+j],maxi[l[cur]][i]-mini[r[cur]][j]);
				mini[cur][i+j]=min(mini[cur][i+j],mini[l[cur]][i]-maxi[r[cur]][j]);
			}			
		}
	}
	else if(typ==0){
		//cout<<"buu"<<endl;
		rep(i,min(subtree[l[cur]],poo[typ])+1){
			for(j=0;j<min(subtree[r[cur]],poo[typ])+1 && i+j<=poo[typ];j++){
				
				maxi[cur][i+j]=max(maxi[cur][i+j],maxi[l[cur]][i]-mini[r[cur]][j]);
				mini[cur][i+j]=min(mini[cur][i+j],mini[l[cur]][i]-maxi[r[cur]][j]);
			}			
		}
		rep(i,min(subtree[l[cur]],poo[typ])+1){
			for(j=0;j<min(subtree[r[cur]],poo[typ])+1 && i+j<=poo[typ];j++){
				
				maxi[cur][i+j+1]=max(maxi[cur][i+j+1],maxi[l[cur]][i]+maxi[r[cur]][j]);
				mini[cur][i+j+1]=min(mini[cur][i+j+1],mini[l[cur]][i]+mini[r[cur]][j]);
			}
			
		}

	}
	else{
		//cout<<"dasd"<<endl;
		rep(i,min(subtree[l[cur]],poo[typ])+1){
			for(j=0;j<min(subtree[r[cur]],poo[typ])+1 && i+j<=poo[typ];j++){
				
				maxi[cur][i+j]=max(maxi[cur][i+j],maxi[l[cur]][i]+maxi[r[cur]][j]);
				mini[cur][i+j]=min(mini[cur][i+j],mini[l[cur]][i]+mini[r[cur]][j]);
				
			}
			
		}
		rep(i,min(subtree[l[cur]],poo[typ])+1){
			for(j=0;j<min(subtree[r[cur]],poo[typ])+1 && i+j<=poo[typ];j++){
				
				maxi[cur][i+j+1]=max(maxi[cur][i+j+1],maxi[l[cur]][i]-mini[r[cur]][j]);
				mini[cur][i+j+1]=min(mini[cur][i+j+1],mini[l[cur]][i]-maxi[r[cur]][j]);
			}			
		}
	}
	// rep(i,subtree[cur]+1){
	// 	cout<<maxi[cur][i]<<" "<<cur<<" "<<mini[cur][i]<<"   "<<i<<endl;
	// }
	return 0;




}
int main(){
    std::ios::sync_with_stdio(false);
    string s;
    cin>>s;

    cin>>poo[0]>>poo[1];
    if(poo[0]<poo[1])
    	typ=0;
    else
    	typ=1;
    // if(s[0]!='('){
    // 	cout<<s[0]<<endl;
    // }
    int root=0;
    int counter=1,i;

    rep(i,s.length()){

    	if(s[i]=='('){
    		if(!flag[root]){
    			flag[root]=1;
    			l[root]=counter++;
    			par[l[root]]=root;
    			root=l[root];
    		}
    		else{
    			r[root]=counter++;
    			par[r[root]]=root;
    			root=r[root];
    		}
    	}
    	else if(s[i]==')'){
    		root=par[root];
    	}
    	else if(s[i]=='+'){
    		op[root]=1;
    	}
    	else if(s[i]=='-'){
    		op[root]=2;
    	}
    	else if(s[i]=='?'){
    		op[root]=3;
    	}
    	else{
    		if(flag[root]){
    			r[root]=counter++;
    			par[r[root]]=root;
    			dig[r[root]]=1;
    			val[r[root]]=s[i]-'0';
    		}
    		else{
    			l[root]=counter++;
    			par[l[root]]=root;
    			dig[l[root]]=1;
    			val[l[root]]=s[i]-'0';
    			flag[root]=1;
    		}

    		//dig[root]=1;

    	}
    	
    }
    dfs(1);
    cout<<maxi[1][poo[typ]]<<endl;
    return 0;  
    
}