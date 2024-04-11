//Abhishek Bansal
#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define loop(a,b) for(int i=a;i<b;i++)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define DRT()  int t; cin>>t; while(t--)
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< ii > vii;
int a[100001];
int bin(int x,int lo,int hi){
    if(lo>hi)return lo;
    int m=(lo+hi)/2;
    if(a[m]>2*x){
        if(m==lo||a[m-1]<=2*x)return m;
        else return bin(x,lo,m-1);
    }
    else return bin(x,m+1,hi);
}
int min(int a,int b){
    return a<b?a:b;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n,ans=1000000;
    si(n);
    loop(0,n)si(a[i]);
    sort(a,a+n);
    loop(0,n){
        int m=a[i];
        int j=bin(m,i,n-1);
        ans=min(ans,i+n-j);
    }
    printf("%d\n",ans);
    return 0;
}