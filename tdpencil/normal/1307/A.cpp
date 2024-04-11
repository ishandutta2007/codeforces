#include<bits/stdc++.h>
using namespace std;
 
#define lli            long long int  
#define ll             long long 
#define vi             vector<int>
#define mod            1000000007
#define MAX            INT_MIN
#define MIN            INT_MAX
#define ff             first
#define ss             second
#define pb             push_back
#define bs             binary_search    // binary_search(a,a+n,x);
#define mp             make_pair
#define pii            pair<int,int>
#define pqb            priority_queue<int>
#define lower(x)         transform(x.begin(), x.end(), x.begin(), ::tolower);           
#define upper(x)          transform(x.begin(), x.end(), x.begin(), ::toupper);
#define lb             lower_bound      // lower_bound(a,a+n,x) - a; => For Index
#define up             upper_bound      // upper_bound(a,a+n,x) - a; => For Index       
#define floop(x,n)       for(int i=x;i<n;i++)
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define ps(x,y)        fixed<<setprecision(y)<<x         
#define FIO            ios_base::sync_with_stdio(false); cin.tie(NULL);
                  
void c_p_c()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif   
}    

void solution()
{
    int t;
    cin>>t;

    while(t--)
    {
        int N,D;
        cin>>N>>D;
        int a[N];
        for (int i=1;i<=N;i++)
          cin>>a[i];
        while (D--){ //loop over D days
          for (int i=2;i<=N;i++)
        if (a[i]>0){ //move closest haybale over
          a[i]--;
          a[i-1]++;
          break;
        }
        }
        cout<<a[1]<<endl;
    }
}

int32_t main()
{
    c_p_c();
    FIO;
 
    // int t;
    // cin>>t;
 
    // while(t--)
    // {
         solution();
    //}
 
    return 0;
}