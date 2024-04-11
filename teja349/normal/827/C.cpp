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
vector<vi> bit(500);
string s;
int arr[1234],post[1234];

int updatebit(int num,int pos,int val){
	pos++;
	//cout<<"val"<<endl;
	while(pos<bit[num].size()){
		bit[num][pos]+=val;
		pos+=pos&(-pos);
	}

	return 0;
}
int precomp(int cha,int len,int pos){
	//len++;
	
	int j=len+1;
	int i=pos;
	int q=0;
	bit[cha*100+len*10+pos].resize(s.length()/j + 20,0);
	//cout<<i<<" "<<s.length()<<endl;
	while(i<s.length()){
		//cout<<s[i]<<" "<<arr[cha]<<endl;
		if(s[i]==arr[cha]){
			updatebit(cha*100+len*10+pos,q,1);

		}
		q++;
		
		i+=j;
	}
	

	return 0;
	

}
int querybit(int num,int pos){
	int sum=0;
	//cout<<pos<<" "<<bit[num].size()<<" ";
	pos++;

	//cout<<bit[num][pos]<<" sd "<<endl;
	while(pos>0){
		sum+=bit[num][pos];
		pos-=pos&(-pos);
		//cout<<pos<<" "<<bit[num][pos]<<endl;
	}

	//cout<<sum<<endl;
	return sum;
}
int updatestr(int pos,int cha,int val){
	int i,posi;
	//flag=1;
	f(i,1,11){
		posi=pos%i;
		updatebit(cha*100+(i-1)*10+posi,pos/i,val);
	}
}
int main(){
    std::ios::sync_with_stdio(false);
    //string s;
    cin>>s;
    int q;
    cin>>q;
    arr[0]='A';
    arr[1]='G';
    arr[2]='T';
    arr[3]='C';
    post['A']=0;
    post['G']=1;
    post['T']=2;
    post['C']=3;
    int i,j,k;
    rep(i,4){
    	rep(j,10){
    		rep(k,j+1){
    			precomp(i,j,k);
    		}
    	}
    }
    int x,t,l,r;
    char ch;
    //return 0;
    string e;
    while(q--){
    	int t;
    	cin>>t;
    	if(t==1){
    		cin>>x>>ch;
    		x--;
    		updatestr(x,post[s[x]],-1);
    		updatestr(x,post[ch],1);
    		s[x]=ch;
    	}
    	else{
    		cin>>l>>r>>e;
    		l--;
    		r--;
    		int len=e.length();
    		int sumi=0;
    		rep(i,len){
    			//cout<<i<<endl;
    			//return 0;
    			sumi-=querybit(post[e[i]]*100+(len-1)*10+(l+i)%len,(l+i)/len-1);
    			if(r%len>=(l+i)%len){
    				sumi+=querybit(post[e[i]]*100+(len-1)*10+(l+i)%len,r/len);
    				//;cout<<"boo"<<endl;
    			}
    			else{
    				sumi+=querybit(post[e[i]]*100+(len-1)*10+(l+i)%len,r/len-1);
    			}
    			//cout<<sumi<<endl;
    		}
    		//return 0;
    		cout<<sumi<<endl;
    	}
    }
    return 0;

    
}