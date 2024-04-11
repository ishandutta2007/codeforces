#include<iostream>
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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 200005
char a[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int zero=0,one=0;
    for(int i=1;i<=n;i++){
        if(a[i]=='('){
            if(zero==one)
            {
                cout<<0;
                zero++;
            }
            else
            {
                cout<<1;
                one++;
            }
        }
        if(a[i]==')'){
            if(zero>one)
            {
                cout<<0;
                zero--;
            }
            else {cout<<1;one--;}
        }
    }
    cout<<endl;
    return 0;
}