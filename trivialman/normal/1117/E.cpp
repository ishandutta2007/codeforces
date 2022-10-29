#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define repr(i,a,b) for(int i=(a);i>=(b);--i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL MOD = 1e9+7;
const int N = 20010;

int n, id[N];
//vector<int> a[26],b[676],c;
string s,s1,s2,s3,t,t1,t2,t3;

int main(){
	#ifndef ONLINE_JUDGE
	//freopen("test.in","r",stdin);
	#endif
    cin>>t;
    n = t.size();
    s1.resize(N);s2.resize(N);s3.resize(N);
    rep(i,0,26*26*26-1){
    	s1[i] = i/676+97;
    	s2[i] = i%676/26+97;
    	s3[i] = i%26+97;
	}
    //cout<<s1.substr(0,50)<<endl<<s2.substr(0,50)<<endl<<s3.substr(0,50)<<endl;
    cout<<"? "<<s1.substr(0,n)<<endl<<flush;
    cin>>t1;
    cout<<"? "<<s2.substr(0,n)<<endl<<flush;
    cin>>t2;
	cout<<"? "<<s3.substr(0,n)<<endl<<flush;
    cin>>t3;
    rep(i,0,n-1){
    	id[(t1[i]-97)*676 + (t2[i]-97)*26 + (t3[i]-97)] = i;
	}
	cout<<"! ";
	rep(i,0,n-1)cout<<t[id[i]];
	cout<<endl;
}