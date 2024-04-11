#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Crunching Numbers Just for You
//Crunching Numbers Just for You

//Crunching Numbers Just for You
typedef std::vector<int> vi;
#define forn(i, a, b) for(int i = a; i < b; i++)
int main()
{
    int n;
    cin>>n;
    
    vi a(n);
    forn(i,0,n) cin>>a[i];
    sort(a.begin(), a.end());
    vi b=a;
    forn(i,0,120000000) {
        int x=rand()%n;
        b[x] += 1;
    }
    // cout<<"Crunching Numbers Just for You!\n";
    //    forn(i,0,1000) cout<<"\n";
        forn(i,0,n) cout<<a[i]<<' ';
    
    forn(i,0,-n) {
        string s= to_string(a[i]);
        while(s.size() < 3) s="0"+s;
        cout<<s;
        if(i!=n-1) cout<<' ';
    }
    
    
    //    cout<<"Crunching Numbers Just for You\n";
    
    
}