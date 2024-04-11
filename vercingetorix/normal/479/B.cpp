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
    int n,k;
    cin>>n>>k;
    vector<pair<int, int> > a;
    int x;
    vector<pair<int,int> > op;
    vector<pair<int,int> > op_n;
    for(int i=1;i<=n;i++){
        cin>>x;
        a.pb(mp(x,i));
    }
    sort(all(a));
    int d = - a[0].first + a[n-1].first;
    int curk=0;
    int kans=0;
    while(curk<k){
        curk++;
        a[0].first++;
        a[n-1].first--;
        op_n.pb(mp(a[n-1].second, a[0].second));
        sort(all(a));
        /*cout<<endl<<endl<<curk<<endl;
        for(int i=0; i<n; i++) cout<<a[i].first<<" "<<a[i].second<<endl;
        cout<<endl<<endl;*/
        if((- a[0].first + a[n-1].first) < d){
            for(int i=0; i<op_n.size(); i++) op.pb(op_n[i]);
            op_n.clear();
            kans=curk;
            d = - a[0].first + a[n-1].first;
        }
    }
    cout<<d<<" "<<kans<<endl;
    for(int i=0; i<kans; i++) cout<<op[i].first<<" "<<op[i].second<<endl;
    //cout<<ans;
    
}