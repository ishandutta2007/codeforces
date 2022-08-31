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
int pres[53][53];
int x[53],y[53];
int wantx[53],wanty[53];
struct total{
	int x,y,pos;
};
total haha[123];

int comp(total a,total b){
	if(a.x!=b.x)
		return a.x<b.x;
	if(a.y!=b.y)
		return a.y<b.y;
}
vii vec,vec1;
int move(int a,int b,int c,int d){
	int i,j;
	if(a==c){
		if(b<d){
			f(j,b,d){
				vec.pb(mp(a,j));
				vec1.pb(mp(a,j+1));
				swap(pres[a][j],pres[a][j+1]);
			}
		}
		else{
			fd(j,b,d+1){
				vec.pb(mp(a,j));
				vec1.pb(mp(a,j-1));
				swap(pres[a][j],pres[a][j-1]);
			}
		}
	}
	else{
		if(a<c){
			f(j,a,c){
				vec.pb(mp(j,b));
				vec1.pb(mp(j+1,b));
				swap(pres[j][b],pres[j+1][b]);
			}
		}
		else{
			fd(j,a,c+1){
				vec.pb(mp(j,b));
				vec1.pb(mp(j-1,b));
				swap(pres[j][b],pres[j-1][b]);
			}
		}
	}
	return 0;
}
int printallmoves(){
	cout<<vec.size()<<endl;
	int i;
	rep(i,vec.size()){
		cout<<vec[i].ff+1<<" "<<vec[i].ss+1<<" ";
		cout<<vec1[i].ff+1<<" "<<vec1[i].ss+1<<endl;
	}
	return 0;
}
int printithmove(int i){
	cout<<vec[i].ff+1<<" "<<vec[i].ss+1<<" ";
		cout<<vec1[i].ff+1<<" "<<vec1[i].ss+1<<endl;
}
int dobrute(int n,int m){
	int i,j;
	rep(i,n+2){
		rep(j,n+2){
			pres[i][j]=-1;
		}
	}
	rep(i,m){
		cin>>x[i]>>y[i];
		x[i]--;
		y[i]--;
		pres[x[i]][y[i]]=i;
	}
	rep(i,m){
		cin>>wantx[i]>>wanty[i];
		wantx[i]--;
		wanty[i]--;
		if(pres[wantx[i]][wanty[i]]==i){
			continue;
		}
		if(pres[wantx[i]][wanty[i]]!=-1){
			if(wantx[i]==x[i]){
				move(wantx[i],wanty[i],(wantx[i]^1),wanty[i]);
				x[1]^=1;
			}
			else{
				move(wantx[i],wanty[i],(wantx[i]),(wanty[i]^1));
				y[1]^=1;
			}
		}

		if(pres[wantx[i]][wanty[i]]==-1){
			if(wantx[i]==x[i]){
				move(x[i],y[i],wantx[i],wanty[i]);
			}
			else if(wanty[i]==y[i]){
				move(x[i],y[i],wantx[i],wanty[i]);
			}
			else{
				if(m==1){
					move(x[i],y[i],wantx[i],y[i]);
					move(wantx[i],y[i],wantx[i],wanty[i]);
				}
				else{
					if(x[i]==x[i^1]){
						move(x[i],y[i],wantx[i],y[i]);
						move(wantx[i],y[i],wantx[i],wanty[i]);
					}
					else{
						move(x[i],y[i],x[i],wanty[i]);
						move(x[i],wanty[i],wantx[i],wanty[i]);
					}
				}
			}
		}
		
	}
	printallmoves();

}
int fuck[123][123];
int main(){
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    if(n==1){
    	cout<<0<<endl;
    	return 0;
    }
    if(n==2){
    	dobrute(n,m);
    	return 0;
    }
	int i,j;
    rep(i,n){
    	rep(j,n){
    		pres[i][j]=-1;
    	}
    }
    rep(i,m){
    	cin>>x[i]>>y[i];
    	x[i]--;
    	y[i]--;
    	pres[x[i]][y[i]]=i;
    }
	
    rep(i,m){
    	cin>>wantx[i]>>wanty[i];
		wantx[i]--;
		wanty[i]--;
    	haha[i].x=wantx[i];
    	haha[i].y=wanty[i];
    	haha[i].pos=i;
    }
	
    sort(haha,haha+m,comp);
	int k;
    rep(i,n){
    	rep(j,n){
    		if(pres[i][j]!=-1){
    			k=j-1;
    			while(k>=0 && pres[i][k]==-1){
    				swap(pres[i][k+1],pres[i][k]);
    				vec.pb(mp(i,k+1));
    				vec1.pb(mp(i,k));
    				k--;
    			}

    		}
    	}
    }
	// 
	
	
    int cur=0;
	int ans;
    rep(i,n){
    	if(pres[i][0]!=-1)
    		continue;
		//cout<<i<<endl;	
    	ans=-1;
		fd(j,i-1,0){
    		if(pres[j][1]!=-1){
    			ans=j;
    			break;
    		}
    	}
    	if(ans!=-1){
    		fd(j,n-1,0){
	    		if(pres[ans][j]!=-1)
	    			break;
	    	}
	    	move(ans,j,i,j);
			move(i,j,i,0);
	    	continue;
    	}
		
		ans=-1;
    	f(j,i+1,n){
    		if(pres[j][1]!=-1){
    			ans=j;
    			break;
    		}
    	}
		
    	if(ans==-1)
    		break;
    	fd(j,n-1,0){
    		if(pres[ans][j]!=-1)
    			break;
    	}
		//cout<<ans<<endl;
    	move(ans,j,i,j);
		move(i,j,i,0);
    	continue;

    }
	
	
	
    rep(i,m){
		
    	rep(j,n){
    		if(pres[j][0]==haha[i].pos){
    			break;
    		}
    	}
		//cout<<j<<" "<<haha[i].pos<<endl;
    	if(j==i)
    		continue;
		int fig=0;
		
		if(pres[i][0]!=-1){
			fig=1;
			move(i,0,i,2);
    		
		}	
    	move(j,0,j,1);
    	move(j,1,i,1);
		move(i,1,i,0);
    	if(fig==1){
			move(i,2,j,2);
			move(j,2,j,0);
		}
    }
	
	
    i=0;
    j=0;
	
    while(i<m){
    	j=i+1;
    	int cnt=1;
    	while(j<m && haha[i].x==haha[j].x){
    		move(j,0,j,cnt);
    		move(j,cnt,i,cnt);
    		cnt++;
    		j++;
    	}
    	i=j;
    }
	
	//return 0;
	
	int dd;
	int val,wow;
    rep(dd,n){
		
		wow=0;	
    	rep(i,n){
	    	if(pres[i][0]==-1)
	    		continue;
				
	    	val=wantx[pres[i][0]];
			if(val==i){
	    		continue;
	    	}
			
			//cout<<i<<endl;
			int notpos=0;
	    	if(val<i){
	    		fd(j,i-1,val){
	    			if(pres[j][0]!=-1){
	    				notpos=1;
	    				break;
	    			}
	    		}
	    	}
	    	else{
	    		f(j,i+1,val+1){
	    			if(pres[j][0]!=-1){
	    				notpos=1;
	    				break;
	    			}
	    		}
	    	}
	    	

			
	    	if(notpos!=1){
	    		//cout<<i<<endl;
				wow=1;
	    		break;
	    	}

	    }
		
		
		//cout<<wow<<" "<<i<<" "<<val<<endl;
	    if(wow==1){
	    	//cout<<val<<" "<<i<<" "<<wow<<endl;
		
			rep(j,n){
	    		if(pres[i][j]!=-1){
	    			move(i,j,val,j);
	    		}
	    	}
		}
	    if(wow==0)
	    	break;
    }


	//return 0;
	
    rep(i,n){
    	fd(j,n-1,0){
    		if(pres[i][j]!=-1){
    			move(i,j,i,wanty[pres[i][j]]);
    		}
    	}
		

    }
	// rep(j, n)
	// {
	// 	rep(i, n)
	// 	{
	// 		cout << pres[i][n - j - 1] << " ";
	// 	}
	// 	cout << endl;
	// }
	// rep(i, n)
	// {
	// 	rep(j, n)
	// 	{
	// 		pres[i][j] = -1;
	// 		fuck[i][j] = -1;
	// 	}
	// }
	// rep(i, m)
	// {
	// 	pres[x[i]][y[i]] = i;
	// 	fuck[wantx[i]][wanty[i]] = i;
	// }
	// rep(i, vec.size())
	// {
	// 	//cout << i << endl;
	// 	//printithmove(i);

	// 	assert(vec[i].ff >= 0 && vec[i].ff < n);
	// 	assert(vec[i].ss >= 0 && vec[i].ss < n);
	// 	assert(vec1[i].ff >= 0 && vec1[i].ff < n);
	// 	assert(vec1[i].ss >= 0 && vec1[i].ss < n);
	// 	assert(abs(vec[i].ff - vec1[i].ff) + abs(vec[i].ss - vec1[i].ss) == 1);
	// 	assert(pres[vec[i].ff][vec[i].ss] != -1);
	// 	assert(pres[vec1[i].ff][vec1[i].ss] == -1);
	// 	swap(pres[vec[i].ff][vec[i].ss], pres[vec1[i].ff][vec1[i].ss]);
	// }
	// rep(i, n)
	// {
	// 	rep(j, n)
	// 	{
	// 		assert(pres[i][j] == fuck[i][j]);
	// 	}
	// }
	// cout << "GOOD";
	// return 0;

	// rep(j,n){
	// 	rep(i,n){
	// 		cout<<pres[i][n-j-1]<<" ";
	// 	}
	// 	cout<<endl;
	// }
    printallmoves();
    


    return 0;  
    
}