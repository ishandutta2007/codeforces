#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair


int main()
{
    #ifndef ONLINE_JUDGE  
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    #endif
    int ans=0;
    int n;
    cin>>n;
    if(n<4){
        cout<<"NO";
    }
    else if(n==4){
        cout<<"YES"<<endl;
        cout<<"1 * 2 = 2"<<endl;
        cout<<"2 * 3 = 6"<<endl;
        cout<<"6 * 4 = 24"<<endl;
    }
    else if(n==5){
        cout<<"YES"<<endl;
        cout<<"2 - 1 = 1" <<endl;
        cout<<"1 + 3 = 4" <<endl;
        cout<<"4 * 5 = 20"<<endl;
        cout<<"4 + 20 = 24";
    }
    else if(n==6){
        cout<<"YES"<<endl;
        cout<<"2 - 1 = 1" <<endl;
        cout<<"3 - 1 = 2" <<endl;
        cout<<"5 * 6 = 30"<<endl;
        cout<<"2 + 4 = 6"<<endl;
        cout<<"30 - 6 = 24";
    }
    else if(n==7){
        cout<<"YES"<<endl;
        cout<<"2 - 1 = 1" <<endl;
        cout<<"1 + 3 = 4" <<endl;
        cout<<"4 * 5 = 20"<<endl;
        cout<<"4 + 20 = 24"<<endl;
        cout<<"7 - 6 = 1"<<endl;
        cout<<"24 * 1 = 24";
    }
    else if(n>=8){
        cout<<"YES"<<endl;
        cout<<"1 * 2 = 2"<<endl;
        cout<<"2 * 3 = 6"<<endl;
        cout<<"6 * 4 = 24"<<endl;
        cout<<"5 - 6 = -1"<<endl;
        cout<<"7 - 8 = -1"<<endl;
        cout<<"-1 - -1 = 0"<<endl;
        for(int i=9; i<=n; i++){
            cout<<"0 * " << i<< " = 0"<<endl;
        }
        cout<<"24 + 0 = 24"<<endl;
    }
    
}