/*input

2


*/
     
#include <bits/stdc++.h>
     
#define pb(x) push_back(x);
#define in(y) insert(y);
#define tt(t) while(t--)
#define itr ::iterator it;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define si set<int>                      
#define msi map<string, int>
#define new cout<<endl
#define ff(n) for(int i=0;i<n;i++)
#define all(v) sort(v.begin(),v.end())
#define boost ios_base::sync_with_stdio(0),cin.tie(0)     

using namespace std ;

int main(){

	boost;
 	int n;
 	cin>>n;
 	n=abs(n);
 	int i=0;
 	for(int a=0;a<1000000;a++){
 		i+=a;
 		if(-i<=n and n<=i){
 			if( (((n-i) % 2) + 2)%2==0) {cout<<a; return 0;}
 		}
 	}
    return 0 ;
 
}