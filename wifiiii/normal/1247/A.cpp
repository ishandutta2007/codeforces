#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 urng(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=100010;
 
int main()
{
    int a,b;
    cin>>a>>b;
    if(a==b)
    {
        cout<<a<<1<<" "<<b<<2<<endl;
    }
    else if(a+1==b)
    {
        cout<<a<<" "<<b<<endl;
    }
    else if(a==9 && b==1)
    {
        cout<<9<<" "<<10<<endl;
    }
    else cout<<-1<<endl;
}