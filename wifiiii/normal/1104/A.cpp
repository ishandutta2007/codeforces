#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define scsz(s,a,b) int jjj=1;for(int iii=a;iii<=b;++iii) {cout<<s[iii];if(jjj++ % 10) cout<<"\t";else cout<<"\n";}cout<<endl;
const ll mod = 1e9+7;

int main()
{
    int n;
    cin>>n;
    cout<<n<<endl;
    for(int i=1;i<=n;++i) {if(i!=1) cout<<" ";cout<<1;}
    cout<<endl;
}