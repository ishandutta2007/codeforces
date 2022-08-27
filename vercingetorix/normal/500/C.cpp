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
    int n,m;
    int ans = 0;
    cin>>n>>m;
    vi pos(n+1, 0);
    vi book(n+1, 0);
    vi w(n+1);
    for(int i=1; i<=n;i++) cin>>w[i];
    int books = 0;
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        if(pos[x]==0){
            books++;
            pos[x]=books;
            book[books]=x;
        }
        for(int j=pos[x]; j>1; j--){
            book[j]=book[j-1];
            pos[book[j]]=j;
            ans+=w[book[j]];
        }
        pos[x]=1;
        book[1]=x;

    }
    cout<<ans;
    
}