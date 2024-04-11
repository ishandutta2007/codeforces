#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<unordered_map>
#include<time.h>
#include<cstdlib>
#include <chrono>
#include <random>
typedef long long ll;
typedef unsigned long long ull;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma comment(linker, "/STACK:36777216")  //hdu 
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define eqs 1e-8
#define lb(x) (x&(-x))
#define ch(a) (int(a-'a')+1)
#define rep(i, a, b) for(int i=a;i<=b;i++)
#define mkp(a, b) make_pair(a,b)
#define re register
#define umap(a) (a).reserve(1024);(a).max_load_factor(0.25);
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pii,int> piii;
//const double pi=acos(-1);
const int maxn=500005;
//const ll Mod=1000000007;
const ll Mod=998244353;


string s;

int main()
{
    sync;
    int t;
    cin>>t;
    while(t--)
    {
        int L,R;
        int n;
        cin>>n;
        cin>>s;
        int mid=n/2;
        int A,B;
        if(n%2==0||s[mid]=='1')
        {
            int pre=0,lv=0;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='0')
                {
                    if(s[n-i-1]=='1')
                        pre++;
                    else
                        lv++;
                }
            }
            if(lv)
            {
                L=2;
                R=0;
            }
            else
            {
                L=0;
                R=0;
            }
            
            A=0;B=pre;
            A+=L;
            B+=R;
            if(A<B)
            {
                cout<<"ALICE"<<endl;
                continue;
            }
            
            if(pre>0&&lv>0)
            {
                A=1;B=pre-1;
                A+=R;
                B+=L;
                if(A<B)
                {
                    cout<<"ALICE"<<endl;
                    continue;
                }
            }
            
            A=0;B=pre;
            A+=L;
            B+=R;
            if(A==B)
            {
                cout<<"DRAW"<<endl;
                continue;
            }
            
            if(pre>0&&lv>0)
            {
                A=1;B=pre-1;
                A+=R;
                B+=L;
                if(A==B)
                {
                    cout<<"DRAW"<<endl;
                    continue;
                }
            }
            
            cout<<"BOB"<<endl;
        }
        else
        {
            int pre=0,lv=0;
            for(int i=0;i<n;i++)
            {
                if(i!=mid&&s[i]=='0')
                {
                    if(s[n-i-1]=='1')
                        pre++;
                    else
                        lv++;
                }
            }
            
            if(lv)
            {
                L=2;
                R=0;
            }
            else
            {
                L=0;
                R=0;
            }
            
            
            A=1;B=pre;
            A+=R;
            B+=L;
            if(A<B)
            {
                cout<<"ALICE"<<endl;
                continue;
            }
//            if(pre>0)
//            {
//                A=0;B=pre+1;
//                A+=L;
//                B+=R;
//                if(A<B)
//                {
//                    cout<<"ALICE"<<endl;
//                    continue;
//                }
//            }
            
            
            A=1;B=pre;
            A+=R;
            B+=L;
            if(A==B)
            {
                cout<<"DRAW"<<endl;
                continue;
            }
//            if(pre>0)
//            {
//                A=0;B=pre+1;
//                A+=L;
//                B+=R;
//                if(A==B)
//                {
//                    cout<<"DRAW"<<endl;
//                    continue;
//                }
//            }
            
            cout<<"BOB"<<endl;
        }
    }
    
    return 0;
}